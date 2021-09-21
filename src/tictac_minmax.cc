#include <tictac_support.h>
#include <bits/stdc++.h>

// Get all available moves
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

// Check the board is full or not
bool is_full(int board[][3], int &AI, int &human)
{
    std::vector<std::pair<int, int>> moves = get_moves(board, AI, human);
    return 0 == moves.size();
}

// check if marker is winner
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

// Check if someone has won or lost
int is_over(int board[][3], int &AI, int &human)
{
    return is_winner(board, AI) ? 999 : (is_winner(board, human) ? -999 : 0);
}

// minmax algo with pruning
std::pair<int, std::pair<int, int>> minimax_optimization(int board[][3], int marker, int alpha, int beta, int &AI, int &human)
{
    // Initialize best move
    std::pair<int, int> best_move = std::make_pair(-1, -1);
    int best_score = (marker == AI) ? -999 : 999;

    // If we hit a terminal state (leaf node), return the best score and move
    if (is_full(board, AI, human) || is_over(board, AI, human) != 0)
    {
        best_score = is_over(board, AI, human);
        return std::make_pair(best_score, best_move);
    }

    std::vector<std::pair<int, int>> moves = get_moves(board, AI, human);

    for (int i = 0; i < moves.size(); i++)
    {
        std::pair<int, int> move = moves[i];
        board[move.first][move.second] = marker;

        // Maximizing player's turn
        if (marker == AI)
        {
            int score = minimax_optimization(board, human, alpha, beta, AI, human).first;
            if (best_score < score)
            {
                best_score = score;
                best_move = move;
                alpha = std::max(alpha, best_score);
                board[move.first][move.second] = 0;
                if (beta <= alpha)
                    break;
            }

        } // Minimizing opponent's turn
        else
        {
            int score = minimax_optimization(board, AI, alpha, beta, AI, human).first;

            if (best_score > score)
            {
                best_score = score;
                best_move = move;
                beta = std::min(beta, best_score);
                board[move.first][move.second] = 0;
                if (beta <= alpha)
                    break;
            }
        }

        board[move.first][move.second] = 0;
    }

    return std::make_pair(best_score, best_move);
}
