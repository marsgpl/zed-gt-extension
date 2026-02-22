; Valid node names (no indent)
(valid_node) @keyword

; Valid property
(key) @property
(value) @keyword

; Colon separator
":" @punctuation.delimiter

; Invalid lines (wrong indent, bad chars, wrong format)
(comment) @comment
(invalid_line) @comment
