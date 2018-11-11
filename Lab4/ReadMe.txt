David Qiu (437405)
david.qiu@wustl.edu
Lab 4

Purpose: Allow for saves and add Sudoku game
Type lab4.exe TicTacToe or lab4.exe Gomoku or lab4.exe Sudoku to start

Returns: board after each time a player makes a move, until one wins or draws or user types quit
Returns: success (0) if the game is finished with a winner
Returns "Usage: lab3.exe gamename {board_dim} {win_count}" if the number of arguments is wrong or game name is spelled wrong
Returns "Player Quit" if player quits and a non-zero number
Returns "Stalemate!" if no more moves available.
Returns "You won!" if you win in Sudoku along with the completed board.
Returns Dimension error messages if dimensions do not make sense for Extra Credit gomoku from last lab
Returns "Save file cannot be opened" if file cannot be opened
Returns "Game is Saved!" if game is saved.
Returns "Null pointer exists" if the shared ptr exists
Prompts for (x,y) for TicTacToe and Gomoku, and (x,y,number) for Sudoku, user can type "quit" to quit the game. 
Then prompts for save, user can type "yes" to save game, or anything else to wipe the save file.

Save file format:
{string_of_pieces} or {"NONE"} (no game file saved)
Save file is created if it doens't exist.
Save file is overwritten with clean slate if file is incorrectly formatted.
I extract the first 9 numbers of the first 9 lines. If there are extra, I ignore them. If the values are invalid, I start the game over.
"Save File incorrectly formatted. Starting new game." is returned if save file is not correct.

Copy Control:
I used none of them.


errors when trying to build:
1. Sudoku board wasn't printing correctly: fixed by using string constructor to get the string from a char.

Trial Runs for Sudoku:

Sudoku Save File:
0   0 0 0 8 0 0 7 9
0 0 0    4 1 9 0 0 5
0 6 0 0 0 0 2 8 0
7 0 0 0  2 0 0 0 6
4 0 0 8 0 3   0 0 1
8 0 0 0   6 0 0 0 3
0 9 8 0 0 0 0 6 0 
6 0 0 1 9    5 0 0 0 
5 3 0 0 7 0 0   0   0
output:

H:\My Documents\Visual Studio 2015\Projects\Lab4\Debug>lab4.exe Sudoku
8||5|3| || |7| || | | ||
-||-|-|-||-|-|-||-|-|-||
7||6| | ||1|9|5|| | | ||
-||-|-|-||-|-|-||-|-|-||
6|| |9|8|| | | || |6| ||
=||=|=|=||=|=|=||=|=|=||
5||8| | || |6| || | |3||
-||-|-|-||-|-|-||-|-|-||
4||4| | ||8| |3|| | |1||
-||-|-|-||-|-|-||-|-|-||
3||7| | || |2| || | |6||
=||=|=|=||=|=|=||=|=|=||
2|| |6| || | | ||2|8| ||
-||-|-|-||-|-|-||-|-|-||
1|| | | ||4|1|9|| | |5||
-||-|-|-||-|-|-||-|-|-||
0|| | | || |8| || |7|9||
=||=|=|=||=|=|=||=|=|=||
#||0|1|2||3|4|5||6|7|8||

Type quit or 'x-coordinate,y-coordinate,number' to continue playing:
quit
Do you want to save?(input 'yes' to save or anything to restart)
yes
Game is Saved!


Sudoku
NONE
Save File


H:\My Documents\Visual Studio 2015\Projects\Lab4\Debug>lab4.exe Sudoku
8|| | | || | | || | | ||
-||-|-|-||-|-|-||-|-|-||
7|| | | || | | || | | ||
-||-|-|-||-|-|-||-|-|-||
6|| | | || | | || | | ||
=||=|=|=||=|=|=||=|=|=||
5|| | | || | | || | | ||
-||-|-|-||-|-|-||-|-|-||
4|| | | || | | || | | ||
-||-|-|-||-|-|-||-|-|-||
3|| | | || | | || | | ||
=||=|=|=||=|=|=||=|=|=||
2|| | | || | | || | | ||
-||-|-|-||-|-|-||-|-|-||
1|| | | || | | || | | ||
-||-|-|-||-|-|-||-|-|-||
0|| | | || | | || | | ||
=||=|=|=||=|=|=||=|=|=||
#||0|1|2||3|4|5||6|7|8||

Gomoku

H:\My Documents\Visual Studio 2015\Projects\Lab4\Debug>lab4.exe Sudoku
8|| | | || | | || | | ||
-||-|-|-||-|-|-||-|-|-||
7|| | | || | | || | | ||
-||-|-|-||-|-|-||-|-|-||
6|| | | || | | || | | ||
=||=|=|=||=|=|=||=|=|=||
5|| | | || | | || | | ||
-||-|-|-||-|-|-||-|-|-||
4|| | | || | | || | | ||
-||-|-|-||-|-|-||-|-|-||
3|| | | || | | || | | ||
=||=|=|=||=|=|=||=|=|=||
2|| | | || | | || | | ||
-||-|-|-||-|-|-||-|-|-||
1|| | | || | | || | | ||
-||-|-|-||-|-|-||-|-|-||
0|| | | || | | || | | ||
=||=|=|=||=|=|=||=|=|=||
#||0|1|2||3|4|5||6|7|8||

Type quit or 'x-coordinate,y-coordinate,number' to continue playing:
quit
Do you want to save?(input 'yes' to save or anything to restart)
n
Player Quit!

H:\My Documents\Visual Studio 2015\Projects\Lab4\Debug>lab4.exe Gomoku
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

5

4

3

2

1

X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19


Player B's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
quit
Do you want to save?(input 'yes' to save or anything to restart)
yes
Game is Saved!

TicTacToe:

H:\My Documents\Visual Studio 2015\Projects\Lab4\Debug>lab4.exe TicTacToe
4

3

2

1

0

  0 1 2 3 4


Player X's turn
Type quit or 'x-coordinate,y-coordinate' to continue playing:
quit
Do you want to save?(input 'yes' to save or anything to restart)
n
Player Quit!
