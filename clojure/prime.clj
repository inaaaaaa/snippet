(defn prime [lst]
  (if (empty? lst) '()
      (cons (first lst)
            (prime (filter (fn [x] (not (= (mod x (first lst)) 0)))
                           (rest lst))))))

;; main
(println (prime (range 2 100)))
