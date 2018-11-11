#include "stdafx.h"
#include "standard.h"
#include "tictactoe.h"
#include "gamebase.h"
//prints out the board
void TicTacToe::print() {
	cout << *this << endl;
}
//constructor
TicTacToe::TicTacToe() {
	initialize();
}
//initialize the board with empty pieces and empty player
void TicTacToe::initialize() {
	for (int i = 0;i < 5;++i) {
		for (int j = 0;j < 5;++j) {
			gameboard[i][j].piece = "";
			gameboard[i][j].player = no_player;
		}
	}
}
//checks if a gameboard spot is valid
bool TicTacToe::isValid(unsigned int &x, unsigned int &y) {
	return gameboard[x][y].player != no_player;
}
//returns the player name based on player
string TicTacToe::getNames(Player player) {
	if (player == playerone) {
		return "Player X";
	}
	if (player == playertwo) {
		return "Player O";
	}
	return "";
}
//prints out the TicTacToe game board
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
int TicTacToe::getMax() {
	return 3;
}
//checks if there are three consecutive game pieces from the same player. Returns the winner if there is
Player TicTacToe::done() {
	for (int i = 1;i < 4;++i) {
		if (gameboard[i][3].player == gameboard[i][2].player&&gameboard[i][2].player == gameboard[i][1].player&&gameboard[i][3].player != no_player) {
			winner = gameboard[i][3].player;
			return winner;
		}
		if (gameboard[1][i].player == gameboard[2][i].player&&gameboard[2][i].player == gameboard[3][i].player&&gameboard[1][i].player != no_player) {
			winner = gameboard[1][i].player;
			return winner;
		}
	}
	if (gameboard[1][3].player == gameboard[2][2].player&&gameboard[2][2].player == gameboard[3][1].player&&gameboard[1][3].player != no_player) {
		winner = gameboard[1][3].player;
		return winner;
	}
	if (gameboard[1][1].player == gameboard[2][2].player&&gameboard[2][2].player == gameboard[3][3].player&&gameboard[1][1].player != no_player) {
		winner = gameboard[3][3].player;
		return winner;
	}
	return no_player;
}
//counts up the empty player slots. If there are none left, returns true, meaning there are no more moves left
bool TicTacToe::draw() {
	if (done()) {
		return false;
	}
	TicTacToe newBoard;
	int count = 0;
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
//returns the number of moves made
unsigned int TicTacToe::getTurns() {
	return num_moves;
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
			player1_moves += "(" + toString(x) + "," + toString(y) + "); ";
			cout << *this << endl;
			cout << player1_moves << endl;
			cout << player2_moves << endl;
			++num_moves;
			return success;
		}
		else {
			return pro;
		}
	}
	//same as above
	else if (num_moves % 2 == 1) {
		cout << "Player O's turn " << endl;
		int pro = prompt(x, y);
		if (pro == 0) {
			gameboard[x][y].player = playertwo;
			gameboard[x][y].piece = "O";
			player2_moves += "(" + toString(x) + "," + toString(y) + "); ";
			cout << *this << endl;
			cout << player1_moves << endl;
			cout << player2_moves << endl;
			++num_moves;
			return success;
		}
		else {
			return pro;
		}
	}
	return success;
}
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
	return "";
}