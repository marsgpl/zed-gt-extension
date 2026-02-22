module.exports = grammar({
  name: "gt",

  rules: {
    source_file: $ => repeat(choice(
      $.comment,
      $.node,
      $.property,
      $.error_node,
      $.invalid_indent,
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

    // Valid property: 4 spaces, key, colon, optional value
    property: $ => seq(
      "    ",
      field("key", $.key),
      ":",
      optional(seq(" ", field("value", $.value))),
      "\n"
    ),

    key: $ => /[^:\n]+/,

    value: $ => /[^\n]+/,

    // Invalid indented line (doesn't match property format)
    invalid_indent: $ => seq(
      / +[^\n]*/,
      "\n"
    ),

    blank_line: $ => /\n/
  }
});
