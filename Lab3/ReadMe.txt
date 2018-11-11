David Qiu (437405)
david.qiu@wustl.edu
Lab 3

Purpose: Refactor existing TicTacToe game into a common game base and added another game (Gomoku) for user to select.

Type lab3.exe TicTacToe or lab3.exe Gomoku to start a game.

Returns: board after each time a player makes a move, until one wins or draws or user types quit
Returns: success (0) if the game is finished with a winner
Returns "Usage: lab3.exe gamename" if the number of arguments is wrong or game name is spelled wrong
Returns "Player Quit" if player quits and a non-zero number (-9)
Returns "Stalemate!" if no more moves available.
Caught errors:
"Dimensions must be greater than or equal to win count!": dimension input is less than win count
"Dimensions must be a number greater than 0!": dimension input less than 1
"Win count must be a number greater than 0!": win input less than 1
"Dimensions and Wins must be a number greater than 0!": win and dimension input less than 1

Extra Credit: Input board dimensions and win count after "lab3.exe Gomoku" to get a custom Gomoku game, otherwise it returns a 19x19 board with 5 win count
I check argument input and if they put in a board dimentsion, I create my array based on what they input. If it is less than 5, then I put the win count to
the board dimension, otherwise it is just defaulted at 5.
If the user put in a win count, I check if it is valid and set that in my class. Then, when checking victory/draw conditions, it is checking based on the user 
input win count.

errors when trying to build:
1. getting my diagonal victory checker for Gomoku was difficult and I had to debug by going through each pair of coordinates I was checking
2. Could not run my play method inside GameBase. Fixed it by creating a constructor for my two classes.

Trial Runs for Gomoku:

Horizontal Win:
Type quit or 'x-coordinate,y-coordinate' to continue playing:
6,3
19

18

17

16

15

14

13

12

11

10

9

8

7

6

5       B B

4     B B

3 B W W W W W

2   B W

1

X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19


Player B: (2,2); (1,3); (3,4); (4,5); (5,5); (4,4);
Player W: (3,2); (3,3); (2,3); (4,3); (5,3); (6,3);
Winner is Player W!
Number of moves: 12

Diagonal Win:

Player B's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
6,6
19

18

17

16

15

14

13

12

11

10

9                 W

8

7

6           B

5         B

4       B

3     B

2   B                              W

1           W                      W

X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19


Player B: (2,2); (3,3); (4,4); (5,5); (6,6);
Player W: (15,1); (15,2); (9,9); (6,1);
Winner is Player B!
Number of moves: 9

H:\My Documents\Visual Studio 2015\Projects\Lab3\Debug>CC
Vertical Win:
Player B's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
3,6
19                                              W

18

17

16

15

14

13

12

11

10

9

8

7

6     B

5     B

4     B

3     B

2 W W B

1 W

X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19


Player B: (3,2); (3,3); (3,4); (3,5); (3,6);
Player W: (1,1); (1,2); (2,2); (19,19);
Winner is Player B!
Number of moves: 9

Extra Credit Gomoku board:

H:\My Documents\Visual Studio 2015\Projects\Lab3\Debug>lab3.exe Gomoku 6 4
6

5

4

3

2

1

X 1 2 3 4 5 6


Player B's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
2,1
6

5

4

3

2

1   B

X 1 2 3 4 5 6


Player B: (2,1);
Player W:
Player W's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
3,3
6

5

4

3     W

2

1   B

X 1 2 3 4 5 6


Player B: (2,1);
Player W: (3,3);
Player B's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
3,1
6

5

4

3     W

2

1   B B

X 1 2 3 4 5 6


Player B: (2,1); (3,1);
Player W: (3,3);
Player W's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
4,4
6

5

4       W

3     W

2

1   B B

X 1 2 3 4 5 6


Player B: (2,1); (3,1);
Player W: (3,3); (4,4);
Player B's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
4,1
6

5

4       W

3     W

2

1   B B B

X 1 2 3 4 5 6


Player B: (2,1); (3,1); (4,1);
Player W: (3,3); (4,4);
Player W's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
2,2
6

5

4       W

3     W

2   W

1   B B B

X 1 2 3 4 5 6


Player B: (2,1); (3,1); (4,1);
Player W: (3,3); (4,4); (2,2);
Player B's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
6,1
6

5

4       W

3     W

2   W

1   B B B   B

X 1 2 3 4 5 6


Player B: (2,1); (3,1); (4,1); (6,1);
Player W: (3,3); (4,4); (2,2);
Player W's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
1,1
6

5

4       W

3     W

2   W

1 W B B B   B

X 1 2 3 4 5 6


Player B: (2,1); (3,1); (4,1); (6,1);
Player W: (3,3); (4,4); (2,2); (1,1);
Winner is Player W!
Number of moves: 8

