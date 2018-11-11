#ifndef LAB0
#define LAB0
#include <vector>
#include <string>

//enumeration of inputs
enum inputs {program_input,
	file_input,
	argument_input};
//enumeration of success and errors possible
enum output {
	success,
	argument_error = -1,
	file_open_error = -2,
	parse_error = -3
};

int usage(char* program_name);
int parse(char * file_name, std::vector<std::string> & string_parse);

#endif