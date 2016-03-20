(defn prime [lst]
  (if (empty? lst) '()
      (cons (first lst)
            (prime (filter (fn [x] (not (zero? (mod x (first lst)))))
                           (rest lst))))))

;; main
(println (prime (range 2 100)))
