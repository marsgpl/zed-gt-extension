# about

this is a zed editor extension that highlights syntax for the custom text format `*.gt`. zed builds it automatically: no source code generation or compilation is needed in this repo.

## instructions

- never run commands like `npx` yourself, always ask user
- never update the `grammars/` folder (it is auto-generated)
- never edit `src/` (regenerated from `grammar.js` by `npx tree-sitter generate`)

## what `.gt` describes

a graph: nodes identified by name, with edges (relations) to other named nodes.

## syntax

a `.gt` file is a sequence of lines. each line is exactly one of: a blank line, a node line, an edge line. anything else is an error.

### name

used for node identifiers, edge identifiers, and edge targets. allowed characters are `a-zA-Z0-9_-` and single spaces between printable characters. specifically:

- no leading or trailing whitespace
- no consecutive spaces
- no characters outside `[a-zA-Z0-9_-]` (other than the single internal spaces)

regex: `[a-zA-Z0-9_-]+( [a-zA-Z0-9_-]+)*`

### node line

format: `<name>\n`

- no indentation
- the entire line is a single name

### edge line

format: `    <name>: <name>\n`

- exactly 4 spaces of indentation
- edge name (a name)
- exactly one `:` immediately after the edge name (no space before)
- exactly one space after the `:`
- target node name (a name)
- nothing else before the newline

### valid example

```gt
self
    created by: yura
    is: ai
```

## errors

any deviation from the format above is an error. examples:

- trailing whitespace
- two or more consecutive spaces
- missing space after `:`
- space before `:`
- indentation that is not exactly 4 spaces
- a `:` on a non-indented line
- multiple `:` on the same line
- 4-space indent without a `:`
- characters outside the allowed set
- a final line without a trailing `\n` (the grammar requires line termination)

errors are highlighted using the `@variant` capture so themes can render them as a highly visible style (red background, white text).

### theming errors red

`@variant` is rendered with whatever style the active zed theme defines for `variant` — which is usually not red. to force red bg / white text, the user adds an override to `~/.config/zed/settings.json`:

```json
{
  "experimental.theme_overrides": {
    "syntax": {
      "variant": {
        "color": "#ffffff",
        "background_color": "#cc0000"
      }
    }
  }
}
```

## architecture

- `grammar.js` — tree-sitter grammar source. each line type (`node_line`, `edge_line`, `error_line`, `blank_line`) is a single atomic regex token. this is intentional: structural rules with shared sub-tokens let tree-sitter's lexer commit to a partial token (e.g. the literal `"    "` indent) and then trigger automatic error recovery, which can mask deviations or split a malformed line into a valid prefix + ERROR suffix. atomic line tokens force the lexer to match the entire line or reject it, so any deviation falls cleanly through to `error_line`.
- `languages/gt/highlights.scm` — capture rules. since `node_line` and `edge_line` are atomic, the whole line gets one capture (no separate colors for `edge_name` vs `target_name`).
- `languages/gt/config.toml` — language metadata for zed
- `extension.toml` — zed extension manifest; `commit` field pins the grammar revision zed pulls
- `src/` — generated parser (do not edit)
- `grammars/` — auto-managed grammar checkout (do not edit)

## release

after editing `grammar.js`, run `npm run release` to regenerate the parser, commit, bump the commit hash in `extension.toml`, and push. (the user runs this — never run `npx` yourself.)

## available capture tokens

@attribute, @boolean, @comment, @comment.doc, @constant, @constant.builtin,
@constructor, @embedded, @emphasis, @emphasis.strong, @enum, @function, @hint,
@keyword, @label, @link_text, @link_uri, @number, @operator, @predictive,
@preproc, @primary, @property, @punctuation, @punctuation.bracket,
@punctuation.delimiter, @punctuation.list_marker, @punctuation.special, @string,
@string.escape, @string.regex, @string.special, @string.special.symbol, @tag,
@tag.doctype, @text.literal, @title, @type, @type.builtin, @variable,
@variable.special, @variable.parameter, @variant
