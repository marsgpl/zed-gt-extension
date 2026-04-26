# about

this is a zed editor extension that highlights syntax for the custom text format `*.gt`. zed builds it automatically: no source code generation or compilation is needed in this repo.

## instructions

- never run commands like `npx` yourself, always ask user
- never update the `grammars/` folder (it is auto-generated)
- never edit `src/parser.c`, `src/grammar.json`, or `src/node-types.json` (regenerated from `grammar.js` by `npx tree-sitter generate`)
- `src/scanner.c` is hand-written (the external scanner) and IS edited directly when changing line-validation behavior

## what `.gt` describes

a graph: nodes identified by name, with edges (relations) to other named nodes.

## syntax

a `.gt` file is a sequence of lines. each line is exactly one of: a node line or an edge line. anything else is an error.

blank lines are not allowed: any two consecutive `\n` bytes (i.e. an empty line) are an error.

the file must not start with an edge line. an indented line that appears before any node is an error (an edge with no node to attach to is meaningless).

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
- a blank line (two consecutive `\n`)

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

- `grammar.js` — tree-sitter grammar source. declares four external tokens (`_node_line_marker`, `_edge_line_marker`, `error_line`, `blank_line`) that come from `src/scanner.c`. `node_line` and `edge_line` are structural (`seq` of sub-rules) so `node_name`, `edge_name`, `:`, and `target_name` each appear as their own tree-sitter nodes and get separate highlight captures. each structural rule starts with the corresponding zero-width marker, so the grammar only attempts a structural parse when the scanner has already validated the entire line. `source_file = (blank | error)*  (node_line _line*)?` — `_edge_line_marker` is unreachable from the start state, so it's not in the scanner's `valid_symbols` at the top of the file and indented first lines fall to `error_line`.
- `src/scanner.c` — hand-written external scanner. for each line it reads the line into a buffer, validates the shape against the spec, and emits one of: `NODE_LINE_MARKER` (zero-width, valid node), `EDGE_LINE_MARKER` (zero-width, valid edge), or `ERROR_LINE` (atomic, covers the whole malformed line — including blank lines, which are disallowed). validating in C, before tree-sitter's parser sees any tokens, avoids tree-sitter's automatic error recovery — there's no partial-parse path that could leak a bad line through as a valid one. `mark_end` is called at the start of scan so subsequent `advance` calls are lookahead only; the lexer resumes from the marked position so a zero-width marker leaves the line text in place for the structural rules to consume.
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
