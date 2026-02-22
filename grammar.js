module.exports = grammar({
  name: "gt",

  extras: $ => [],

  rules: {
    source_file: $ => repeat($._line),

    _line: $ => choice(
      $.blank_line,
      $.valid_node,
      $.invalid_node,
      $.property_line,
      $.comment_line,
    ),

    blank_line: $ => /\n/,

    // Valid node: unindented, valid chars only
    valid_node: $ => token(prec(1, seq(/[a-zA-Z0-9_\- ]+/, /\n/))),

    // Invalid node: unindented, contains invalid chars
    invalid_node: $ => token(seq(/[^\s\n][^\n]*/, /\n/)),

    // Indented line with colon (property)
    property_line: $ => seq(
      /[ \t]+/,
      choice($.valid_key, $.invalid_key),
      ":",
      optional(seq(/ +/, choice($.valid_value, $.invalid_value))),
      /\n/
    ),

    valid_key: $ => token(prec(1, /[a-zA-Z0-9_\- ]+/)),
    invalid_key: $ => /[^:\n]+/,

    valid_value: $ => token(prec(1, /[a-zA-Z0-9_\- ]+/)),
    invalid_value: $ => /[^\n]+/,

    // Indented line without colon (comment)
    comment_line: $ => token(seq(/[ \t]+[^:\n]*/, /\n/)),
  }
});
