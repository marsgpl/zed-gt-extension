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

the file must not start with an edge line. before the first node line, only blank lines are allowed; any indented line that appears before any node is an error (an edge with no node to attach to is meaningless).

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
- an indented (edge) line before any node line has been declared

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

- `grammar.js` — tree-sitter grammar source. `node_line` and `edge_line` are structural (not atomic) so each sub-part (`node_name`, `edge_name`, `:`, `target_name`) is its own tree-sitter node and gets its own highlight capture. to prevent tree-sitter's automatic error recovery from masking deviations (e.g. a stray space in the indent or a missing space after `:`), the `conflicts` declaration combined with `prec.dynamic` enables GLR parsing: for any line that could be either a valid structural line or an `error_line`, both branches are explored in parallel. if the structural branch fails partway, it dies and `error_line` wins for the whole line. `source_file` puts `edge_line` only inside the optional that follows the first `node_line`, so before any node is declared the only valid alternatives are `blank_line` and `error_line` — that's how indented-line-at-file-start gets rejected.
- `languages/gt/highlights.scm` — capture rules: `node_name` and `target_name` → `@type`; `edge_name` → `@property`; `:` → `@punctuation.delimiter`; `error_line` and `(ERROR)` → `@variant`.
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
