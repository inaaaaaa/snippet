#lang racket

(define (memo-proc proc)
  (let ([first-time? #t]
        [result null])
    (lambda ()
      (when first-time?
        (set! first-time? #f)
        (set! result (proc)))
      result)))

(define-syntax-rule (my-delay expr)
  (memo-proc (lambda () expr))) ; memoization
;  (lambda () expr)) ; non memoization

(define (my-force delayed-obj)
  (delayed-obj))

(define-syntax-rule (stream-cons a b)
  (cons a (my-delay b)))

(define (stream-car s)
  (car s))

(define (stream-cdr s)
  (if (null? s)
      '()
      (my-force (cdr s))))

(define (heavy-nats)
  (sleep 1) ; heavy calculation
  (stream-cons 1 (stream-map add1 (heavy-nats))))

(define (stream-map f s)
  (if (null? s)
      '()
      (stream-cons (f (stream-car s)) (stream-map f (stream-cdr s)))))

(define (stream-take s n)
  (displayln "***")
  (displayln s)
  (if (zero? n)
      '()
      (cons (stream-car s)
            (stream-take (stream-cdr s) (sub1 n)))))

;; main
(let ([xs (heavy-nats)])
  (time (stream-take xs 5))
  (time (stream-take xs 5))
  (time (stream-take xs 10)))
