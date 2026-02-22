; Valid node names (unindented, valid chars only)
((node) @keyword
 (#match? @keyword "^[a-zA-Z0-9_ -]+$"))

; Invalid node names
((node) @comment
 (#not-match? @comment "^[a-zA-Z0-9_ -]+$"))

; Valid keys (relation names)
((key) @property
 (#match? @property "^[a-zA-Z0-9_ -]+$"))

; Invalid keys
((key) @comment
 (#not-match? @comment "^[a-zA-Z0-9_ -]+$"))

; Valid values (node names)
((value) @keyword
 (#match? @keyword "^[a-zA-Z0-9_ -]+$"))

; Invalid values
((value) @comment
 (#not-match? @comment "^[a-zA-Z0-9_ -]+$"))

; Colon separator
":" @punctuation.delimiter

; Comment lines (indented without colon)
(comment_content) @comment

; Invalid/unmatched lines
(invalid_line) @comment
