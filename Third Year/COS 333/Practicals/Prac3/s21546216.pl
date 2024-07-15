% Task1
married(peter, mary).
married(lilly, joseph).

ownsPet(peter, rover).
ownsPet(mary, fluffy).
ownsPet(joseph, tweety).
ownsPet(lilly, fluffy).

household(X, Y) :- married(X, Y); married(Y, X).

householdPet(O1, O2, P) :- household(O1, O2), (ownsPet(O1, P); ownsPet(O2, P)).
householdPet(O1, O2, P) :- ownsPet(O1, P), ownsPet(O2, P).

wanderingPet(P) :- ownsPet(X, P), ownsPet(Y, P), X \= Y, not(household(X,Y)). % Check to see if there are two people who own the same pet but dont live in the same house

% Task2
addPositives([], 0).
addPositives([H|T], Sum) :-
    H > 0, % Check if the head is positive
    addPositives(T, Rest), % If so, Recursively call the function with the rest of the list - the head
    Sum is H + Rest. % Add the head to the sum of the rest of the list
addPositives([H|T], Sum) :-
    H =< 0, % Check if the head is not positive
    addPositives(T, Sum). % If so, Recursively call the function with the rest of the list - the head but dont add its value

% Task3
% Base case 1: empty list, return empty list
getEverySecondValue([], []). 
% Base case 2: list with one element, return empty list as the first element doesnt matter
getEverySecondValue([_], []). 
% Recursive case: skip the first element and get the second element, then call the function again with the rest of the list
getEverySecondValue([_, X | T], [X | Result]) :-
    getEverySecondValue(T, Result). 




