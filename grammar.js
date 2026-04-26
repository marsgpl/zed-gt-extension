// Strategy:
//
// `src/scanner.c` validates each line atomically before the grammar sees it.
// For a valid node line or edge line it emits a zero-width marker token
// (`_node_line_marker` / `_edge_line_marker`); the grammar then parses the
// line structurally so each sub-part (name, `:`, target) gets its own
// highlight capture. For anything malformed it emits a single atomic
// `error_line` token covering the whole line, so the entire bad line is
// highlighted as an error — tree-sitter's automatic error recovery never
// gets a chance to commit to a partial parse and leak through.
//
// `source_file` puts `edge_line` only after the first `node_line`, so
// `_edge_line_marker` is not in the scanner's `valid_symbols` set at the
// top of the file — an indented first line falls through to `error_line`.

module.exports = grammar({
  name: "gt",

  extras: $ => [],

  externals: $ => [
    $._node_line_marker,
    $._edge_line_marker,
    $.error_line,
  ],

  rules: {
    source_file: $ => seq(
      repeat($.error_line),
      optional(seq($.node_line, repeat($._line))),
    ),

    _line: $ => choice(
      $.node_line,
      $.edge_line,
      $.error_line,
    ),

    node_line: $ => seq(
      $._node_line_marker,
      $.node_name,
      /\n/,
    ),

    edge_line: $ => seq(
      $._edge_line_marker,
      "    ",
      $.edge_name,
      ":",
      " ",
      $.target_name,
      /\n/,
    ),

    node_name: $ => /[a-zA-Z0-9_\-]+( [a-zA-Z0-9_\-]+)*/,
    edge_name: $ => /[a-zA-Z0-9_\-]+( [a-zA-Z0-9_\-]+)*/,
    target_name: $ => /[a-zA-Z0-9_\-]+( [a-zA-Z0-9_\-]+)*/,
  },
});
