#lang racket

(define lst '(1 1 1 3 4))

(define (split* x xs)
  (cond [(null? xs) (cons '() '())]
        [(not (eqv? x (car xs))) (cons '() (list xs))]
        [else (let ([next (split* x (cdr xs))])
                (cons (cons (car xs) (car next))
                      (cdr next)))]))

; main
(split* 3 '()) ; => '(())
(split* (car lst) lst) ; => '((1 1 1) (3 4))
