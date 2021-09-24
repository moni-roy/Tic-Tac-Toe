#include <tictac_support.h>
#include <bits/stdc++.h>

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
std::vector<std::pair<int, int>> get_moves(int board[][3], int &AI, int &human)
{
    std::vector<std::pair<int, int>> moves;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != AI && board[i][j] != human)
            {
                moves.push_back(std::make_pair(i, j));
            }
        }
    }

    return moves;
}

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
bool is_winner(int board[][3], int marker)
{
    for (int i = 0; i < 3; i++)
    {
        // check row
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == marker)
            return true;
        // check column
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == marker)
            return true;
    }
    // check diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == marker)
        return true;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == marker)
        return true;
    return false;
}

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
int is_over(int board[][3], int &AI, int &human)
{
    return is_winner(board, AI) ? 10 : (is_winner(board, human) ? -10 : 0);
}

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
std::pair<int, std::pair<int, int>> minimax_optimization(int board[][3], int marker, int alpha, int beta, int &AI, int &human)
{
    // Initialize best move
    std::pair<int, int> best_move = std::make_pair(-1, -1);
    int best_score = (marker == AI) ? -1000 : 1000;

    // If we hit a terminal state (leaf node), return the best score and move
    std::vector<std::pair<int, int>> moves = get_moves(board, AI, human);
    if (moves.size() == 0 || is_over(board, AI, human) != 0)
    {
       best_score = is_over(board, AI, human);
        return std::make_pair(best_score, best_move);
    }

    for (auto move : moves)
    {
        board[move.first][move.second] = marker;

        // Maximizing player's turn
        if (marker == AI)
        {
            int score = minimax_optimization(board, human, alpha, beta, AI, human).first;
            board[move.first][move.second] = 0;

            if (best_score < score)
            {
                best_score = score;
                best_move = move;
                alpha = std::max(alpha, best_score);
                if (beta <= best_score)
                    break;
            }
        }
        // Minimizing opponent's turn
        else
        {
            int score = minimax_optimization(board, AI, alpha, beta, AI, human).first;
            board[move.first][move.second] = 0;

            if (best_score > score)
            {
                best_score = score;
                best_move = move;
                beta = std::min(beta, best_score);
                if (best_score <= alpha)
                    break;
            }
        }
    }

    return std::make_pair(best_score, best_move);
}
