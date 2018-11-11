// Lab1.cpp : Defines the entry point for the console application.
//Author:David Qiu (437405)
//Lab 1
#include "stdafx.h"
#include "standard.h"
#include "gamepieces.h"
#include "gameboard.h"
//main function: inputs text file and prints out game board
int main(int argc, char * argv[])
{	
	//create space game piece
	game_piece default;
	default.color = nocolor;
	default.name = "";
	default.display = " ";
	//checks if there are only 2 arguments
	if (argc != argument_input) {
		return usage(argv[program_input], " <input_file_name>"); //calls usage function to print usage message	
	}

	//opens file and runs if there is a valid file
	ifstream ifs(argv[file_input]);
	if (ifs.is_open()) {
		unsigned int width = 0;
		unsigned int height = 0;
		//reads every line of the file until there are two integer numbers, which represent the dimensions
		int dim = read_dimension(ifs, width, height);
		if (dim == file_open_error) {
			cout << "No dimensions found" << endl;
			return get_dimension_error;
		}
		while (dim != success) {
			dim = read_dimension(ifs, width, height);
			if (dim == file_open_error) {
				cout << "No dimensions found" << endl;
				return get_dimension_error;
			}
		}
		//create vector of game pieces
		vector<game_piece> board;
		//populate vector with game pieces that are set to a default space
		for (size_t i = 0;i <(width*height);++i) {
			board.push_back(default);
		}
		//reads the file and replaces black pieces with pieces described in file
		int read =  read_pieces(ifs, board, width, height);
		//error message if read is not successful
		if (read != success) {
			cout << "Cannot read pieces" << endl;
			return no_piece_error;
		}
		//prints out the pieces and outputs success if it works
		ifs.close();
		return print_pieces(board, width, height);
	
	}
	//error for file opening
	else {
		cout << "Cannot open file" << endl;
		return file_open_error;
	}
}


