# about

this is a zed editor extension to highlight syntax for custom text file "gt"

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
self
    is: ai
```

## how should it highlight syntax

- if no indentation: node name: orange color
- if indentation (4 spaces "    "): relation name: default color
- after ":" goes node name relation relates to: orange color
- if ":" goes after node name that has no indentation: highlight as error (red)
- node names can contain spaces, marker should be ":"

## available tokens

@attribute, @boolean, @comment, @comment.doc, @constant, @constant.builtin,
@constructor, @embedded, @emphasis, @emphasis.strong, @enum, @function, @hint,
@keyword, @label, @link_text, @link_uri, @number, @operator, @predictive,
@preproc, @primary, @property, @punctuation, @punctuation.bracket,
@punctuation.delimiter, @punctuation.list_marker, @punctuation.special, @string,
@string.escape, @string.regex, @string.special, @string.special.symbol, @tag,
@tag.doctype, @text.literal, @title, @type, @type.builtin, @variable,
@variable.special, @variable.parameter, @variant
