#lang sicp
(define (getEveryEvenElement lst)
    (let ((result (recursiveHelper lst 1)))

    (define output result) ; store the result in the output list
    output) ; return the output list
)

(define (recursiveHelper lst index)
    (if (null? lst) 
        ; base case: empty list to be used to populate the even inex characters
        '()
        ; recursive case: keep pushing the new shorter list onto the stack until the list is empty
        (let ((tempResults (recursiveHelper (cdr lst) (+ index 1))))
            (if (even? index) ; If the index is even append it to the list
                ; Case even: append the first element in lst to the list and return the list
                (cons (car lst) tempResults)
                ; Case odd: return the list without the addition of the first element
                tempResults
            )
        )
    )
)

; Test cases
(getEveryEvenElement '())
(getEveryEvenElement '(a))
(getEveryEvenElement '(a b))
(getEveryEvenElement '(a b c))
(getEveryEvenElement '(a b c d))
