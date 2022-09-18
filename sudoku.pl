:- use_module(library(clpfd)).

sudoku(LINES):-
    read_columns_from_grid(LINES, COLUMNS),
    read_blocks_from_grid(LINES, BLOCKS),
    maplist(sudoku_rules, LINES),
    maplist(sudoku_rules, COLUMNS),
    maplist(sudoku_rules, BLOCKS).

sudoku_rules(LCB) :-
    length(LCB, 9), 
    LCB ins 1..9,
    all_distinct(LCB).

read_columns_from_grid(ROWS, COLUMNS):-
    transpose(ROWS, COLUMNS).

read_blocks_from_grid([], []).
read_blocks_from_grid([L1, L2, L3 | OTHER_LINES], [BLOCK1, BLOCK2, BLOCK3 | OTHER_BLOCKS]) :-
    blocks(L1, L2, L3, [BLOCK1, BLOCK2, BLOCK3]),
    read_blocks_from_grid(OTHER_LINES, OTHER_BLOCKS).

blocks([], [], [], []).
blocks([N1, N2, N3 | R1], [N4, N5, N6 | R2], [N7, N8, N9 | R3], [ROW_BLOCK | REST]):-
    ROW_BLOCK = [N1, N2, N3, N4, N5, N6, N7, N8, N9],
    blocks(R1, R2, R3, REST).

valid_grid([
    [9,8,7, 6,5,4, 3,2,1],
    [2,4,6, 1,7,3, 9,8,5],
    [3,5,1, 9,2,8, 7,4,6],
    
    [1,2,8, 5,3,7, 6,9,4],
    [6,3,4, 8,9,2, 1,5,7],
    [7,9,5, 4,6,1, 8,3,2],
    
    [5,1,9, 2,8,6, 4,7,3],
    [4,7,2, 3,1,9, 5,6,8],
    [8,6,3, 7,4,5, 2,1,9]
]).

% swipl -g run_tests -t halt sudoku.pl
:- begin_tests(sudoku).

test('une ligne contenant 10 est invalide') :-
    not(sudoku_rules([10, 1, 2, 3, 4, 5, 6, 7, 8])).

test('une ligne contenant 0 est invalide') :-
    not(sudoku_rules([0, 1, 2, 3, 4, 5, 6, 7, 8])).

test('une ligne contenant deux fois la même valeur est invalide') :-
    not(sudoku_rules([1, 1, 2, 3, 4, 5, 6, 7, 8])).

test('lignes contiennent 9 valeurs') :-
    sudoku_rules([1, 2, 3, 4, 5, 6, 7, 8, 9]).


test('can read columns from 1 length grids') :-
    read_columns_from_grid([[1]], [[1]]).

test('can read columns from 2 length grids') :-
    read_columns_from_grid([
        [1, 2],
        [3, 4]
    ], [
        [1, 3],
        [2, 4]
    ]).

test('can read blocks from grid') :-
    valid_grid(X),
    read_blocks_from_grid(X, [
        [9,8,7, 2,4,6, 3,5,1],
        [6,5,4, 1,7,3, 9,2,8],
        [3,2,1, 9,8,5, 7,4,6],
        
        [1,2,8, 6,3,4, 7,9,5],
        [5,3,7, 8,9,2, 4,6,1],
        [6,9,4, 1,5,7, 8,3,2],
        
        [5,1,9, 4,7,2, 8,6,3],
        [2,8,6, 3,1,9, 7,4,5],
        [4,7,3, 5,6,8, 2,1,9]
    ]).


test('can check that a grid is valid') :-
    valid_grid(X),
    sudoku(X).

:- end_tests(sudoku).