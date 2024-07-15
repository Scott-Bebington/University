#lang sicp
(display "2022 Semester test 1")
(newline)
(display "Question 23")
(newline)
(define (sphereVolume radius)
  (if (>= 0 radius)
      0
      (let ((radiusCubed (* (* radius radius) radius)))
        (let ((pi 3.14))
          (let ((fourOverThree (/ 4 3)))
            (* fourOverThree (* pi radiusCubed))
          )
        )
      )
  )
)

(sphereVolume 3.2)
(newline)
(display "Question 24")
(newline)
(define (countPositiveEvenNumbers lst)
  (cond
    ((null? lst) 0) ; If the list is empty, return 0 as the initial count
    ((or (zero? (car lst)) (odd? (car lst)) (negative? (car lst))) (+ 0 (countPositiveEvenNumbers (cdr lst)))) ; Return a smaller list not incrementing the counter
    (else (+ 1 (countPositiveEvenNumbers (cdr lst)))) ; Does meet all the requirements, return smaller list and increment the counter
  )
)

(countPositiveEvenNumbers '())
(countPositiveEvenNumbers '(-2 4 0 5 8 3))


(newline)
(display "2023 Semester test 1")
(newline)
(display "Question 23")
(newline)
(define (cylinderVolume radius height)
  (let ((pi (/ 22 7)))
    (let ((radiusSquared (* radius radius)))
      (* pi (* radiusSquared height))
    )
  )
)

(cylinderVolume 2.8 1.7)


(newline)
(display "Question 24")
(newline)
(define (countNonMatchingValues lst value)
  (cond
    ((null? lst) 0) ; Return 0 as the end of the list has been reached
    ((eq? value (car lst)) (+ 0 (countNonMatchingValues (cdr lst) value))) ; Values match, Dont increment the counter and send in the new smaller list
    (else (+ 1 (countNonMatchingValues (cdr lst) value))) ; Values dont match, Increment the counter and send in the new smaller list
  )
)

(countNonMatchingValues '() 'A)
(countNonMatchingValues '(A B A C D) 'A)

