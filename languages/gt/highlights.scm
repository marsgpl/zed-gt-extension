; Valid node
((node) @keyword
 (#match? @keyword "^[a-zA-Z0-9_ -]+$"))

; Invalid node
((node) @comment
 (#not-match? @comment "^[a-zA-Z0-9_ -]+$"))

; Valid key
((key) @property
 (#match? @property "^[a-zA-Z0-9_ -]+$"))

; Invalid key
((key) @comment
 (#not-match? @comment "^[a-zA-Z0-9_ -]+$"))

; Valid value
((value) @keyword
 (#match? @keyword "^[a-zA-Z0-9_ -]+$"))

; Invalid value
((value) @comment
 (#not-match? @comment "^[a-zA-Z0-9_ -]+$"))

":" @punctuation.delimiter
(comment) @comment
