; Comments
(comment) @comment

; Node names (no indent)
(node) @string

; Property values (after colon)
(property value: (value) @string)

; Colon separator
":" @punctuation.delimiter

; Error: colon after unindented node name
(error_node) @boolean
