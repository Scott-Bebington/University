#lang sicp
(define (countDivisors numToBeDivided Divisors)
    (if (null? Divisors) ; base case: empty list
        0
        (if (= 0 (remainder numToBeDivided (car Divisors))) ; check if the number is divisible by the current divisor
            (+ 1 (countDivisors numToBeDivided (cdr Divisors))) ; If the number is divisible, add 1 to the count and check the next divisor
            (countDivisors numToBeDivided (cdr Divisors)) ; If the number is not divisible, check the next divisor
        )
    )
)

(countDivisors 10 '())
(countDivisors 10 '(20 50 60))
(countDivisors 10 '(1 20 30 2 5 40 10 60))