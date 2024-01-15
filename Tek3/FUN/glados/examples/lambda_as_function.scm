(define (apply-twice f x) (f (f x)))
(apply-twice (lambda (x) (* x x)) 2)
