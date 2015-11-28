#lang racket

(define lst '(0 1 2 3 4 5))

(define (my-reverse lst)
  (foldl (lambda (e v) (cons e v))
         '()
         lst))

(define (my-reverse* lst target)
  (if (null? lst)
      target
      (my-reverse* (cdr lst) (cons (car lst) target))))

; main
(my-reverse lst)
(my-reverse* lst '())
