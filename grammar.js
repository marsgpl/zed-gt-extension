// Each line is matched atomically as a single token. The lexer commits to a
// line type only if the entire line matches the strict regex; otherwise the
// line falls through to `error_line`. This prevents tree-sitter's automatic
// error recovery from masking deviations (e.g. skipping a stray indent space
// or splitting a malformed name into a valid prefix + ERROR suffix).

const NAME = "[a-zA-Z0-9_\\-]+( [a-zA-Z0-9_\\-]+)*";

module.exports = grammar({
  name: "gt",

  extras: $ => [],

  rules: {
    source_file: $ => repeat($._line),

    _line: $ => choice(
      $.blank_line,
      $.node_line,
      $.edge_line,
      $.error_line,
    ),

    blank_line: $ => token(/\n/),

    node_line: $ => token(new RegExp(`${NAME}\\n`)),

    edge_line: $ => token(new RegExp(`    ${NAME}: ${NAME}\\n`)),

    error_line: $ => token(prec(-1, /[^\n]+\n?/)),
  },
});
