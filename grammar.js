module.exports = grammar({
  name: "gt",

  extras: $ => [],

  rules: {
    source_file: $ => repeat($._line),

    _line: $ => choice(
      $.blank_line,
      $.node,
      $.property,
      $.comment,
    ),

    blank_line: $ => /\n/,

    node: $ => token(seq(/[^\s\n][^\n]*/, /\n/)),

    property: $ => seq(
      /[ \t]+/,
      $.key,
      ":",
      / /,
      $.value,
      /\n/
    ),

    key: $ => /[^:\n]+/,
    value: $ => /[^\n]+/,

    comment: $ => token(prec(-1, seq(/[ \t]+[^\n]*/, /\n/))),
  }
});
