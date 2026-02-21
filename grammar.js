module.exports = grammar({
  name: "gt",

  rules: {
    source_file: $ => repeat(choice($.comment, $.node, $.property, $.error_node, $.blank_line)),

    comment: $ => seq("#", /[^\n]*/, "\n"),

    node: $ => seq(
      /[^\s:][^:\n]*/,
      "\n"
    ),

    error_node: $ => seq(
      /[^\s:][^:\n]*:[^\n]*/,
      "\n"
    ),

    property: $ => seq(
      "    ",
      field("key", $.key),
      ":",
      optional(seq(" ", field("value", $.value))),
      "\n"
    ),

    key: $ => /[^:\n]+/,

    value: $ => /[^\n]+/,

    blank_line: $ => /\n/
  }
});
