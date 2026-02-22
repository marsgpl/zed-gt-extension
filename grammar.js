module.exports = grammar({
  name: "gt",

  extras: $ => [],

  rules: {
    source_file: $ => repeat(choice(
      $.blank_line,
      $.comment,
      $.valid_node,
      $.valid_property,
      $.invalid_line
    )),

    blank_line: $ => /\n/,

    comment: $ => token(seq("#", /[^\n]*/, "\n")),

    // Valid node: column 0, valid chars only
    valid_node: $ => token(seq(/[a-zA-Z0-9_\- ]+/, "\n")),

    // Valid property: exactly 4 spaces, valid key, colon, space, valid value
    valid_property: $ => seq(
      "    ",
      $.key,
      token.immediate(":"),
      " ",
      $.value,
      "\n"
    ),

    key: $ => /[a-zA-Z0-9_\- ]+/,
    value: $ => /[a-zA-Z0-9_\- ]+/,

    // Any other non-empty line is invalid
    invalid_line: $ => token(prec(-1, seq(/[^\n]+/, "\n"))),
  }
});
