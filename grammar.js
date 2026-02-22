module.exports = grammar({
  name: "gt",

  rules: {
    source_file: $ => repeat(choice(
      $.comment,
      $.node,
      $.property,
      $.error_node,
      $.invalid_property,
      $.wrong_indent,
      $.blank_line
    )),

    comment: $ => seq("#", /[^\n]*/, "\n"),

    // Valid node name: only alphanumeric, underscore, hyphen, space
    node: $ => seq(
      /[a-zA-Z0-9_\- ]+/,
      "\n"
    ),

    // Invalid unindented line (has colon or invalid chars)
    error_node: $ => seq(
      /[^\s\n][^\n]*/,
      "\n"
    ),

    // Valid property: exactly 4 spaces, key, colon, optional value
    property: $ => prec(1, seq(
      "    ",
      field("key", $.key),
      ":",
      optional(seq(" ", field("value", $.value))),
      "\n"
    )),

    key: $ => choice($.valid_key, $.invalid_key),
    valid_key: $ => prec(1, /[a-zA-Z0-9_\- ]+/),
    invalid_key: $ => /[^:\n]+/,

    value: $ => choice($.valid_value, $.invalid_value),
    valid_value: $ => prec(1, /[a-zA-Z0-9_\- ]+/),
    invalid_value: $ => /[^\n]+/,

    // 4 spaces but wrong format (no colon, etc.)
    invalid_property: $ => seq(
      "    ",
      /[^\n]*/,
      "\n"
    ),

    // Wrong indentation (not 0 or 4 spaces)
    wrong_indent: $ => seq(
      / {1,3}| {5,}/,
      /[^\n]*/,
      "\n"
    ),

    blank_line: $ => /\n/
  }
});
