(ns map)

(defmulti _map (fn [f lst] lst))
(defmethod _map '() [f lst] '())
(defmethod _map :default [f lst] (cons (f (first lst))
                                       (map f (rest lst))))

;; main
(prn (_map (fn [x] (* x x)) (range 1 12)))
