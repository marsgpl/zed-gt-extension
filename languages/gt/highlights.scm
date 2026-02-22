; Invalid (default fallback)
(node) @comment
(key) @comment
(value) @comment

; Valid (override if matches pattern)
((node) @keyword
 (#match? @keyword "^[a-zA-Z0-9_ -]+$"))

((key) @property
 (#match? @property "^[a-zA-Z0-9_ -]+$"))

((value) @keyword
 (#match? @keyword "^[a-zA-Z0-9_ -]+$"))

":" @punctuation.delimiter
(comment) @comment
