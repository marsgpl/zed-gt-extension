# about

this is a zed editor extension to highlight syntax for custom text file "gt". zed must build it automatically: no source code generation or compilation is needed in this repo.

## instructions

- never run commands like npx yourself, always ask user
- never update the grammars folder (it is auto-generated)

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
inva!id
  bad indent: ok?
```

## how should it highlight syntax

- unindented line is a node name. valid: @keyword. invalid: @comment. validation regexp: /[a-zA-Z0-9_- ]+/.
- indented line must have 2 parts: before ":" and after. if there is no ":" then treat whole line as @comment. left part is relation node name. same validation regexp. treat as @property if valid, @comment if invalid. right part is node name. same validation regexp. treat as @keyword if valid, @comment if invalid.

## available tokens

@attribute, @boolean, @comment, @comment.doc, @constant, @constant.builtin,
@constructor, @embedded, @emphasis, @emphasis.strong, @enum, @function, @hint,
@keyword, @label, @link_text, @link_uri, @number, @operator, @predictive,
@preproc, @primary, @property, @punctuation, @punctuation.bracket,
@punctuation.delimiter, @punctuation.list_marker, @punctuation.special, @string,
@string.escape, @string.regex, @string.special, @string.special.symbol, @tag,
@tag.doctype, @text.literal, @title, @type, @type.builtin, @variable,
@variable.special, @variable.parameter, @variant
