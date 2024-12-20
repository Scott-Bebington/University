#lang sicp

; Task 1
(display "Task 1")
(newline)
(define (circleArea radius)
    (let ((pi (/ 22 7)))
        (if (<= radius 0)
                0
                (* pi (* radius radius)))))

(circleArea -1.8)

; Task 2
(newline)
(display "Task 2")
(newline)
(define (countDivisors numToBeDivided Divisors)
    (if (null? Divisors) ; base case: empty list
        0
        (if (= 0 (remainder numToBeDivided (car Divisors))) ; check if the number is divisible by the current divisor
            (+ 1 (countDivisors numToBeDivided (cdr Divisors))) ; If the number is divisible, add 1 to the count and check the next divisor
            (countDivisors numToBeDivided (cdr Divisors)) ; If the number is not divisible, check the next divisor
        )
    )
)

(countDivisors 3 '())
(countDivisors 3 '(1 1 3))
(countDivisors 3 '(1 20 30 2 5 40 10 60))

; Task 3
(newline)
(display "Task 2")
(newline)
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
(getEveryEvenElement '(a b c))
(getEveryEvenElement '(a b c d e f g))
