#lang sicp
(define (circleArea radius)
    (let ((pi (/ 22 7)))
        (if (<= radius 0)
                0
                (* pi (* radius radius)))))

(circleArea 3.2)