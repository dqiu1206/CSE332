//standard functions used in all labs
#include "stdafx.h"
#include "standard.h"
#include "gamepieces.h"
#include "gameboard.h"
//prints out usage error
int usage(char* program_name,string error) {
	cout << "Usage: " << program_name << error << endl;
	return argument_error;
}

//parse text file and pushes it into a vector
int parse(char * file_name, vector<string> &string_parse) {
	//opens file
	ifstream ifs(file_name);
	string word;
	string line;
	//runs if the file is open
	if (ifs.is_open()) {

		while (getline(ifs, line)) { //gets each line of text file and stores into string, runs until no more text
			istringstream string_stream(line); //copies line into stream
			while (string_stream >> word) { //ignores white space then reads string into word
				string_parse.push_back(word); //pushes word into vector
			}
		}
		ifs.close();
	}
	else { //return error if file cannot open
		cout << "Cannot open file" << endl;
		return file_open_error;
	}
	return success;
}
//converts string into all lowercase
void lowercase(string& str) {
	for (size_t i = 0;i < str.length();++i) {
		str[i]=tolower(str[i]);
	}
}

