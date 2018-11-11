//header for the gameboard
#ifndef gameboard
#define gameboard
#include "gamepieces.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
int read_pieces(ifstream &stream, vector<game_piece> &position, unsigned int &row, unsigned int &col);
int read_dimension(ifstream &stream, unsigned int &width, unsigned int&height);
int print_pieces(const vector<game_piece> &pieces, unsigned int width, unsigned int height);
#endif