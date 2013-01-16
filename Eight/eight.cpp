/*
Eight
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 7225		Accepted: 3158		Special Judge

Description
The 15-puzzle has been around for over 100 years; even if you don't know it by that name, you've seen it. It is constructed with 15 sliding tiles, each with a number from 1 to 15 on it, and all packed into a 4 by 4 frame with one tile missing. Let's call the missing tile 'x'; the object of the puzzle is to arrange the tiles so that they are ordered as:

 1  2  3  4 

 5  6  7  8 

 9 10 11 12 

13 14 15  x 


where the only legal operation is to exchange 'x' with one of the tiles with which it shares an edge. As an example, the following sequence of moves solves a slightly scrambled puzzle:

 1  2  3  4    1  2  3  4    1  2  3  4    1  2  3  4 

 5  6  7  8    5  6  7  8    5  6  7  8    5  6  7  8 

 9  x 10 12    9 10  x 12    9 10 11 12    9 10 11 12 

13 14 11 15   13 14 11 15   13 14  x 15   13 14 15  x 

           r->           d->           r-> 


The letters in the previous row indicate which neighbor of the 'x' tile is swapped with the 'x' tile at each step; legal values are 'r','l','u' and 'd', for right, left, up, and down, respectively.

Not all puzzles can be solved; in 1870, a man named Sam Loyd was famous for distributing an unsolvable version of the puzzle, and
frustrating many people. In fact, all you have to do to make a regular puzzle into an unsolvable one is to swap two tiles (not counting the missing 'x' tile, of course).

In this problem, you will write a program for solving the less well-known 8-puzzle, composed of tiles on a three by three
arrangement.

Input
You will receive a description of a configuration of the 8 puzzle. The description is just a list of the tiles in their initial positions, with the rows listed from top to bottom, and the tiles listed from left to right within a row, where the tiles are represented by numbers 1 to 8, plus 'x'. For example, this puzzle

 1  2  3 

 x  4  6 

 7  5  8 


is described by this list:


 1 2 3 x 4 6 7 5 8 

Output
You will print to standard output either the word ``unsolvable'', if the puzzle has no solution, or a string consisting entirely of the letters 'r', 'l', 'u' and 'd' that describes a series of moves that produce a solution. The string should include no spaces and start at the beginning of the line.

Sample Input

 2  3  4  1  5  x  7  6  8 

Sample Output

ullddrurdllurdruldr

Source
South Central USA 1998
*/

//This is a clumsy program, even though it takes 0ms to solve it.
//AUTHOR: LIHAO
//VENUE: LAB
//DATE: 23, SEPTEMBER, 2009

#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int R,C,r,c;
string path;
int maze[4][4];

void find(int n)
{
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (maze[i][j] == n) {
				r = i;
				c = j;
				return;
			}
		}
	}
}

void left()
{
	maze[R][C] = maze[R][C + 1];
	maze[R][C + 1] = 0;
	C++;
	path += "r";
}

void right()
{
	maze[R][C] = maze[R][C - 1];
	maze[R][C - 1] = 0;
	C--;
	path += "l";
}

void up()
{
	maze[R][C] = maze[R + 1][C];
	maze[R + 1][C] = 0;
	R++;
	path += "d";
}

void show()
{
	cout << "R: " << R << " C: " << C << endl;
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	sleep(2);
}

void down()
{
	maze[R][C] = maze[R - 1][C];
	maze[R - 1][C] = 0;
	R--;
	path += "u";
}

void move1()
{
	if (maze[1][1] == 1) {
		return;
	}
	find(1);
	if (r != R && c != C) {
		while (R < r) {
			up();
		}
		while (R > r) {
			down();
		}
	}
	if (maze[2][2] == 1) {
		if (maze[1][2] == 0) {
			up();
		}
		else if (maze[2][1] == 0) {
			left();
		}
		else if (maze[2][3] == 0) {
			right();
			up();
		}
		else {
			down();
		}
	}
	while (maze[1][1] != 1) {
		if (C == 1) {
			if (R == 1) {
				left();
			}
			else {
				down();
			}
		}
		else if (C == 2) {
			if (R == 1) {
				left();
			}
			else {
				right();
			}
		}
		else {
			if (R == 3) {
				right();
			}
			else {
				up();
			}
		}
	}
}

void move2()
{
	if (maze[1][2] == 2) {
		return;
	}
	find(2);
	if (r != R && c != C) {
		while (R < r) {
			up();
		}
		while (R > r) {
			down();
		}
	}
	while (maze[1][2] != 2) {
		if (C == 1) {
			if (R == 2) {
				left();
			}
			else {
				down();
			}
		}
		else if (C == 2) {
			if (R == 1) {
				left();
			}
			else if (R == 2) {
				down();
			}
			else {
				right();
			}
		}
		else {
			if (R == 3) {
				right();
			}
			else {
				up();
			}
		}
	}
}

void move3()
{
	if (maze[1][3] == 3) {
		return;
	}
	if (maze[2][3] == 3) {
		if (maze[1][3] == 0) {
			up();
			return;
		}
	}
	if (maze[1][3] == 0) {
		up();
	}
	while (maze[2][2] != 3 || maze[2][1] != 0) {
		if (C == 1) {
			if (R == 2) {
				up();
			}
			else {
				left();
			}
		}
		else if (C == 2) {
			if (R == 2) {
				right();
			}
			else {
				left();
			}
		}
		else {
			if (R == 2) {
				right();
			}
			else {
				down();
			}
		}
	}
	down();
	left();
	up();
	left();
	down();
	right();
	right();
	up();
}

void move4()
{
	if (maze[2][1] == 4) {
		return;
	}
	while (maze[2][1] != 4) {
		if (C == 1) {
			if (R == 2) {
				left();
			}
			else {
				down();
			}
		}
		else if (C == 2) {
				if (R == 2) {
					left();
				}
				else {
					right();
				}
		}
		else {
			if (R == 2) {
				up();
			}
			else {
				right();
			}
		}
	}
}

void move5()
{
	if (maze[2][2] == 5) {
		return;
	}
	if (maze[3][1] != 5) {
		if (maze[3][1] == 0) {
			left();
		}
		while (maze[2][2] != 5) {
			if (C == 2) {
				if (R == 2) {
					left();
				}
				else {
					down();
				}
			}
			else {
				if (R == 2) {
					up();
				}
				else {
					right();
				}
			}
		}
	}
	else {
		while (maze[3][2] != 0) {
			if (C == 2) {
				up();
			}
			else {
				right();
			}
		}
		right();
		down();
		left();
		up();
		left();
		down();
		right();
		up();
		right();
		down();
		left();
		up();
		right();
		down();
		left();
		left();
	}
}

void move6()
{
	if (maze[2][3] == 6) {
		return;
	}
	if (maze[2][3] == 0) {
		up();
		right();
		right();
		down();
		left();
		while (maze[2][2] != 6) {
			if (C == 2) {
				if (R == 2) {
					left();
				}
				else {
					down();
				}
			}
			else if (C == 3) {
				if (R == 2) {
					up();
				}
				else {
					right();
				}
			}
		}
	}
	else if (maze[3][1] == 0) {
		down();
		left();
		while (maze[2][2] != 6) {
			if (C == 2) {
				if (R == 2) {
					left();
				}
				else {
					down();
				}
			}
			else if (C == 3) {
				if (R == 2) {
					up();
				}
				else {
					right();
				}
			}
		}
	}
	else if (maze[3][2] == 0) {
		right();
		down();
		left();
		while (maze[2][2] != 6) {
			if (C == 2) {
				if (R == 2) {
					left();
				}
				else {
					down();
				}
			}
			else if (C == 3) {
				if (R == 2) {
					up();
				}
				else {
					right();
				}
			}
		}
	}		
	else {
		right();
		right();
		down();
		left();
		while (maze[2][2] != 6) {
			if (C == 2) {
				if (R == 2) {
					left();
				}
				else {
					down();
				}
			}
			else if (C == 3) {
				if (R == 2) {
					up();
				}
				else {
					right();
				}
			}
		}
	}
	right();
	right();
	up();
}

void move78()
{
	if (maze[3][3] == 0) {
		return;
	}
	else if (maze[3][1] == 0) {
		left();
		left();
	}
	else {
		left();
	}
}

bool check()
{
	if (maze[3][1] == 7) {
	return true;
	}
	return false;
}

int main()
{
	char n;
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			cin >> n;
			if (n == 'x') {
				R = i;
				C = j;
				maze[i][j] = 0;
			}
			else {
				maze[i][j] = n - '0';
			}
		}
	}
	show();
	move1();
	show();
	move2();
	show();
	move3();
	show();
	move4();
	show();
	move5();
	show();
	move6();
	show();
	move78();
	show();
	if (check()) {
		cout << path << endl;
	}
	else {
		cout << "unsolvable" << endl;
	}
}
