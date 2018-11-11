//header for game pieces and provides enum values for piece color and a struct for game_piece
#ifndef gamepieces
#define gamepieces
#include <string>
#include <iostream>
using namespace std;
//enumeration of inputs
enum piece_color {
	invalid,
	nocolor,
	red,
	black,
	blue,
	white
};
//creates game_piece struct
struct game_piece {
	piece_color color;
	string name;
	string display;
};
string color_toString(piece_color color);
piece_color string_toColor(string& str);
#endif