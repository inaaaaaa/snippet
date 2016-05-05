(ns curl)

(defn curl! [method url]
  {:pre [(some #(= method %) ["GET" "POST" "PUT" "DELETE"])
         (string? url)]
   :post (string? %)}
  (let [conn (. (new java.net.URL url) openConnection)]
    (try
      (. conn setRequestMethod method)
      (slurp (-> conn (. getContent)))
      (catch Exception e (str "caught exception: " (.getMessage e)))
      (finally (.disconnect conn)))))

;; main
(defn -main [args]
  (prn (curl! "GET" "http://yahoo.co.jp"))
  (System/exit 0))
(-main *command-line-args*)
