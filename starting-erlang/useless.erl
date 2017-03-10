-module(useless).
-export([add/2, hello/0, hello_and_add/1, greet/2]).
-author("Herbert Kagumba").
-compile([debug_info]).

%% Add two numbers
add(A,B) ->
    A + B.

%% Prints hello world
hello() ->
    io:format("Hello, world!~n").

%% Greets and add the number with 2
hello_and_add(X) ->
    hello(),
    add(X,2).

%% Greet based on gender

greet(male, Name) ->
    io:format("Hello, Mr. ~s!~n", [Name]);
greet(female, Name) ->
    io:format("Hello, Mrs. ~s!~n", [Name]);
greet(_, Name) ->
    io:format("Hello, ~s!~n", [Name]).
