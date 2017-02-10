(ns curl)

(defmacro with-connection
  [[name connection] & body]
  `(let [~name ~connection]
     (try
       ~@body
       (finally
         (.disconnect ~name)))))

(def http-methods #{"GET" "POST" "PUT" "DELETE"})

(defn curl! [method url]
  {:pre [(contains? http-methods method)
         (string? url)]
   :post (string? %)}
  (let [conn (.openConnection (new java.net.URL url))]
    (.setRequestMethod conn method)
    (with-connection [c conn]
      (slurp (.getContent c)))))

;; main
(defn -main [args]
  (prn (curl! "GET" "http://yahoo.co.jp"))
  (System/exit 0))
(-main *command-line-args*)
