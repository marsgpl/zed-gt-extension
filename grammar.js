module.exports = grammar({
  name: "gt",

  extras: $ => [],

  rules: {
    source_file: $ => repeat($._line),

    _line: $ => choice(
      $._blank_line,
      $.node_line,
      $.edge_line,
      $.error_line,
    ),

    _blank_line: $ => /\n/,

    node_line: $ => seq(
      $.node_name,
      /\n/,
    ),

    edge_line: $ => seq(
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

    error_line: $ => token(prec(-1, /[^\n]+\n?/)),
  },
});
