module.exports = grammar({
  name: "gt",

  extras: $ => [],

  rules: {
    source_file: $ => repeat($._line),

    _line: $ => choice(
      $.blank_line,
      $.node_line,
      $.property_line,
      $.comment_line,
      $.invalid_line,
    ),

    blank_line: $ => /\n/,

    // Line starting at column 0 (node name)
    node_line: $ => seq($.node, /\n/),
    node: $ => /[^\s\n][^\n]*/,

    // Indented line with colon (property)
    property_line: $ => seq(
      /[ \t]+/,
      $.key,
      ":",
      / */,
      optional($.value),
      /\n/
    ),
    key: $ => /[^:\n]+/,
    value: $ => /[^ \n][^\n]*/,

    // Indented line without colon (comment)
    comment_line: $ => seq($.comment_content, /\n/),
    comment_content: $ => /[ \t]+[^:\n]*/,

    // Catch-all for unmatched lines
    invalid_line: $ => token(prec(-1, seq(/[^\n]+/, /\n/))),
  }
});
