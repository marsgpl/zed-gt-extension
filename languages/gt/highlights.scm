; Valid node
((node) @type
 (#match? @type "^[a-z0-9_-]+( [a-z0-9_-]+)*$"))

; Invalid node
((node) @comment
 (#not-match? @comment "^[a-z0-9_-]+( [a-z0-9_-]+)*$"))

; Valid key
((key) @property
 (#match? @property "^[a-z0-9_-]+( [a-z0-9_-]+)*$"))

; Invalid key
((key) @comment
 (#not-match? @comment "^[a-z0-9_-]+( [a-z0-9_-]+)*$"))

; Valid value
((value) @type
 (#match? @type "^[a-z0-9_-]+( [a-z0-9_-]+)*$"))

; Invalid value
((value) @comment
 (#not-match? @comment "^[a-z0-9_-]+( [a-z0-9_-]+)*$"))

":" @punctuation.delimiter
(comment) @comment
