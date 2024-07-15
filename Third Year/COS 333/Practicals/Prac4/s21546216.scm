#lang sicp

(define (stripNegativesDuplicateEvens lst)

  (cond
    ((null? lst) '())
    (else (let ((newArr (stripNegativesDuplicateEvens (cdr lst))))
      (cond
        ((and (>= (car lst) 0) (even? (car lst))) (cons (car lst) (cons (car lst) newArr))) ; If the first element is positive and even the duplicate it in the list
        ((>= (car lst) 0) (cons (car lst) newArr)) ; If the first element if positive but not even then just add the letter in
        ((negative? (car lst)) newArr)
      )
    ))
  )

  
)

(stripNegativesDuplicateEvens '())
(stripNegativesDuplicateEvens '(-1 -2 -3))
(stripNegativesDuplicateEvens '(0 1 2 -2 3 -3 4 5 -6))
