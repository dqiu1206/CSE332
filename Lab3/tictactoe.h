#ifndef tictactoe
#define tictactoe
#include "gamebase.h"


//Game class
class TicTacToe: public GameBase {
	game_piece gameboard[5][5];
	unsigned int num_moves = 0;
	string player1_moves = "Player X: ";
	string player2_moves = "Player O: ";
	Player winner;
	friend ostream & operator<< (ostream&, const TicTacToe&);
public:
	virtual Player done();
	virtual bool draw();
	virtual int turn();
	virtual void initialize();
	virtual void print() override;
	virtual unsigned int getTurns();
	virtual bool isValid(unsigned int &x, unsigned int &y);
	virtual int getMax();
	virtual string getNames(Player player);
	TicTacToe();
};
ostream & operator<< (ostream&, const TicTacToe&);
string toString(int a);
#endif