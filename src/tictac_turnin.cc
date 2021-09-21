#include <tictac_support.h>
#include <bits/stdc++.h>

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
		(current implementation returns 1 by default, 0 if no move made)
**/
int make_move(int board[][3], bool interactive)
{
	// figure out what move it is
	int state = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != 1 && board[i][j] != 0 && board[i][j] != -1)
			{

				std::cout << "The board is not valid. Input matrix should be either 1, 0, 0r -1 (integer).\n";
				return 0;
			}
			state += board[i][j];
		}
	}

	print_board(board);
	if (is_winner(board, 1) || is_winner(board, -1))
	{
		std::cout << "The board has atleat a winner!.\n";
		return 0;
	}

	state = -state;
	if (state == 0)
		state = 1;

	if (interactive)
	{

		std::string s;
		std::cout << "Do you want to start? (y/n): ";
		std::cin >> s;

		int x, y;
		if (s == "yes" || s == "y" || s == "YES" || s == "Yes")
		{

			if (user_input(board, state))
			{
				state = -state;
				print_board(board);
			}
			else
				return 0;
		}
	}

	int AI = state, human = -state;

	do
	{
		if (game_over(board, AI, human))
			return 1;

		std::pair<int, std::pair<int, int>> best_move = minimax_optimization(board, AI, -10000, 10000, AI, human);
		board[best_move.second.first][best_move.second.second] = AI;
		std::cout << "Best move by AI " << (AI == 1 ? "(user X)" : "(user O)") << ": " << best_move.second.first << " " << best_move.second.second << "\n";
		print_board(board);

		if (interactive)
		{
			if (game_over(board, AI, human))
				return 1;
			if (!user_input(board, human))
				return 0;
			print_board(board);
		}

	} while (interactive);

	return 1;
}

// Print the board
void print_board(int board[3][3])
{
	std::vector<std::vector<char>> display_board(3, std::vector<char>(3, ' '));
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		if (i)
			std::cout << "----------" << std::endl;
		for (int j = 0; j < 3; j++)
		{
			if (j)
				std::cout << " | ";
			if (board[i][j] == -1)
				std::cout << 'O';
			else if (board[i][j] == 1)
				std::cout << 'X';
			else
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// get user input
bool user_input(int board[][3], int state)
{
	while (true)
	{
		int x, y;
		std::cout << "Enter the x, y (0 - indexed): ";
		std::cin >> x >> y;

		if (x > 3 || x < 0 || y > 3 || y < 0 || board[x][y] != 0)
		{
			std::cout << "Invalid move. Please try another position.\n";
			std::string s;
			std::cout << "Do you want to try again? (y/n): ";
			std::cin >> s;
			if (s != "yes" && s != "y" && s != "YES" && s != "Yes")
			{
				return false;
			}
		}
		else
		{
			board[x][y] = state;
			return true;
		}
	}
}

bool game_over(int board[][3], int &AI, int &human)
{
	if (get_moves(board, AI, human).size() == 0)
	{
		std::cout << "Match Draw!!\n";
		return true;
	}
	int score = is_over(board, AI, human);
	std::cout << score;
	if (score != 0)
	{
		if (score > 0)
			std::cout << "You Lost!" << (human == 1 ? "(user X)" : "(user O)") << ".\n";
		else
			std::cout << "You win!!\n";
		return true;
	}
	return false;
}