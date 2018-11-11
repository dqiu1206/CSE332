// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "standard.h"
#include "tictactoe.h"
#include "gamebase.h"
#include "gomoku.h"
//starts a game
int main(int argc, char * argv[])
{
	try {
		GameBase *gb = GameBase::start(argc, argv);
		int result = gb->play();
		return result;
	}
	catch (output e) {
		if (e == quit) {
			cout << "Player Quit!" << endl;
		}
		if (e == argument_error) {
			return usage(argv[program_input], " gamename {board_dim} {win_count}");
		}
		if (e == game_draw) {
			cout << "Stalemate!" << endl;
		}
		if (e == incorrect_dimensions) {
			cout << "Dimensions must be greater than or equal to win count!" << endl;
		}
		if (e == dim_error) {
			cout << "Dimensions must be a number greater than 0!" << endl;
		}
		if (e == wins_error) {
			cout << "Win count must be a number greater than 0!" << endl;
		}
		if (e == dimwins_error) {
			cout << "Dimensions and Wins must be a number greater than 0!" << endl;
		}
		return e;
	}
}

