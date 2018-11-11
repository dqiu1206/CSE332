#ifndef gamebase
#define gamebase
#include <memory>
enum Player {
	no_player,
	playerone,
	playertwo
};
struct game_piece {
	Player player;
	string piece;
};
struct sudoku_piece {
	Player player;
	int number;
	string piece;
};
//Game Base class
class GameBase {
protected:
	unsigned int num_moves = 0;
	string player1_moves;
	string player2_moves;
	Player winner;
	static shared_ptr<GameBase> ptr;
	string game_name;
public:
	virtual Player done() = 0;
	virtual bool draw() = 0;
	virtual int turn() = 0;
	virtual void print() = 0;
	virtual void initialize() = 0;
	virtual int prompt(unsigned int & x, unsigned int & y);
	virtual int play();
	virtual unsigned int getTurns() = 0;
	virtual bool isValid(unsigned int &x, unsigned int &y) = 0;
	virtual int getMax() = 0;
	virtual string getNames(Player player) = 0;
	static void start(int a, char* c[]);
	static shared_ptr<GameBase> instance();
	virtual int saveGame(bool isDone);
	virtual string getGameBoard() = 0;
	virtual string getGameName() = 0;
};
#endif