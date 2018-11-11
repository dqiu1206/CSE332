#ifndef gomoku
#define gomoku
#include "gamebase.h"


//Game class
class Gomoku : public GameBase {
	game_piece** gameboard;
	int max_dimensions = 19;
	int win_count = 5;
	unsigned int num_moves = 0;
	string player1_moves = "Player B: ";
	string player2_moves = "Player W: ";
	Player winner;
	friend ostream & operator<< (ostream&, const Gomoku&);
public:
	virtual Player done();
	virtual bool draw();
	virtual int turn();
	virtual void initialize();
	virtual void print() override;
	virtual unsigned int getTurns();
	virtual bool isValid(unsigned int &x, unsigned int &y);
	virtual int getMax();
	Player horizontal_win();
	Player vertical_win();
	Player diagonal_win();
	virtual string getNames(Player player);
	Gomoku();
	Gomoku(int dimensions, int wins);
};
ostream & operator<< (ostream&, const Gomoku&);
string toString(int a);
#endif