// Strategy:
//
// `src/scanner.c` validates each line atomically before the grammar sees it.
// For a valid node line or edge line it emits a zero-width marker token; the
// grammar then parses the line structurally so each sub-part (name, `:`,
// target) gets its own highlight capture. For malformed content it emits a
// single atomic `error_line` token covering the bad content (no trailing \n).
//
// Line terminators are emitted as separate tokens so blank-line errors can
// span multiple bytes (and therefore render visibly):
//   `_eol`         — exactly one `\n` between valid lines
//   `blank_error`  — two or more consecutive `\n` (a blank line region)
//
// `source_file` puts `edge_line` only after the first `node_line`, so an
// indented first line falls through to `error_line` in the pre-line phase.

module.exports = grammar({
  name: "gt",

  extras: $ => [],

  externals: $ => [
    $._node_line_marker,
    $._edge_line_marker,
    $.error_line,
    $._eol,
    $.blank_error,
  ],

  rules: {
    source_file: $ => seq(
      repeat($._pre_item),
      optional(seq(
        $.node_line,
        repeat($._main_thing),
      )),
    ),

    _pre_item: $ => choice(
      seq($.error_line, $._sep),
      $._sep,
    ),

    _main_thing: $ => choice(
      seq($._sep, choice($.node_line, $.edge_line, $.error_line)),
      $._sep,
    ),

    _sep: $ => choice($._eol, $.blank_error),

    node_line: $ => seq(
      $._node_line_marker,
      $.node_name,
    ),

    edge_line: $ => seq(
      $._edge_line_marker,
      "    ",
      $.edge_name,
      ":",
      " ",
      $.target_name,
    ),

    node_name: $ => /[a-zA-Z0-9_\-]+( [a-zA-Z0-9_\-]+)*/,
    edge_name: $ => /[a-zA-Z0-9_\-]+( [a-zA-Z0-9_\-]+)*/,
    target_name: $ => /[a-zA-Z0-9_\-]+( [a-zA-Z0-9_\-]+)*/,
  },
});
