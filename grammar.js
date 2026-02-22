module.exports = grammar({
  name: "gt",

  extras: $ => [],

  rules: {
    source_file: $ => repeat($._line),

    _line: $ => choice(
      $.blank_line,
      $.node_line,
      $.property,
      $.comment,
    ),

    blank_line: $ => /\n/,

    node_line: $ => seq($.node, /\n/),
    node: $ => /[^\s\n][^\n]*/,

    property: $ => seq(
      "    ",
      $.key,
      ":",
      " ",
      $.value,
      /\n/
    ),

    key: $ => /[^:\n]+/,
    value: $ => /[^\n]+/,

    comment: $ => token(prec(-1, seq(/[ \t]+[^\n]*/, /\n/))),
  }
});
