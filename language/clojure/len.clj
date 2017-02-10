(ns len)

(defmulti len identity)
(defmethod len '() [lst] 0)
(defmethod len :default [lst] (inc (len (rest lst))))

;; main
(prn (len '(1 2 3 4 5)))
(prn (len (range 1000)))
