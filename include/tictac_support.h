#ifndef _TICTAC_SUPPORT_H_
#define _TICTAC_SUPPORT_H_

#include <bits/stdc++.h>

/**
	load_board: loads a tic-tac-toe board state from a file

	args:
		std::string filename: file to read the board from
		int [][3] board: 3x3 array of ints representing the board state
			0: empty
			1: x
		 -1: o

	returns (int):
		0: if file loaded OK
		-1: if file doesn't exist

**/

int load_board(std::string filename, int board[][3]);

/**
	save_board: saves a tic-tac-toe board state to a file

	args:
		std::string filename: file to write the board to
		int [][3] board: 3x3 array of ints representing the board state
			0: empty
			1: x
		 -1: o

	returns (int):
		0: if file opened OK
		-1: if file can't be opened

**/

int save_board(std::string filename, int board[][3]);

/**
	make_move: takes a board state and makes a legal 
	(hopefully optimal) move

	args:
		int [][3] board: 3x3 array of ints representing the 
		board state. The values of board are altered based
		on the move
			0: empty
			1: x
		   -1: o
		interactive: if true, will play the game.
		
	returns (int):
		the number of steps it took to choose the best move
		(returns 1 by default, 0 if no move made)
**/
int make_move(int board[][3], bool interactive = false);

/**
	print_board: takes a board state and print the board

	args:
		int [][3] board: 3x3 array of ints representing the 
		board state. The values of board are altered based
**/
void print_board(int board[][3]);

/**
	user_input: takes a board state and a valid move 
			from user and put in the board

	args:
		int [][3] board: 3x3 array of ints representing the 
		board state. The values of board are altered based
		on the move
			0: empty
			1: x
		   -1: o
		state: it defines the state value for user.
		
	returns (bool):
		true if get the move successfully.
**/
bool user_input(int board[][3], int state);

/**
	game_over: takes a board state and check if game is over. 
		Also print the game state.

	args:
		int [][3] board: 3x3 array of ints representing the 
		board state. The values of board are altered based
		on the move
			0: empty
			1: x
		   -1: o
		AI: it defines the state value for AI.
		human: it defines the state value for human.

	returns (bool):
		true if the game is over.
**/
bool game_over(int board[][3], int &AI, int &human);

/**
	get_moves: takes a board state and gets all available moves.

	args:
		int [][3] board: 3x3 array of ints representing the 
		board state. The values of board are altered based
		on the move
			0: empty
			1: x
		   -1: o
		AI: it defines the state value for AI.
		human: it defines the state value for human.

	returns (std::vector<std::pair<int, int>> ):
		all available moves as a pair of x, y coordinate
**/
std::vector<std::pair<int, int>> get_moves(int board[][3], int &AI, int &human);

/**
	is_over: takes a board state and check if game has any winner nor not.

	args:
		int [][3] board: 3x3 array of ints representing the 
		board state. The values of board are altered based
		on the move
			0: empty
			1: x
		   -1: o
		AI: it defines the state value for AI.
		human: it defines the state value for human.

	returns (int):
		the winnig score if AI win, lossing score if AI lost, or draw score if no winner.
**/
int is_over(int board[][3], int &AI, int &human);

/**
	is_winner: takes a board state and check if the marker is winner.

	args:
		int [][3] board: 3x3 array of ints representing the 
		board state. The values of board are altered based
		on the move
			0: empty
			1: x
		   -1: o
		marker: it defines the state value of AI or human.

	returns (int):
		true if the marker is winner.
**/
bool is_winner(int board[][3], int marker);

/**
	minimax_optimization: runs the minmax optimization (alpha-beta prunig) 
		algorithm to get the best move.

	args:
		int [][3] board: 3x3 array of ints representing the 
		board state. The values of board are altered based
		on the move
			0: empty
			1: x
		   -1: o
		marker: it defines the current state value of AI or human.
		alpha: the value of alpha.
		beta: the value of beta.
		AI: it defines the state value of AI.
		human: it defines the state value of human.

	returns (pair<int, std::pair<int, int>>):
		a pair of best_score and the coordinates of the best move.
**/
std::pair<int, std::pair<int, int>> minimax_optimization(int board[][3], int marker, int alpha, int beta, int &AI, int &human);

#endif