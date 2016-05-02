(require '[clojure.string :as str]
         '[clojure.java.io :as io])

(with-open [r (io/reader "sample_input.csv")]
  (doseq [line (line-seq r)]
    (let [[x y] (str/split line #",")]
      (println (str/join "\n" [x y])))))
