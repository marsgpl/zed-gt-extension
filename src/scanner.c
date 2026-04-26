#include "tree_sitter/parser.h"
#include <stdbool.h>
#include <stdint.h>

enum TokenType {
  NODE_LINE_MARKER,
  EDGE_LINE_MARKER,
  ERROR_LINE,
  EOL,
  BLANK_ERROR,
};

void *tree_sitter_gt_external_scanner_create(void) { return NULL; }
void tree_sitter_gt_external_scanner_destroy(void *p) { (void)p; }
unsigned tree_sitter_gt_external_scanner_serialize(void *p, char *b) {
  (void)p; (void)b; return 0;
}
void tree_sitter_gt_external_scanner_deserialize(void *p, const char *b, unsigned l) {
  (void)p; (void)b; (void)l;
}

static bool is_name_char(int32_t c) {
  return (c >= 'a' && c <= 'z')
      || (c >= 'A' && c <= 'Z')
      || (c >= '0' && c <= '9')
      || c == '_' || c == '-';
}

#define MAX_LINE 4096

// Validate buf[start..end) as a name:
//   [a-zA-Z0-9_-]+( [a-zA-Z0-9_-]+)*
// No leading/trailing space, no consecutive spaces.
static bool is_valid_name(const int32_t *buf, int start, int end) {
  if (start >= end) return false;
  if (!is_name_char(buf[start])) return false;
  if (!is_name_char(buf[end - 1])) return false;
  for (int i = start + 1; i < end - 1; i++) {
    if (is_name_char(buf[i])) continue;
    if (buf[i] == ' ' && is_name_char(buf[i - 1]) && is_name_char(buf[i + 1])) continue;
    return false;
  }
  return true;
}

bool tree_sitter_gt_external_scanner_scan(
  void *payload, TSLexer *lexer, const bool *valid_symbols
) {
  (void)payload;

  // Default token to zero-width at the start position. Subsequent
  // advance() calls are lookahead; mark_end can be called again later
  // to extend the token.
  lexer->mark_end(lexer);

  if (lexer->lookahead == 0) {
    return false; // EOF
  }

  // Separator case: lookahead is \n. We're between lines (or before any).
  if (lexer->lookahead == '\n') {
    lexer->advance(lexer, false);

    if (lexer->lookahead == '\n') {
      // Two or more consecutive \n: blank-line region.
      while (lexer->lookahead == '\n') {
        lexer->advance(lexer, false);
      }
      // Zed doesn't render syntax-highlight backgrounds on byte ranges
      // that contain only \n characters, so absorb one additional
      // non-\n byte (if present) to give the highlight something
      // visible to attach to. The next line's first character will
      // appear in the error color rather than its normal color, but
      // that's the price of making blank-line errors visible.
      if (lexer->lookahead != 0 && lexer->lookahead != '\n') {
        lexer->advance(lexer, false);
      }
      if (!valid_symbols[BLANK_ERROR]) return false;
      lexer->result_symbol = BLANK_ERROR;
      lexer->mark_end(lexer);
      return true;
    }

    // Single \n: ordinary line terminator.
    if (!valid_symbols[EOL]) return false;
    lexer->result_symbol = EOL;
    lexer->mark_end(lexer);
    return true;
  }

  // Content case: read the line into a buffer for shape validation.
  int32_t buf[MAX_LINE];
  int len = 0;
  while (lexer->lookahead != '\n' && lexer->lookahead != 0 && len < MAX_LINE - 1) {
    buf[len++] = lexer->lookahead;
    lexer->advance(lexer, false);
  }

  // Valid node line: whole line is a name.
  if (valid_symbols[NODE_LINE_MARKER] && is_valid_name(buf, 0, len)) {
    lexer->result_symbol = NODE_LINE_MARKER;
    // Zero-width: do not extend mark_end; grammar parses the line.
    return true;
  }

  // Valid edge line: "    name: name" — exactly 4 spaces, ": " separator,
  // names on each side, no leading/trailing/double spaces.
  if (valid_symbols[EDGE_LINE_MARKER] && len >= 8
      && buf[0] == ' ' && buf[1] == ' ' && buf[2] == ' ' && buf[3] == ' ') {
    int sep = -1;
    for (int i = 4; i < len - 1; i++) {
      if (buf[i] == ':' && buf[i + 1] == ' ') {
        sep = i;
        break;
      }
    }
    if (sep > 4
        && is_valid_name(buf, 4, sep)
        && is_valid_name(buf, sep + 2, len)) {
      lexer->result_symbol = EDGE_LINE_MARKER;
      return true;
    }
  }

  // Anything else: malformed content — atomic error_line covering the
  // content only (no \n; the next scan call will emit EOL/BLANK_ERROR).
  if (valid_symbols[ERROR_LINE]) {
    lexer->result_symbol = ERROR_LINE;
    lexer->mark_end(lexer);
    return true;
  }

  return false;
}
