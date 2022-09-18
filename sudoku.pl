valide_ligne(LIGNE) :-
    length(LIGNE, 9).
     

% swipl -g run_tests -t halt sudoku.pl
:- begin_tests(sudoku).

test('lignes contiennent des valeurs entre 1 et 9') :-
    not(valide_ligne([12])).

test('lignes contiennent 9 valeurs') :-
    valide_ligne([1, 2, 3, 4, 5, 6, 7, 8, 9]).

:- end_tests(sudoku).
