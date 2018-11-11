#ifndef gamebase
#define gamebase

enum Player {
	no_player,
	playerone,
	playertwo
};
struct game_piece {
	Player player;
	string piece;
};
//Game Base class
class GameBase {
protected:
	unsigned int num_moves=0;
	string player1_moves;
	string player2_moves;
	Player winner;
public:
	virtual Player done() = 0;
	virtual bool draw() = 0;
	virtual int turn() = 0;
	virtual void print() = 0;
	virtual void initialize() = 0;
	int prompt(unsigned int & x, unsigned int & y);
	int play();
	virtual unsigned int getTurns() = 0;
	virtual bool isValid(unsigned int &x, unsigned int &y) = 0;
	virtual int getMax() = 0;
	virtual string getNames(Player player) = 0;
	static GameBase* start(int a, char* c[]);
};
#endif