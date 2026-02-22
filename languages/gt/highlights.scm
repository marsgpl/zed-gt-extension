; Comments
(comment) @comment

; Node names (no indent) - valid nodes
(node) @keyword

; Property key (relation name)
(property key: (key) @property)

; Property values (after colon)
(property value: (value) @string)

; Colon separator
":" @punctuation.delimiter

; Invalid lines
(error_node) @comment
(invalid_indent) @comment
