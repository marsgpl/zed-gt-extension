# about

this is a zed editor extension to highlight syntax for custom text file "gt". zed must build it automatically: no source code generation or compilation is needed in this repo.

## example

```gt
bank
    is: institution
    is: company
    is: building
bank
    is: landform
    is: shore
    adjacent to: water
apple
    is: fruit
```

## how should it highlight syntax

- if line does not start with space: it is either a valid node name or invalid. regexp of the valid node name: /[a-zA-Z0-9_- ]+/. valid node name token type: @keyword. invalid: @comment.
- if line starts with space (indented): it should be a node relation description (graph edge). format: "    rel node name: node name\n". valid line: relation node name keyword type is: @property. invalid line should be @comment.

## available tokens

@attribute, @boolean, @comment, @comment.doc, @constant, @constant.builtin,
@constructor, @embedded, @emphasis, @emphasis.strong, @enum, @function, @hint,
@keyword, @label, @link_text, @link_uri, @number, @operator, @predictive,
@preproc, @primary, @property, @punctuation, @punctuation.bracket,
@punctuation.delimiter, @punctuation.list_marker, @punctuation.special, @string,
@string.escape, @string.regex, @string.special, @string.special.symbol, @tag,
@tag.doctype, @text.literal, @title, @type, @type.builtin, @variable,
@variable.special, @variable.parameter, @variant
