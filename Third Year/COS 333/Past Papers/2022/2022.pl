stripOccurences(_, [], []).

stripOccurences(X, [H|T], R) :-
    X = H,
    stripOccurences(X, T, R).

stripOccurences(X, [H|T], [H|R]) :-
    X \= H,
    stripOccurences(X, T, R).