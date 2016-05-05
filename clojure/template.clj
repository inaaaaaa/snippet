(ns template)

;; This script will cause the same result by below commands.
;; case1. $ lein run foo
;; case2. $ java -cp ~/local/clojure-1.8.0/clojure-1.8.0.jar clojure.main template.clj foo

(defn hello [x]
  (str "hello " x))

;; main
(defn -main [args]
  (prn (hello (first args)))
  (System/exit 0))

(-main *command-line-args*)
