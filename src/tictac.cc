#include <tictac_support.h>
#include <bits/stdc++.h>

void print_usage()
{
	std::cout << "\nUsage: " << std::endl;
	std::cout << "\t./tictactoe [inputFile] [outputFile] [--play]\n";
	std::cout << "\nOptions:\n\n";
	std::cout << "\tinputFile: \n\t\tname of the input file with the initial state of the board." << std::endl;
	std::cout << "\toutputFile: \n\t\tname of the output file to save the final state of the board." << std::endl;
	std::cout << "\t--play: \n\t\tto play interactively with AI." << std::endl;
}

int main(int argc, char *argv[])
{
	int board[3][3] = {0}, x, y;
	if (argc == 1)
	{
		std::string s = "n";
		if (argc == 1)
		{
			print_usage();
			std::cout << "\nDo you still want to play from the ZERO state? (y/n): ";
			std::cin >> s;
		}
		if (s == "yes" || s == "y" || s == "YES" || s == "Yes")
		{
			make_move(board, true);
		}
	}
	else
	{
		std::string play = "no";
		if (argc > 3)
			play = argv[3];

		// load in current board state
		load_board(argv[1], board);

		// make move
		int isFinished = make_move(board, play == "--play");

		if (!isFinished)
		{
			std::cout << "Something is wrong! Or Terminated by user.\n";
		}

		// save board state
		save_board(argv[2], board);
	}
	return 0;
}
