#lang racket

(define (begin-stream lst func-lst)
  (if (null? func-lst)
      lst
      (begin-stream ((car func-lst) lst) (cdr func-lst))))

(define-syntax-rule (run-pipe input f ...)
  (begin-stream input (list f ...)))

(define-syntax-rule (pipe iter-func args ...)
  (lambda (lst) (iter-func args ... lst)))

;; main
(displayln "***map-filter-fold")
(run-pipe (range 30)
          (pipe map (lambda (e) (* e 3)))
          (pipe filter (lambda (e) (< e 20)))
          (pipe foldr + 0))

(displayln "***fizzbuzz")
(run-pipe (range 1 15)
          (pipe map (lambda (n) (cond [(zero? (modulo n 15)) "FizzBuzz"]
                                      [(zero? (modulo n 3)) "Fizz"]
                                      [(zero? (modulo n 5)) "Buzz"]
                                      [else n])))
          (pipe for-each displayln))
