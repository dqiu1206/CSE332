#include "stdafx.h"
#include "standard.h"
#include "gamebase.h"
#include "gomoku.h"

//prints out Gomoku board
void Gomoku::print() {
	cout << *this << endl;
}
Gomoku::Gomoku(int dimensions, int wins) {
	gameboard = new game_piece*[dimensions + 1];
	for (int i = 0;i < (dimensions + 1);++i) {
		gameboard[i] = new game_piece[dimensions + 1];
	}
	win_count = wins;
	max_dimensions = dimensions;
	string name = game_name + ".txt";
	ifstream ifs(name);
	if (!ifs.is_open()) {
		ofstream ofs(name);
		if (ofs.is_open()) {
			ofs << "NONE" << endl;
		}
		else {
			throw file_open_error;
		}
	}
	ifstream ifs2(name);
	if (ifs2.is_open()) {
		string file_board;

		getline(ifs2, file_board);
		if (file_board == "NONE") {
			initialize();
		}
		else {
			int set_return = setBoard(file_board);
			if (set_return == file_read_error) {
				cout << "Save File incorrectly formatted. Starting new game." << endl;
				initialize();
			}
		}
		
	}
}
//constructor
Gomoku::Gomoku() {
	gameboard = new game_piece*[20];
	for (int i = 0;i < 20;i++) {
		gameboard[i] = new game_piece[20];
	}
	string name = game_name + ".txt";
	ifstream ifs(name);
	if (!ifs.is_open()) {
		ofstream ofs(name);
		if (ofs.is_open()) {
			ofs << "NONE" << endl;
		}
		else {
			throw file_open_error;
		}
	}
	ifstream ifs2(name);
	if (ifs2.is_open()) {
		string file_board;
		getline(ifs2, file_board);
		if (file_board == "NONE") {
			initialize();
		}
		else {
			int set_return = setBoard(file_board);
			if (set_return == file_read_error) {
				cout << "Save File incorrectly formatted. Starting new game." << endl;
				initialize();
			}
		}
		

	}
}
//sets the board from the save file
int Gomoku::setBoard(string file_board) {
	initialize();
	if (file_board.length() != (max_dimensions*max_dimensions)) {
		return file_read_error;
	}
	int count = 0;
	for (int x = 1;x <= max_dimensions;x++) {
		for (int y = 1;y <= max_dimensions;y++) {
			if (file_board[count] == 'B') {
				gameboard[x][y].piece = "B";
				gameboard[x][y].player = playerone;
			}
			else if (file_board[count] == 'W') {
				gameboard[x][y].piece = "W";
				gameboard[x][y].player = playertwo;
			}
			else if (file_board[count] == 'N') {
				gameboard[x][y].piece = "";
				gameboard[x][y].player = no_player;
			}
			else {
				return file_read_error;
			}
			count++;
		}
	}
	return success;
}
//initialize the board with empty pieces and empty player
void Gomoku::initialize() {
	for (int i = 0;i <= max_dimensions;++i) {
		for (int j = 0;j <= max_dimensions;++j) {
			gameboard[i][j].piece = "";
			gameboard[i][j].player = no_player;
		}
	}
}
//checks if board spot is valid
bool Gomoku::isValid(unsigned int &x, unsigned int &y) {
	return gameboard[x][y].player != no_player;
}
//returns max dimensions
int Gomoku::getMax() {
	return max_dimensions;
}
//prints out the board with pieces
ostream & operator<< (ostream& os, const Gomoku& game) {
	for (int y = game.max_dimensions;y >= 0;--y) {
		for (int x = 0;x <= game.max_dimensions;++x) {
			//adds spaces based on the x-dimension number length
			int length = to_string(x).length();
			string addon = "";
			for (int i = 0;i < length - 1;i++) {
				addon += " ";
			}
			if (y == 0) {
				if (x != 0) {
					os << x;
				}
				else {
					os << "X";
				}
			}
			else {
				if (x == 0) {
					os << y;
				}
				else {
					if (game.gameboard[x][y].player == no_player) {
						os << " " + addon;

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
//checks if there are n consecutive game pieces from the same player. Returns the winner if there is
Player Gomoku::done() {
	Player winner = no_player;
	winner = horizontal_win();
	if (winner != no_player) {
		return winner;
	}
	winner = vertical_win();
	if (winner != no_player) {
		return winner;
	}
	winner = diagonal_win();
	if (winner != no_player) {
		return winner;
	}

	return no_player;
}
//returns the player name
string Gomoku::getNames(Player player) {
	if (player == playerone) {
		return "Player B";
	}
	if (player == playertwo) {
		return "Player W";
	}
	return "";
}
//checks diagonal win based on specified win count
Player Gomoku::diagonal_win() {
	int max = 1;
	int count = 0;
	int ypos = 0;
	int xpos = 0;
	Player current = no_player;
	for (int y = max_dimensions;y >= 1;--y) {
		++max;
		count = 0;
		ypos = 0;
		for (int x = 1;x < max;++x) {
			if (gameboard[x][y + ypos].player == no_player) {
				count = 0;
				current = no_player;
			}
			if (gameboard[x][y + ypos].player != no_player) {
				if (gameboard[x][y + ypos].player == current) {
					++count;
				}
				else {
					count = 1;
					current = gameboard[x][y + ypos].player;
				}
			}
			if (count == win_count) {
				return current;
			}
			++ypos;
		}
	}

	current = no_player;
	for (int x = 2;x <= max_dimensions;++x) {
		--max;
		count = 0;
		xpos = 0;
		for (int y = 1;y < max;++y) {
			if (gameboard[x + xpos][y].player == no_player) {
				count = 0;
				current = no_player;
			}
			if (gameboard[x + xpos][y].player != no_player) {
				if (gameboard[x + xpos][y].player == current) {
					++count;
				}
				else {
					count = 1;
					current = gameboard[x + xpos][y].player;
				}
			}
			if (count == win_count) {
				return current;
			}
			xpos++;
		}
	}
	current = no_player;
	int min = max_dimensions;
	count = 0;
	ypos = 0;
	xpos = 0;
	for (int y = max_dimensions;y >= 1;--y) {
		--min;
		count = 0;
		ypos = 0;
		for (int x = max_dimensions;x >min;--x) {
			if (gameboard[x][y + ypos].player == no_player) {
				count = 0;
				current = no_player;
			}
			if (gameboard[x][y + ypos].player != no_player) {
				if (gameboard[x][y + ypos].player == current) {
					++count;
				}
				else {
					count = 1;
					current = gameboard[x][y + ypos].player;
				}
			}
			if (count == win_count) {
				return current;
			}
			++ypos;
		}
	}
	current = no_player;
	for (int x = max_dimensions - 1;x >= 1;--x) {
		count = 0;
		xpos = 0;
		for (int y = 1;y <= x;++y) {
			if (gameboard[x - xpos][y].player == no_player) {
				count = 0;
				current = no_player;
			}
			if (gameboard[x - xpos][y].player != no_player) {
				if (gameboard[x - xpos][y].player == current) {
					++count;
				}
				else {
					count = 1;
					current = gameboard[x - xpos][y].player;
				}
			}
			if (count == win_count) {
				return current;
			}
			++xpos;
		}
	}
	return no_player;
}
//checks horizontal win based on specified win count
Player Gomoku::horizontal_win() {
	bool win = false;
	int count = 0;
	Player current = no_player;
	for (int y = 1;y <= max_dimensions;y++) {
		count = 0;
		for (int x = 1;x <= max_dimensions;x++) {
			if (gameboard[x][y].player == no_player) {
				count = 0;
				current = no_player;
			}
			if (gameboard[x][y].player != no_player) {
				if (gameboard[x][y].player == current) {
					++count;
				}
				else {
					count = 1;
					current = gameboard[x][y].player;
				}
			}
			if (count == win_count) {
				return current;
			}
		}
	}
	return no_player;
}
//checks vertical win based on specified win count
Player Gomoku::vertical_win() {
	bool win = false;
	int count = 0;
	Player current = no_player;
	for (int x = 1;x <= max_dimensions;++x) {
		count = 0;
		for (int y = 1;y <= max_dimensions;++y) {
			if (gameboard[x][y].player == no_player) {
				count = 0;
				current = no_player;
			}
			if (gameboard[x][y].player != no_player) {
				if (gameboard[x][y].player == current) {
					++count;
				}
				else {
					count = 1;
					current = gameboard[x][y].player;
				}
			}
			if (count == win_count) {
				return current;
			}
		}
	}
	return no_player;
}
string Gomoku::getGameBoard() {
	string gameboard_pieces;
	for (int x = 1;x <= max_dimensions;++x) {
		for (int y = 1;y <= max_dimensions;++y) {
			if (gameboard[x][y].player == no_player) {
				gameboard_pieces += "N";
			}
			else {
				gameboard_pieces += gameboard[x][y].piece;
			}
		}
	}
	return gameboard_pieces;
}
//checks if a win condition is possible
bool Gomoku::draw() {
	int count = 0;
	for (int i = 1;i <= max_dimensions;++i) {
		for (int j = 1;j <= max_dimensions;++j) {
			if (gameboard[i][j].player == no_player) {
				count++;
			}
		}
	}
	if (count >= win_count) {
		return false;
	}
	//check playerone
	Gomoku *newBoard = new Gomoku();
	Gomoku &board = *newBoard;
	Gomoku *newBoard2 = new Gomoku();
	Gomoku &board2 = *newBoard2;
	for (int i = 1;i <= max_dimensions;++i) {
		for (int j = 1;j <= max_dimensions;++j) {
			board.gameboard[i][j].player = gameboard[i][j].player;
			board2.gameboard[i][j].player = gameboard[i][j].player;
		}
	}
	for (int i = 1;i <= max_dimensions;++i) {
		for (int j = 1;j <= max_dimensions;++j) {
			if (board.gameboard[i][j].player == no_player) {
				board.gameboard[i][j].player = playerone;
			}
			if (board2.gameboard[i][j].player == no_player) {
				board2.gameboard[i][j].player = playertwo;
			}
		}
	}
	Player win1 = board.done();
	Player win2 = board2.done();
	if (win1 == no_player || win2 == no_player) {
		return true;
	}

	return false;
}
//returns the number of moves made so far
unsigned int Gomoku::getTurns() {
	return num_moves;
}
//starts player turn
int Gomoku::turn() {
	unsigned int x;
	unsigned int y;
	//if the move is even, start player X's turn, otherwise, start player O's
	if (num_moves % 2 == 0) {
		cout << "Player B's turn " << endl;
		//call prompt and check if it succeeded
		int pro = prompt(x, y);
		if (pro == 0) {
			//place pieces onto the board and prints out the board and previous moves
			gameboard[x][y].player = playerone;
			int length = to_string(x).length();
			string addon = "";
			for (int i = 0;i < length - 1;i++) {
				addon += " ";
			}
			gameboard[x][y].piece = "B" + addon;
			player1_moves += "(" + to_string(x) + "," + to_string(y) + "); ";
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
		cout << "Player W's turn " << endl;
		int pro = prompt(x, y);
		if (pro == 0) {
			gameboard[x][y].player = playertwo;
			int length = to_string(x).length();
			string addon = "";
			for (int i = 0;i < length - 1;i++) {
				addon += " ";
			}

			gameboard[x][y].piece = "W" + addon;

			player2_moves += "(" + to_string(x) + "," + to_string(y) + "); ";
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
string Gomoku::getGameName() {
	return "Gomoku";
}
