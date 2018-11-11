David Qiu (437405)
david.qiu@wustl.edu
Lab 2

Purpose: Creates a tic-tac-toe board for user to play.

Type Lab2.exe TicTacToe to start the game.

Returns: board after each time a player makes a move, until one wins or draws.
Returns "Usage: lab2.exe TicTacToe" if the number of arguments is wrong or game name is spelled wrong
Returns "Player Quit" if player quits or game ends.
Returns "Draw!" if no more moves available.

errors when trying to build:
1. draw() function didn't return correctly. It was due to me accessing array outside what I was supposed to

Microsoft Windows [Version 6.1.7601]
Copyright (c) 2009 Microsoft Corporation.  All rights reserved.

Trial Run 1 (player x win):

H:\My Documents\Visual Studio 2015\Projects\Lab2\Debug>lab2.exe TicTacToe
4

3

2

1

0

  0 1 2 3 4


Player X's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
1,1
4

3

2

1   X

0

  0 1 2 3 4


Player X: (1,1);
Player O's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
2,
Invalid Input
Type quit or 'x-coordinate,y-coordinate' to continue playing:
2,2
4

3

2     O

1   X

0

  0 1 2 3 4


Player O: (2,2);
Player X's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
3,2
4

3

2     O X

1   X

0

  0 1 2 3 4


Player X: (1,1); (3,2);
Player O's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
3,3
4

3       O

2     O X

1   X

0

  0 1 2 3 4


Player O: (2,2); (3,3);
Player X's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
1,2
4

3       O

2   X O X

1   X

0

  0 1 2 3 4


Player X: (1,1); (3,2); (1,2);
Player O's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
2,3
4

3     O O

2   X O X

1   X

0

  0 1 2 3 4


Player O: (2,2); (3,3); (2,3);
Player X's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
2,1
4

3     O O

2   X O X

1   X X

0

  0 1 2 3 4


Player X: (1,1); (3,2); (1,2); (2,1);
Player O's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
3,1
4

3     O O

2   X O X

1   X X O

0

  0 1 2 3 4


Player O: (2,2); (3,3); (2,3); (3,1);
Player X's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
1,3
4

3   X O O

2   X O X

1   X X O

0

  0 1 2 3 4


Player X: (1,1); (3,2); (1,2); (2,1); (1,3);
Winner is Player X!
Player Quit

Trial 2 (draw):

H:\My Documents\Visual Studio 2015\Projects\Lab2\Debug>lab2.exe TicTacToe
4

3

2

1

0

  0 1 2 3 4


Player X's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
2,2
4

3

2     X

1

0

  0 1 2 3 4


Player X: (2,2);
Player O's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
3,3
4

3       O

2     X

1

0

  0 1 2 3 4


Player O: (3,3);
Player X's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
3,1
4

3       O

2     X

1       X

0

  0 1 2 3 4


Player X: (2,2); (3,1);
Player O's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
2,1
4

3       O

2     X

1     O X

0

  0 1 2 3 4


Player O: (3,3); (2,1);
Player X's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
1,1
4

3       O

2     X

1   X O X

0

  0 1 2 3 4


Player X: (2,2); (3,1); (1,1);
Player O's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
1,3
4

3   O   O

2     X

1   X O X

0

  0 1 2 3 4


Player O: (3,3); (2,1); (1,3);
Player X's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
2,3
4

3   O X O

2     X

1   X O X

0

  0 1 2 3 4


Player X: (2,2); (3,1); (1,1); (2,3);
Player O's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
3,2
4

3   O X O

2     X O

1   X O X

0

  0 1 2 3 4


Player O: (3,3); (2,1); (1,3); (3,2);
Player X's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
1,2
4

3   O X O

2   X X O

1   X O X

0

  0 1 2 3 4


Player X: (2,2); (3,1); (1,1); (2,3); (1,2);
Draw!
Player Quit
