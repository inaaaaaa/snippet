# eval_metric

| mnemonic | description                           | range       | better |
|:---------|:--------------------------------------|:------------|:-------|
| rmse     | root mean square error                | 0 <= x      | small  |
| logloss  | negative log-likelihood               | ?           | ?      |
| error    | #(wrong cases) / #(all cases)         | 0 <= x <= 1 | small  |
| auc      | Area under the curve                  | 0 <= x <= 1 | bigger |
| ndcg     | Normalized Discounted Cumulative Gain | x <= 1      | bigger |
| map      | Mean average precision                | 0 < x <= 1  | bigger |
