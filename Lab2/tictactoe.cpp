#include "stdafx.h"
#include "standard.h"
#include "tictactoe.h"
//initialize the board with empty pieces and empty player
void TicTacToe::initialize() {
	for (int i = 0;i < 5;++i) {
		for (int j = 0;j < 5;++j) {
			gameboard[i][j].piece = "";
			gameboard[i][j].player = no_player;
		}
	}
}
//prints out the board with pieces
ostream & operator<< (ostream& os, const TicTacToe& game) {
	for (int y = 4;y >= -1;--y) {
		for (int x = -1;x < 5;++x) {
			if (y == -1) {
				if (x != -1) {
					os << x;
				}
				else {
					os << " ";
				}
			}
			else {
				if (x == -1) {
					os << y;
				}
				else {
					if (game.gameboard[x][y].player == no_player) {
						os << " ";
					}
					else {
						os << game.gameboard[x][y].piece;
					}

				}
			}
			os << " ";
		}
		os << endl;
		os << endl;
	}
	return os;
}
//checks if there are three consecutive game pieces from the same player. Returns true if there is
bool TicTacToe::done() {
	for (int i = 1;i < 4;++i) {
		if (gameboard[i][3].player == gameboard[i][2].player&&gameboard[i][2].player == gameboard[i][1].player&&gameboard[i][3].player!=no_player) {
			winner = gameboard[i][3].player;
			return true;
		}
		if (gameboard[1][i].player == gameboard[2][i].player&&gameboard[2][i].player == gameboard[3][i].player&&gameboard[1][i].player != no_player) {
			winner = gameboard[1][i].player;
			return true;
		}
	}
	if (gameboard[1][3].player == gameboard[2][2].player&&gameboard[2][2].player == gameboard[3][1].player&&gameboard[1][3].player != no_player) {
		winner = gameboard[1][3].player;
		return true;
	}
	if (gameboard[1][1].player == gameboard[2][2].player&&gameboard[2][2].player == gameboard[3][3].player&&gameboard[1][1].player != no_player) {
		winner = gameboard[3][3].player;
		return true;
	}
	return false;
}
//counts up the empty player slots. If there are none left, returns true, meaning there are no more moves left
bool TicTacToe::draw() {
	if (done()) {
		return false;
	}

	TicTacToe newBoard;
	int count = 0;
	int x[2];
	int y[2];
	int xs;
	int ys;
	for (int i = 1;i < 4;++i) {
		for (int j = 1;j < 4;++j) {
			newBoard.gameboard[i][j] = gameboard[i][j];
			if (gameboard[i][j].player == no_player) {
				++count;
			}
		}
	}
	if (count == 0) {
		return true;
	}

	return false;
}
//prompts user for input
int TicTacToe::prompt(unsigned int & x, unsigned int &y) {
	cout << "Type quit or 'x-coordinate,y-coordinate' to continue playing: " << endl;
	string input;
	//get user input
	getline(cin, input);
	if (input == "quit") {
		return quit;
	}
	//checks if there are only three input characters
	if (input.length() == 3) {
		//finds the comma and replaces it with a space. Checks the comma is in correct position
		size_t position = input.find(",");
		if (position != string::npos&&position==1) {
			input.replace(position, 1, " ");
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
		if (x > 3 || x < 1 || y>3 || y < 1) {
			cout << "Input out of range" << endl;
			return prompt(x, y);
		}
		//checks if piece exists
		if (gameboard[x][y].player != no_player) {
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
//starts player turn
int TicTacToe::turn() {
	unsigned int x;
	unsigned int y;
	//if the move is even, start player X's turn, otherwise, start player O's
	if (num_moves % 2 == 0) {
		cout << "Player X's turn " << endl;
		//call prompt and check if it succeeded
		int pro = prompt(x, y);
		if (pro == 0) {
			//place pieces onto the board and prints out the board and previous moves
			gameboard[x][y].player = playerone;
			gameboard[x][y].piece = "X";
			x_moves += "(" + toString(x) + "," + toString(y) + "); ";
			cout << *this << endl;
			cout << x_moves << endl;
			++num_moves;
			return success;
		}
		else {
			return pro;
		}
		
	}
	//same as above
	else if(num_moves%2==1){
		cout << "Player O's turn " << endl;
		int pro = prompt(x, y);
		if (pro == 0) {
			gameboard[x][y].player = playertwo;
			gameboard[x][y].piece = "O";
			o_moves += "(" + toString(x) + "," + toString(y) + "); ";
			cout << *this << endl;
			cout << o_moves << endl;
			++num_moves;
			return success;
		}
		else {
			return pro;
		}
		
	}
	return success;

}
//starts the game off
int TicTacToe::play() {
	initialize();
	cout << *this << endl;
	bool playing = true;
	x_moves = "Player X: ";
	o_moves = "Player O: ";
	while (playing) {
		int turns = turn();
		if (turns == 0) {
			//if done is true, then print out the winner
			if (done()) {
				string win;
				if (winner == playerone) {
					win = "Player X";
				}
				else if (winner == playertwo) {
					win = "Player O";
				}
				cout << "Winner is " << win << "!" << endl;
				playing = false;
			}
			//if there are no more valid moves, print out Draw!
			if (draw()) {
				cout << "Draw! " << endl;
				playing = false;
			}
		}
		else {
			return turns;
		}
		
	}
	return success;


}
//helper to convert integer into string
string toString(int a) {
	if (a == 1) {
		return "1";
	}
	else if (a == 2) {
		return "2";
	}
	else if (a == 3) {
		return "3";
	}
	else if (a == 0) {
		return "0";
	}
}