valide_ligne(ligne) :-
    false.

:- begin_tests(sudoku).

test('lignes contiennent des valeurs entre 1 et 9') :-
    not(valide_ligne([12])).

:- end_tests(sudoku).
