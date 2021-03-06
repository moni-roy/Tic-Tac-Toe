# Tic-Tac-Toe

Project for CS 682: Artificial intelligence

## Purpose

The purpose of this assignment is to provide a basic programming experience with an algorithm commonly-used in AI. You should be able to demonstrate the ability to utilize a recursive algorithm in a game-playing scenario.

## Algorithms

This program uses the minimax algorithm with alpha-beta pruning to find the best available moves

### Algorithm Details

A minimax algorithm is a recursive algorithm for choosing the next move in an n-player game, usually a two-player game. A value is associated with each position or state of the game. This value is computed by means of a position evaluation function and it indicates how good it would be for a player to reach that position. The player then makes the move that maximizes the minimum value of the position resulting from the opponent's possible following moves. If it is A's turn to move, A gives a value to each of their legal moves.

Alpha–beta pruning is a search algorithm that seeks to decrease the number of nodes that are evaluated by the minimax algorithm in its search tree. It is an adversarial search algorithm used commonly for machine playing of two-player games (Tic-tac-toe, Chess, Go, etc.). It stops evaluating a move when at least one possibility has been found that proves the move to be worse than a previously examined move. Such moves need not be evaluated further. When applied to a standard minimax tree, it returns the same move as minimax would, but prunes away branches that cannot possibly influence the final decision.

### Pseudocode

```
function minimax_optimization(node, alpha, beta, maximizingPlayer) is
    if node is a terminal node or don't have legal moves then
        return the heuristic value of node
    if maximizingPlayer then
        value := -INF
        for each child of node do
            value := max(value, minimax_optimization(child, alpha, beta, FALSE))
            alpha := max(alpha, value)
            if value >= beta then
                break 
        return value
    else
        value := +INF
        for each child of node do
            value := min(value, minimax_optimization(child, alpha, beta, TRUE))
            beta := min(beta, value)
            if value <= alpha then
                break 
        return value
```

```
<Initial call>
minimax_optimization(origin, -INF, +INF, TRUE)
```

## Pre-requisities for run locally

- cmake >= 2.6

  - [Installation instructions](https://cmake.org/install/)

- make

  - Linux: make is installed by default on most Linux distros
  - Mac: [See the xcode feature list](https://developer.apple.com/xcode/features/)
  - Windows: [Installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)

- gcc/g++ >= 5.4
  - Linux: gcc / g++ is installed by default on most Linux distros
  - Mac: [See the xcode feature list](https://developer.apple.com/xcode/features/)
  - Windows: recommend using [MinGW](http://www.mingw.org/)

## Compilation Instructions

```
<this section should only need to be done once>
$ mkdir build && cd build
$ cmake ..

<each time you want to compile (from the build directory)>
$ make
(if successful, the executable will be in the ’build’ directory)
```

## Test/Play Instructions

```
Usage
    ./tictactoe [inputFile] [outputFile] [--play]

DESCRIPTIONS
    A program to play the 3×3 tic–tac–toe game interactively.

    The program used a minimax search algorithm with alpha-beta
    pruning to get the best moves if no immediate win move is available.

    If the initial state is in losing position,
    it will return the first available move.


OPTIONS
    inputFile
        Name of the input file. It contains the initial board state.

        The board value should be -1, 0, or 1,
        where -1, 0, and 1 means O, empty, and X, respectively.

        If you give the the inputFile, you must give the outFile as well.

    outputFile
        Name of the output file. Programs will save the final state of the board.
        If file is not exit, it will create one.

    --play
        If you want to play interactively with AI.
        Otherwise, the program will make only one move.
```

## Run Command

```
<need to run from buld directory, skip if already in there>
$ cd build

<comand to make one possible best move>
$ ./tictactoe test.board out.board

<command to play interactively with AI>
$ ./tictactoe test.board out.board --play

<command to play from the ZERO state>
$ ./tictactoe
```

## Results and Discussion

Please see the [report](https://github.com/moni-roy/Tic-Tac-Toe/blob/main/report/Report.pdf) for details.
