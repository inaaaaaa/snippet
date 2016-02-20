-module(hello_world).
-export([hello/0]).

%% how to run : escript hello_world.erl

hello() ->
    io:format("Hello, world!~n").

main(_) ->
    hello(),
    hello(),
    hello().
