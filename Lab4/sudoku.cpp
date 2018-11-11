#include "stdafx.h"
#include "standard.h"
#include "sudoku.h"
#include "gamebase.h"
#include <algorithm>
//prints out Sudoku board
void Sudoku::print() {
	cout << *this << endl;
}
//constructor
Sudoku::Sudoku() {
	initialize();
	string name = game_name + ".txt";
	//checks if save file exists, if not, creates one
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
	//checks if there is a save file or not. If there is checks if save file is correctly formatted, starts new game if not.
	ifstream ifs2(name);
	if (ifs2.is_open()) {
		int count = 0;
		bool keepGoing = true;
		string file_board[10];
		while (getline(ifs2, file_board[count])&&keepGoing&&count<9) {
			if (file_board[0] == "NONE") {
				initialize();
				keepGoing = false;
			}
			count++;
		}
		string test;
		if (getline(ifs2, test)) {
			cout << "Save File incorrectly formatted. Starting new game." << endl;
			initialize();
		}
		if (count == 9) {
			int set_return = setBoard(file_board);
			if (set_return == file_read_error) {
				cout << "Save File incorrectly formatted. Starting new game." << endl;
				initialize();
			}
		}

	}
}
//helper
string Sudoku::toString(int a) {
	if (a == 1) {
		return "1";
	}
	if (a == 2) {
		return "2";
	}if (a == 3) {
		return "3";
	}if (a == 4) {
		return "4";
	}if (a == 5) {
		return "5";
	}if (a == 6) {
		return "6";
	}if (a == 7) {
		return "7";
	}if (a == 8) {
		return "8";
	}if (a == 9) {
		return "9";
	}
}
//sets the board from the save file
int Sudoku::setBoard(string file_board[]) {
	initialize();
	for (int y = 0;y <9;++y) {
		string get = file_board[y];
		istringstream iss(get);
		for (int x = 0;x <9;++x) {
			int var;
			iss >> var;
			if (var < 0 || var>9 ) {
				return file_read_error;
			}
			if (iss.fail()) {
				return file_read_error;
			}
			if (var == 0) {
				sudoku_set("N", x, y);
			}
			else {
				string set = toString(var);
				sudoku_set(set, x, y);
			}

		}
	}
	return success;
}
//initialize the board
void Sudoku::initialize() {
	for (int i = 0;i < 9;++i) {
		for (int j = 0;j < 9;++j) {
			gameboard[i][j].piece = " ";
			gameboard[i][j].player = no_player;
			gameboard[i][j].number = 0;
		}
	}
}
//checks if board spot is valid
bool Sudoku::isValid(unsigned int &x, unsigned int &y) {
	if (given[x][y].player == no_player) {
		return true;
	}
	return false;
}
//prints out the board
ostream & operator<< (ostream& os, const Sudoku& game) {
	for (int y = 8;y >= 0;--y) {
		for (int x = 0;x <= 8;++x) {
			if (x == 0) {
				os << y << "||" << game.gameboard[x][y].piece << "|";
			}
			else {
				if (x == 2 || x == 5 || x == 8) {
					os << game.gameboard[x][y].piece << "||";
				}
				else {
					os << game.gameboard[x][y].piece << "|";
				}
			}

		}
		os << endl;
		if (y == 6 || y == 3) {
			os << "=||=|=|=||=|=|=||=|=|=||" << endl;
		}
		if (y != 6 && y != 3 && y != 0) {
			os << "-||-|-|-||-|-|-||-|-|-||" << endl;
		}
		if (y == 0) {
			os << "=||=|=|=||=|=|=||=|=|=||" << endl;
			os << "#||0|1|2||3|4|5||6|7|8||" << endl;
		}
	}
	return os;
}
//checks if the player has won
Player Sudoku::done() {
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			if (gameboard[i][j].number == 0) {
				return no_player;
			}
		}
	}
	for (int x = 0;x < 9;x=x+3) {
		for (int y = 0;y < 9;y=y+3) {
			if (!squareWin(x, x + 2, y, y + 2)) {
				return no_player;
			}
		}
	}
	for (int x = 0;x < 9;x++) {
		if (!column_win(x)) {
			return no_player;
		}
	}
	return playerone;
}
//checks each 3x3 square
bool Sudoku::squareWin(int x_start,int x_end,int y_start, int y_end) {
	int array[9];
	int count = 0;
	for (int x = x_start;x <= x_end;x++) {
		for (int y = y_start;y <= y_end;y++) {
			array[count] = gameboard[x][y].number;
			count++;
		}
	}
	sort(array, array + 9);
	for (int i = 0;i < 9;i++) {
		if (array[i] != (i + 1)) {
			return false;
		}
	}
	return true;
}
//checks if each column and row is correct
bool Sudoku::column_win(int column) {
	int array[9];
	int array2[9];
	for (int y = 0;y < 9;y++) {
		array[y] = gameboard[column][y].number;
		array2[y] = gameboard[y][column].number;
	}
	sort(array, array + 9);
	sort(array2, array2 + 9);
	for (int i = 0;i < 9;i++) {
		if (array[i] != (i + 1)) {
			return false;
		}
		if (array2[i] != (i + 1)) {
			return false;
		}
	}
	return true;
}

unsigned int Sudoku::getTurns() {
	return num_moves;
}
string Sudoku::getGameName() {
	return "sudoku0";
}
//sets individual piece on the board
void Sudoku::sudoku_set(string file_board, unsigned int x, unsigned int y) {
	if (file_board == "N") {
		gameboard[x][y].number = 0;
		gameboard[x][y].piece = " ";
		gameboard[x][y].player = no_player;
	}
	else {
		int set;
		istringstream iss(file_board);
		iss >> set;
		gameboard[x][y].number = set;
		gameboard[x][y].piece = file_board;
		gameboard[x][y].player = playerone;
		given[x][y].number = set;
		given[x][y].piece = file_board;
		given[x][y].player = playerone;
	}
}
string Sudoku::getNames(Player player) {
	return "Player";
}
//sends game board formatted correctly to save the game
string Sudoku::getGameBoard() {
	string gameboard_pieces;
	for (int y = 0;y < 9;++y) {
		for (int x = 0;x < 9;++x) {
			if (gameboard[x][y].player == no_player) {
				gameboard_pieces += "0 ";
			}
			else {
				gameboard_pieces += gameboard[x][y].piece+" ";
			}
		}
		if (y != 8) {
			gameboard_pieces += "\n";
		}
	}
	return gameboard_pieces;
}
//lets player continuously play pieces until he wins or quits
int Sudoku::play() {
	bool playing = true;
	unsigned int x;
	unsigned int y;
	unsigned int number;
	while (playing) {
		int pro = prompt(x, y, number);
		if (pro == success) {
			string num_char = to_string(number);
			sudoku_set(num_char, x, y);
			Player winner = done();
			if (winner != no_player) {
				cout << "You won!" << endl;
				print();
				playing = false;
				saveGame(true);
			}
		}
	}
	return success;
}
int Sudoku::prompt(unsigned int &x,unsigned int &y, unsigned int &number) {
	print();
	cout << "Type quit or 'x-coordinate,y-coordinate,number' to continue playing: " << endl;
	string input;
	//get user input
	getline(cin, input);
	if (input == "quit") {
		string input2;
		cout << "Do you want to save?(input 'yes' to save or anything to restart)" << endl;
		getline(cin, input2);
		if (input2.compare("yes") == 0) {
			int save_success = saveGame(false);
			if (save_success == success) {
				throw save_games;
			}
		}
		else {
			int save_success = saveGame(true);
			if (save_success == success) {
				throw quit;
			}
		}
		throw quit;
	}
	unsigned int max = 8;

	if (input.length()==5) {
		size_t position = input.find(",");
		if (position != string::npos) { //position is found
			if (position==1) {
				size_t position2 = input.find(",", position + 1);
				if (position2 != string::npos&&position2==3) {
					input.replace(position, 1, " ");
					input.replace(position2, 1, " ");
				}
				else {
					cout << "Invalid Input" << endl;
					return prompt(x, y, number);
				}
			}
			else {
				cout << "Invalid Input" << endl;
				return prompt(x, y,number);
			}
		}
		else {
			cout << "Invalid Input" << endl;
			return prompt(x, y,number);
		}
		//get the two numbers from the string
		istringstream iss(input);
		iss >> x;
		iss >> y;
		iss >> number;
		//checks if the coordinates are valid, reprompts if it isn't
		if (x > max || x < 0 || y>max || y < 0) {
			cout << "Coordinates out of range" << endl;
			return prompt(x, y,number);
		}
		if (number < 1 || number>9) {
			cout << "Number input must be between 1 and 9";
			return prompt(x, y, number);
		}
		if (!isValid(x,y)) {
			cout << "Cannot place piece here" << endl;
			return prompt(x, y, number);
		}
	}
	else {
		cout << "Invalid Input" << endl;
		return prompt(x, y,number);
	}
	return success;
}
int Sudoku::turn() {
	return 0;
}
bool Sudoku::draw() { 
	return false;
}
int Sudoku::getMax() {
	return 8;
}