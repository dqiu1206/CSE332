// Lab0.cpp : Defines the entry point for the console application.
//Author:David Qiu (437405)
//Lab 0
//Parse text file and outputs strings followed by integers

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Lab0.h"

using namespace std;
//prints out usage message
int usage(char* program_name) {
	cout << "Usage: "<<program_name<<" <input_file_name>" << endl;
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

//main function: inputs file to be read and outputs strings followed by only integers
int main(int argc, char * argv[])
{
	//checks if there are only 2 arguments
	if (argc!=argument_input) {
		return usage(argv[program_input]); //calls usage function to print usage message	
	}
	vector<string> string_parse;
	//parses string and checks if it succeeded, move on if it did
	int check_parse = parse(argv[file_input], string_parse);
	if (check_parse != success) {	
		return file_open_error;
	}
	vector<int> only_number;	
	//iterates through each string in vector
	for (size_t i = 0;i < string_parse.size();++i) {
		bool isDigits = true; 
		string ind_string = string_parse.at(i); //create temp string
		//iterate through each character of the string
		for (size_t j = 0;j < ind_string.length();++j) {
			char c = ind_string[j];
			if (isdigit(c) == 0) {
				isDigits = false; //set isDigits to false if there are any non-integers				
			}
		}
		if (!isDigits) {	
			cout << ind_string << endl; //prints out string if there are any non-integers
		}
		else { //pushes strings with only numbers into vector
			int push;
			istringstream digits(ind_string); //create stream of string with only digits
			digits >> push; //insert into integer
			only_number.push_back(push); //push into vector
		}
	}
	//prints out digits vector
	for (size_t i = 0;i < only_number.size();++i) {
		cout << only_number[i] << endl;
	}
    return success;
}


