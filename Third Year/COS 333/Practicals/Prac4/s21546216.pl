% Predicate to strip negatives and zeros, and duplicate positives
stripNegativesAndZerosDuplicatePositives([], []). % Base case: empty list, result is also empty list.

% Recursive case: if the head of the input list is positive, duplicate it and keep both copies in the result list.
stripNegativesAndZerosDuplicatePositives([H|T], [H,H|Result]) :-
  H > 0, % Check if the head is greater than 0.
  stripNegativesAndZerosDuplicatePositives(T, Result). % Recursively process the tail of the input list.

% Recursive case: if the head of the input list is negative or zero, skip it.
stripNegativesAndZerosDuplicatePositives([H|T], Result) :-
  (H =< 0 ; H =:= 0), % Check if the head is less than or equal to 0.
  stripNegativesAndZerosDuplicatePositives(T, Result). % Recursively process the tail of the input list.
