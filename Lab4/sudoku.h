#ifndef sudoku
#define sudoku
#include "gamebase.h"


//Game class
class Sudoku : public GameBase {
	sudoku_piece gameboard[9][9];
	sudoku_piece given[9][9];
	unsigned int num_moves = 0;
	string game_name = "sudoku0";
	friend ostream & operator<< (ostream&, const Sudoku&);
public:
	Sudoku();
	virtual void initialize();
	virtual void print() override;
	virtual bool isValid(unsigned int &x, unsigned int &y);
	
	virtual unsigned int getTurns();
	virtual string getGameBoard();
	virtual string getNames(Player player);
	int setBoard(string file_board[]);
	void Sudoku::sudoku_set(string file_board, unsigned int x, unsigned int y);
	virtual string getGameName();
	bool squareWin(int x_start, int x_end, int y_start, int y_end);
	bool column_win(int column);
	virtual Player done(); //unfinished
	virtual bool draw();
	virtual int turn();
	virtual int play();
	int prompt(unsigned int &x,unsigned int &y, unsigned int &number);
	virtual int getMax();
	string toString(int a);

};
ostream & operator<< (ostream&, const Sudoku&);
#endif