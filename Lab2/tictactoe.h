#ifndef tictactoe
#define tictactoe

enum Player {
	no_player,
	playerone,
	playertwo
};
//game pieces
struct game_piece {
	Player player;
	string piece;
};
//Game class
class TicTacToe {
	game_piece gameboard[5][5];
	unsigned int num_moves;
	string x_moves;
	string o_moves;
	Player winner;
	unsigned int remainder;
	friend ostream & operator<< (ostream&, const TicTacToe&);
public:
	bool done();
	bool draw();
	int prompt(unsigned int & x,unsigned int & y);
	int turn();
	int play();
	void initialize();
};
ostream & operator<< (ostream&, const TicTacToe&);
string toString(int a);
#endif