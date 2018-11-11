#include "stdafx.h"
#include "standard.h"
#include "tictactoe.h"
#include "gamebase.h"
#include "gomoku.h"

//prompts user for input
int GameBase::prompt(unsigned int & x, unsigned int &y) {
	cout << "Type quit or 'x-coordinate,y-coordinate' to continue playing: " << endl;
	string input;
	//get user input
	getline(cin, input);
	if (input == "quit") {
		throw quit;
	}
	unsigned int max = getMax();
	int maxlength = (to_string(max).length()*2)+1;
	if (((int)input.length() <=maxlength)&&((int)input.length()>=3)) {
		size_t position = input.find(",");
		if (position != string::npos) {	
			if (input.find(",", position + 1) == string::npos) {
				input.replace(position, 1, " ");
			}
			else {
				cout << "Invalid Input" << endl;
				return prompt(x, y);
			}
		}
		else {
			cout << "Invalid Input" << endl;
			return prompt(x, y);
		}
		//get the two numbers from the string
		istringstream iss(input);
		iss >> x;
		iss >> y;
		//checks if the coordinates are valid, reprompts if it isn't
		if (x > max || x < 1 || y>max || y < 1) {
			cout << "Input out of range" << endl;
			return prompt(x, y);
		}
		//checks if piece exists
		if (isValid(x,y)) {
			cout << "Piece already there!" << endl;
			return prompt(x, y);
		}
	}
	else {
		cout << "Invalid Input" << endl;
		return prompt(x, y);
	}
	return success;
}
//starts playing the game
int GameBase::play() {
	print();
	bool playing = true;
	while (playing) {
		int turns = turn();
		if (turns == success) {
			//if done is true, then print out the winner
			Player winner = done();
			if (winner!=no_player) {
				string win = getNames(winner);
				num_moves = getTurns();
				cout << "Winner is " << win << "!" << endl;
				cout << "Number of moves: " << num_moves << endl;
				playing = false;
			}
			//if there are no more valid moves, print out Draw!
			if (draw()) {
				num_moves = getTurns();
				playing = false;
				cout << "Number of moves: " << num_moves << endl;
				throw game_draw;
			}
			
		}
		else {
			return turns;
		}
	}
	return success;
}
//checks the arguments and returns a pointer to a game if it is correct, otherwise throws an argument error
GameBase* GameBase::start(int a, char* b[]) {
	//constructs default game
	if (a == 2) {
		if (strcmp(b[file_input], "TicTacToe") == 0) {
			GameBase *g = new TicTacToe();
			return g;
		}
		if (strcmp(b[file_input], "Gomoku") == 0) {
			GameBase *g = new Gomoku();
			return g;
		}
		throw argument_error;
	}
	//if board dimensions are entered, checks and constructs new game board
	if (a == 3) {
		if (strcmp(b[file_input], "Gomoku") == 0) {
			istringstream iss(b[dimension_input]);
			int dimensions = -1;
			iss >> dimensions;
			if (to_string(dimensions).length() != strlen(b[dimension_input])) {
				throw dim_error;
			}
			if (dimensions < 1) {
				throw dim_error;
			}
			if (dimensions >= 1 && dimensions<=5) {
				GameBase *g = new Gomoku(dimensions, dimensions);
				return g;
			}
			if (dimensions > 5) {
				GameBase *g = new Gomoku(dimensions, 5);
				return g;
			}
		}
	}
	//if board dimensions and win count are entered, check validity and construct new game board
	if (a == 4) {
		if (strcmp(b[file_input], "Gomoku") == 0) {
			istringstream iss(b[dimension_input]);
			int dimensions = -1;
			iss >> dimensions;
			istringstream iss2(b[win_count_input]);
			int wins = -1;
			iss2 >> wins;
			if (to_string(dimensions).length() != strlen(b[dimension_input])) {
				throw dim_error;
			}
			if (to_string(wins).length() != strlen(b[win_count_input])) {
				throw wins_error;
			}
			if (dimensions < 1&&wins<1) {
				throw dimwins_error;
			}
			if (dimensions < 1) {
				throw dim_error;
			}
			if (wins < 1) {
				throw wins_error;
			}
			if (wins > dimensions) {
				throw incorrect_dimensions;
			}
			GameBase *g = new Gomoku(dimensions, wins);
			return g;
			
		}
	}
	throw argument_error;
}

