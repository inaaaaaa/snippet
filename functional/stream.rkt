#lang racket

(require racket/stream)

(define ones (stream-cons 1 ones))

(define nats (stream-cons 1 (stream-map add1 nats)))

(define (fibgen a b)
  (stream-cons a (fibgen b (+ a b))))

(define fibs (fibgen 0 1))

(define (divisible? n m)
  (zero? (modulo n m)))

(define (sieve st)
  (stream-cons (stream-first st)
               (sieve (stream-filter (lambda (e) (not (divisible? e (stream-first st))))
                                     (stream-rest st)))))

(define primes (sieve (stream-rest nats)))

(define (stream-take st n)
  (if (zero? n)
      '()
      (cons (stream-first st) (stream-take (stream-rest st) (sub1 n)))))

; main
(stream-take ones 10)
(stream-take nats 10)
(stream-take fibs 10)
(stream-take primes 10)
