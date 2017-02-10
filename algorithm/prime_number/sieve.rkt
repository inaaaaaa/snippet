#lang racket

(require racket/stream)

(define (divisible? n m)
  (zero? (modulo n m)))

(define (sieve s)
  (stream-cons (stream-first s)
               (sieve (stream-filter (lambda (e) (not (divisible? e (stream-first s))))
                                     (stream-rest s)))))

(define (stream-take s n)
  (if (zero? n)
      '()
      (cons (stream-first s)
            (stream-take (stream-rest s) (sub1 n)))))

(define nats (stream-cons 1 (stream-map add1 nats)))
(define primes (sieve (stream-rest nats)))

;; main
(stream-take primes 100)
