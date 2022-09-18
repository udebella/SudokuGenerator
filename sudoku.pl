:- use_module(library(clpfd)).

valide_ligne(LIGNE) :-
    length(LIGNE, 9), LIGNE ins 1..9,
    all_distinct(LIGNE).

read_columns_from_grid(X, X).
     

% swipl -g run_tests -t halt sudoku.pl
:- begin_tests(sudoku).

test('une ligne contenant 10 est invalide') :-
    not(valide_ligne([10, 1, 2, 3, 4, 5, 6, 7, 8])).

test('une ligne contenant 0 est invalide') :-
    not(valide_ligne([0, 1, 2, 3, 4, 5, 6, 7, 8])).

test('une ligne contenant deux fois la même valeur est invalide') :-
    not(valide_ligne([1, 1, 2, 3, 4, 5, 6, 7, 8])).

test('lignes contiennent 9 valeurs') :-
    valide_ligne([1, 2, 3, 4, 5, 6, 7, 8, 9]).


test('can read columns from 1 length grids') :-
    read_columns_from_grid([[1]], [[1]]).

:- end_tests(sudoku).
