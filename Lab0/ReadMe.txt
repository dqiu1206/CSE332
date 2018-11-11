David Qiu (437405)
david.qiu@wustl.edu
Lab 0

Purpose: Parses text file and outputs each string with non-integer followed by strings with only integers
I did not deviate heavily from the lab specifications

Returns: If no errors, it returns a list of strings followed by a list of integers
Returns "Usage: lab0.exe <input_file_name>" if the number of arguments is wrong (2)
Returns "Cannot open file" if file cannot be opened

errors when trying to build:
1. "syntax error: identifier 'vector'" fixed it by putting #include <vector>, #include <string>,
#include <iostream> and using namespace std in the header file, lab0.h
2."Debug Assertion Failed!" string subscript out of range. I fixed this by using size_t instead of int in my for loops

Test Cases:
1.Ran input_file.txt from lab0 site
Output:
these
all
are
strings
7string
str4ing
string2
more
strings
0
1
2
3
5
7
11
13
17
19

2.Ran another text file I created
hi my name3
432
52 is bo3
what is your 234
name?

Output:
hi
my
name3
is
bo3
what
is
your
name?
432
52
234