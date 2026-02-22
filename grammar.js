module.exports = grammar({
  name: "gt",

  rules: {
    source_file: $ => repeat(choice(
      $.comment,
      $.node,
      $.property,
      $.error_node,
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

    // Any line with exactly 4 spaces
    property: $ => seq(
      "    ",
      choice(
        $.property_valid,
        $.property_invalid
      ),
      "\n"
    ),

    // Valid property content: key: optional value
    property_valid: $ => prec(1, seq(
      field("key", $.valid_key),
      ":",
      optional(seq(" ", field("value", $.valid_value)))
    )),

    // Invalid property content (no colon, invalid chars, etc.)
    property_invalid: $ => /[^\n]*/,

    valid_key: $ => /[a-zA-Z0-9_\- ]+/,
    valid_value: $ => /[a-zA-Z0-9_\- ]+/,

    // Wrong indentation (not 0 or 4 spaces)
    wrong_indent: $ => seq(
      / {1,3}| {5,}/,
      /[^\n]*/,
      "\n"
    ),

    blank_line: $ => /\n/
  }
});
