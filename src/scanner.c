#include "tree_sitter/parser.h"
#include <stdbool.h>
#include <stdint.h>

enum TokenType {
  NODE_LINE_MARKER,
  EDGE_LINE_MARKER,
  ERROR_LINE,
  BLANK_LINE,
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

  // Mark token start — zero-width by default. mark_end records the
  // token's end position; subsequent advance() calls during this scan
  // are lookahead only and don't extend the token. After scan returns,
  // the lexer resumes from the marked position, so we can read the
  // whole line for validation and still emit a zero-width marker.
  lexer->mark_end(lexer);

  int32_t buf[MAX_LINE];
  int len = 0;
  while (lexer->lookahead != '\n' && lexer->lookahead != 0 && len < MAX_LINE - 1) {
    buf[len++] = lexer->lookahead;
    lexer->advance(lexer, false);
  }
  bool has_nl = (lexer->lookahead == '\n');
  if (has_nl) {
    lexer->advance(lexer, false);
  }

  // Blank line: just \n.
  if (len == 0) {
    if (!has_nl) return false; // EOF
    if (!valid_symbols[BLANK_LINE]) return false;
    lexer->result_symbol = BLANK_LINE;
    lexer->mark_end(lexer); // include the \n
    return true;
  }

  // No trailing newline at EOF: the line is malformed by spec.
  if (!has_nl) {
    if (!valid_symbols[ERROR_LINE]) return false;
    lexer->result_symbol = ERROR_LINE;
    lexer->mark_end(lexer);
    return true;
  }

  // Valid node line: whole line content is a name.
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

  // Anything else: whole line is one atomic error token.
  if (valid_symbols[ERROR_LINE]) {
    lexer->result_symbol = ERROR_LINE;
    lexer->mark_end(lexer); // covers the whole line including \n
    return true;
  }

  return false;
}
