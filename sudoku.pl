:- use_module(library(clpfd)).

right_range([]).
right_range([X | REST]):-
    X in 1..9,
    right_range(REST).

valide_ligne(LIGNE) :-
    length(LIGNE, 9),
    right_range(LIGNE).
     

% swipl -g run_tests -t halt sudoku.pl
:- begin_tests(sudoku).

test('une ligne contenant 10 est invalide') :-
    not(valide_ligne([10, 1, 2, 3, 4, 5, 6, 7, 8])).

test('une ligne contenant 0 est invalide') :-
    not(valide_ligne([0, 1, 2, 3, 4, 5, 6, 7, 8])).

test('lignes contiennent 9 valeurs') :-
    valide_ligne([1, 2, 3, 4, 5, 6, 7, 8, 9]).

:- end_tests(sudoku).
