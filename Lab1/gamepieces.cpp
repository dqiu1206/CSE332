//provides functions to allow switching between string and enum
#include "stdafx.h"
#include "gamepieces.h"
#include "standard.h"
#include "gameboard.h"
//converts the piece color to a string
string color_toString(piece_color color) {
	if (color == red) {
		return "red";
	}
	else if (color == black) {
		return "black";
	}
	else if (color == white) {
		return "white";
	}
	else if (color == blue) {
		return "blue";
	}
	else if (color == nocolor) {
		return "no color";
	}
	else {
		return "invalid color";
	}
}
//converts the string from the text to the piece color enum
piece_color string_toColor(string& strs) {
	lowercase(strs);
	if (strs == "red") {
		return red;
	}
	else if (strs == "white") {
		return white;
	}
	else if (strs == "blue") {
		return blue;
	}
	else if (strs == "black") {
		return black;
	}
	else if (strs == " " || strs == "no color") {
		return nocolor;
	}
	else {
		return invalid;
	}
}
