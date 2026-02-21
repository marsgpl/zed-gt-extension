# about

this is a zed editor extension to highlight syntax for custom text file "gt".

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

- if no indentation: node name: blue color
- if indentation (4 spaces "    "): relation name: default color
- after ":" goes node name relation relates to: blue color
- if ":" goes after node name that has no indentation: highlight as error (red)
- node names can contain spaces, marker should be ":"
