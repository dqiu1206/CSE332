// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "standard.h"
#include "tictactoe.h"

//starts a game
int main(int argc, char * argv[])
{
	string tic = "TicTacToe";
	if (argc != argument_input||argv[file_input]!=tic) {
		return usage(argv[program_input], " TicTacToe"); //calls usage function to print usage message	
	}
	TicTacToe game;
	int plays =game.play();
	if (plays = quit) {
		cout << "Player Quit" << endl;
		return quit;
	}
	return plays;
}

