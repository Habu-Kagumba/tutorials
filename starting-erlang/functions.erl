-module(functions).
-export(
   [
    head/1,
    second/1,
    same/2,
    valid_date/1,
    right_age/1,
    if_exp/0,
    working_if/1,
    comp_if/1
   ]
  ).

head([H|_]) -> H.

second([_,X|_]) -> X.

same(X,X) ->
    true;
same(_,_) ->
    false.

valid_date({Date = {Y,M,D}, Time = {H,Min,S}}) ->
    io:format("The Date tuple (~p) says today is: ~p/~p/~p,~n", [Date,Y,M,D]),
    io:format("The Time tuple (~p) indicates: ~p:~p:~p.~n", [Time,H,Min,S]);
valid_date(_) ->
    io:format("Stop feeding me wrong data!~n").

right_age(A) when A >= 16, A < 100 ->
    true;
right_age(_) ->
    false.

if_exp() ->
    if 1 =:= 1 -> works
    end,
    if 1 =:= 2, 1 =:= 1 -> fails
    end.

working_if(N) ->
    if N =:= 1 -> might_succeed;
       true -> always_succeeds
    end.

comp_if(Animal) ->
    Talk = if Animal == cat -> "meow";
              Animal == cow -> "moo";
              true -> "some wierd sound"
           end,
    {Animal, "says " ++ Talk ++ "!"}.
