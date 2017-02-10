(ns macro_unless)

(defmacro unless [pred a b]
  `(if (not ~pred) ~a ~b))

;; main
(prn (unless 'true "a" "b")) ; => b
