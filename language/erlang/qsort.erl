-module(qsort).

fac(0) -> 1;
fac(N) when N > 0 ->
    N * fac(N - 1).

qsort([]) -> [];
qsort([X|XS]) ->
    qsort([Y || Y <- XS, Y < X])
        ++ [X]
        ++ qsort([Y || Y <- XS, Y >= X]).

main(_) ->
    X = 100,
    Y = X + 1,
    erlang:display(Y),
    erlang:display(fac(5)),
    erlang:display(qsort([2, 4, 1])).
