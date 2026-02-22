; Comments
(comment) @comment

; Node names (no indent) - valid nodes
(node) @keyword

; Valid property content
(valid_key) @property
(valid_value) @keyword

; Colon separator
":" @punctuation.delimiter

; Invalid lines
(error_node) @comment
(property_invalid) @comment
(wrong_indent) @comment
