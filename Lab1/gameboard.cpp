//contains methods that read, populate and print out the game board
#include "stdafx.h"
#include "gamepieces.h"
#include "standard.h"
#include "gameboard.h"
//tries to find the dimension input in the text file
int read_dimension(ifstream& stream, unsigned int& width, unsigned int&height) {
	string str;
	bool dim = false;
	//opens stream and reads the first line
	if (stream.is_open()) {
		if (getline(stream, str)) {
			istringstream iss(str);
			//if there is both a width and a height, return true
			if (iss >> width) {
				if (iss >> height) {
					dim = true;
				}
			}	
		}
		//error for no more lines in text file
		else {
			cout << "Cannot read line from input stream" << endl;
			return get_line_error;
		}
	}
	//error for file opening
	else {
		cout << "Cannot open file" << endl;
		return file_open_error;
	}
	//returns success if program is able to pull a width and height
	if(dim) {
		return success;
	}
	//general error message
	else {
		cout << "Cannot extract board dimensions" << endl;
		return get_dimension_error;
	}
}
//inputs text file and reads line by line to get each game piece and inserts it into the vector
int read_pieces(ifstream &stream, vector<game_piece> &position, unsigned int &width, unsigned int &height) {
	string str;
	bool isPiece = false;
	//opens the stream and checks every line
	if (stream.is_open()) {
		while (getline(stream, str)) {
			istringstream iss(str);
			string color;
			string piece;
			string display;
			unsigned int hor;
			unsigned int vert;
			//checks in order of color, piece name, piece display, and it's coordinates
			if (iss >> color) {
				if (iss >> piece) {
					if (iss >> display) {
						if (iss >> hor) {
							if (iss >> vert) {
								//convert the string to the enum
								piece_color p = string_toColor(color);
								//runs only if the color is valid
								if (p != invalid) {
									//runs only if the coordinates are inside the game board
									if (hor < width) {
										if (vert < height) {
											//assigns the game piece to the vector and replacing the default piece
											unsigned index = vert*width + hor;
											game_piece pieces;
											pieces.color = p;
											pieces.name = piece;
											pieces.display = display;
											position[index] = pieces;
											//indicates that there was at least one piece read
											isPiece = true;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		stream.close();
	}
	//file opening error
	else {
		cout << "Cannot open file" << endl;
		return file_open_error;
	}
	//success if there is at least one piece read and inputted
	if (isPiece) {
		return success;
	}
	//error for if no valid game pieces are seen
	else {
		cout << "Cannot find valid game piece" << endl;
		return no_piece_error;
	}
}
//prints out the entire game board
int print_pieces(const vector<game_piece> &pieces, unsigned int width, unsigned int height) {
	if (pieces.size() > (width*height)) {
		cout << "Too many pieces" << endl;
		return piece_overflow_error;
	}
		for (size_t row = (height-1);row >= 0;--row) {
			for (size_t col = 0; col < width;++col) {
				unsigned int index = (row)*width + col;
				if (index < (height*width)) {
					if (col == (width - 1)) {
						cout << pieces[index].display << endl;
					}
					else {
						cout << pieces[index].display;
					}
				}
				else {
					return success;
				}
			}

		}
		return success;

}