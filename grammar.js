// Grammar strategy:
//
// `node_line` and `edge_line` are structural (not atomic) so each sub-part
// (`node_name`, `edge_name`, `:`, `target_name`) is a separate tree-sitter
// node and gets its own highlight capture.
//
// To prevent tree-sitter's automatic error recovery from masking deviations
// (e.g. a stray space in the indent or a missing space after `:`), the
// `conflicts` declaration combined with `prec.dynamic` enables GLR parsing:
// for any line that could be either a valid structural line or an
// `error_line`, both branches are explored in parallel. If the structural
// branch fails partway, it dies and `error_line` wins for the whole line.
//
// `source_file` enforces that the file cannot start with an `edge_line`:
// before the first `node_line`, only `blank_line` and `error_line` are valid
// alternatives — so an indented first line falls through to `error_line`.

module.exports = grammar({
  name: "gt",

  extras: $ => [],

  conflicts: $ => [
    [$.node_line, $.error_line],
    [$.edge_line, $.error_line],
  ],

  rules: {
    source_file: $ => seq(
      repeat(choice($.blank_line, $.error_line)),
      optional(seq($.node_line, repeat($._line))),
    ),

    _line: $ => choice(
      $.blank_line,
      $.node_line,
      $.edge_line,
      $.error_line,
    ),

    blank_line: $ => /\n/,

    node_line: $ => prec.dynamic(2, seq(
      $.node_name,
      /\n/,
    )),

    edge_line: $ => prec.dynamic(2, seq(
      "    ",
      $.edge_name,
      ":",
      " ",
      $.target_name,
      /\n/,
    )),

    node_name: $ => /[a-zA-Z0-9_\-]+( [a-zA-Z0-9_\-]+)*/,
    edge_name: $ => /[a-zA-Z0-9_\-]+( [a-zA-Z0-9_\-]+)*/,
    target_name: $ => /[a-zA-Z0-9_\-]+( [a-zA-Z0-9_\-]+)*/,

    error_line: $ => token(prec(-1, /[^\n]+\n?/)),
  },
});
