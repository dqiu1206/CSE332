//standard template header for inputs and errors
#ifndef standard
#define standard
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;
//enumeration of inputs
enum inputs {
	program_input,
	file_input,
	argument_input
};
//enumeration of success and errors possible
enum output {
	success,
	argument_error = -1,
	file_open_error = -2,
	parse_error = -3,
	get_line_error = -4,
	get_dimension_error = -5,
	no_piece_error = -6,
	piece_overflow_error = -7,
	print_piece_error = -8,
	quit = -9
};
int usage(char* program_name, string error);
int parse(char * file_name, vector<string> & string_parse);
void lowercase(string& str);
#endif