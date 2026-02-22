; Comments
(comment) @comment

; Node names (no indent) - valid nodes
(node) @keyword

; Property key (relation name)
(valid_key) @property
(invalid_key) @comment

; Property values (after colon)
(valid_value) @keyword
(invalid_value) @comment

; Colon separator
":" @punctuation.delimiter

; Invalid lines
(error_node) @comment
(invalid_property) @comment
(wrong_indent) @comment
