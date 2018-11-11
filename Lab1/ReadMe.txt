David Qiu (437405)
david.qiu@wustl.edu
Lab 1

Purpose: Goes through text file line by line and inputs the dimensions followed by the color,name, display and coordinates of each piece in a game board in order to output the game board


Returns: If no errors, it returns the game board
Returns "Usage: lab0.exe <input_file_name>" if the number of arguments is wrong (2)
Returns error messages when something doesn't work

errors when trying to build:
1. errors when trying to create new game piece objects. 
2."Debug Assertion Failed!" vector subscript out of range. Error due to not incrementing across vector correctly.fixed by adding conditional
3.

Test Cases:
1.tic tac toe
Output:
XXO
OX
XOO

2. gomoku.txt
Output:
 O O O O
O O O O
 O O O O


X X X X
 X X X X
X X X X