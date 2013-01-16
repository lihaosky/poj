/*
3. [30%] Maze: A maze is a tour puzzle with one entrance and one exit. It contains walls
and rooms inside. Consecutive rooms form a path. There are one or more paths from the
entrance to the exit, while some of the paths may lead to dead ends. We can visualize the
structure of a maze using an mn matrix M composed of `W' and `.', where a `W' denotes
a wall and a `.' denotes a room. An `S' denotes the entrance and an `F' denotes the exit.
The matrix below is an example of maze:
S W W W W W W W W W W W W . . . . . . . . . . . . W W W W W W
. . . . . . . . . . . . . . W W W W W W W W W W W W W W W W W
W . W W W W W W W W W W W . . . . . . . . . . . . . . . . . W
W . W W W W W W W W W W W . W W W W W W W W W W W W W W W . W
W . W W W W W W W W W W W . W W W W W W W W W W W W W W W . W
W . W W W W W W W W W W W . . . . . . . . . . . . . . . . . W
W . W W W W W W W W W W W W W W W W W W . W W W W W W W W . W
W . W W W W W W W W W W W W W W W W W W . W W W W W W W W . W
W . W W W W W W W W W W W W W W W W W W . W W W W W W W W . W
W . W W W W W W W W W W W W W W W W W W . W W W W W W W W . W
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . F
After the player enters the maze, s/he tries to nd a path to reach the exit. Assume that
the player can only move towards 4 directions: right, down, left and up, and can only
move 1 room each time. The heuristic adopted by the player could be like this:
 If the current room is the exit, s/he successfully nished the route.
 Otherwise, s/he's still on the trip. S/he can try to move right, down, left or up to
see whether there is a way to reach the exit. If s/he encounters a wall or a boundary
of the matrix in the chosen direction, it means there are no ways in this direction
and s/he should try another.
Write a program maze.cpp that reads the structure of a maze from an input le, and nds
the paths from the entrance to the exit using recursion. There are no blanks separating
the `W's and `.'s. (The previous example used blanks to make the diagram easier to read.)
Each maze has exactly one entrance and exactly one exit. Each room should be included
at most once in a path, which means there are no loops in a path. In case there are
more than one paths to reach the exit, output them all. If there are no ways to reach the
2
exit, output nothing. The output path should be composed of a sequence of addresses
of rooms on the path. The address of a room is shown in a row-number, column-number
pair separated by \, " (comma and a blank). The upper left corner has the address of
0, 0. Each line contains one room's address, and each path is followed by a blank line.
Your program gets from command line the name of the input le, the numbers of rows
and columns of the matrix, and outputs the paths to a text le named \path.txt".
Here is a sample run of the program:
The content of input le maze.txt is:
SWWWW
.....
W.W.W
....F
The execution of the program:
[tmchan@localhost ~/c1122/a2]$./maze maze.txt 4 5
After the execution, the content of output le path.txt is:
0, 0
1, 0
1, 1
1, 2
1, 3
2, 3
3, 3
3, 4
0, 0
1, 0
1, 1
2, 1
3, 1
3, 2
3, 3
3, 4
3
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

struct PATH
{
	int row;
	int col;
};

PATH path[1000];

ofstream fp_out;

void print_path(int n)
{
	for(int i=0;i<=n;i++){
		fp_out<<path[i].row<<" ,"<<path[i].col<<endl;
	}
	fp_out<<endl;
}

void restore_maze(string maze[],int row,int col)
{
	for(int i=0;i<=row;i++){
		for(int j=0;j<=col;j++){
			if(maze[i][j]=='x'){
				maze[i][j]='.';
			}
		}
	}
}

bool is_exist(string maze[],int cur_row,int cur_col,int row,int col,int exit_row,int exit_col)
{
      if(cur_row<0||cur_row>row||cur_col<0||cur_col>col){
		return false;
	}
	if(cur_row==exit_row&&cur_col==exit_col){
		return true;
	}
	if(maze[cur_row][cur_col]=='W'||maze[cur_row][cur_col]=='/'||maze[cur_row][cur_col]=='x'){
		return false;
	}
	maze[cur_row][cur_col]='x';
	if(is_exist(maze,cur_row+1,cur_col,row,col,exit_row,exit_col)){
		maze[cur_row+1][cur_col]='.';
		return true;
	}
	if(is_exist(maze,cur_row-1,cur_col,row,col,exit_row,exit_col)){
		maze[cur_row-1][cur_col]='.';
		return true;
	}
	if(is_exist(maze,cur_row,cur_col+1,row,col,exit_row,exit_col)){
		maze[cur_row][cur_col+1]='.';
		return true;
	}
	if(is_exist(maze,cur_row,cur_col-1,row,col,exit_row,exit_col)){
		maze[cur_row][cur_col-1]='.';
		return true;
	}
	return false;
}

bool find_path(string maze[],int counter,int cur_row,int cur_col,int row,int col,int exit_row,int exit_col)
{
      if(cur_row<0||cur_row>row||cur_col<0||cur_col>col){
		return false;
	}
	if(cur_row==exit_row&&cur_col==exit_col){
		path[counter].row=cur_row;
		path[counter].col=cur_col;
		print_path(counter);
		return true;
	}
	if(maze[cur_row][cur_col]=='W'||maze[cur_row][cur_col]=='/'){
		return false;
	}
	maze[cur_row][cur_col]='/';
	bool exist=false;
	if(is_exist(maze,cur_row+1,cur_col,row,col,exit_row,exit_col)){
		exist=true;
		restore_maze(maze,row,col);
		path[counter].row=cur_row;
		path[counter].col=cur_col;
		find_path(maze,counter+1,cur_row+1,cur_col,row,col,exit_row,exit_col);
		maze[cur_row+1][cur_col]='.';
	}
	restore_maze(maze,row,col);
	if(is_exist(maze,cur_row-1,cur_col,row,col,exit_row,exit_col)){
		exist=true;
		restore_maze(maze,row,col);
		path[counter].row=cur_row;
		path[counter].col=cur_col;
		find_path(maze,counter+1,cur_row-1,cur_col,row,col,exit_row,exit_col);
		maze[cur_row-1][cur_col]='.';
	}
	restore_maze(maze,row,col);
	if(is_exist(maze,cur_row,cur_col+1,row,col,exit_row,exit_col)){
		exist=true;
		restore_maze(maze,row,col);
		path[counter].row=cur_row;
		path[counter].col=cur_col;
		find_path(maze,counter+1,cur_row,cur_col+1,row,col,exit_row,exit_col);
		maze[cur_row][cur_col+1]='.';
	}
	restore_maze(maze,row,col);
	if(is_exist(maze,cur_row,cur_col-1,row,col,exit_row,exit_col)){
		exist=true;
		restore_maze(maze,row,col);
		path[counter].row=cur_row;
		path[counter].col=cur_col;
		find_path(maze,counter+1,cur_row,cur_col-1,row,col,exit_row,exit_col);
		maze[cur_row][cur_col-1]='.';
	}
	restore_maze(maze,row,col);
	if(exist){
		return true;
	}
	else{
		return false;
	}
}

int main(int argc,char** argv)
{
  if(argc<4){
     cerr<<"wrong format"<<endl;
     exit(1);
  }
  ifstream fp;

  string f_name,str;
  int row,col,tmp_row;
  f_name=argv[1];
  row=atoi(argv[2])-1;
  col=atoi(argv[3])-1;
  string* maze=new string [row+1];
  fp.open(f_name.c_str());
  fp_out.open("path.txt");
  if(fp.fail()){
     cerr<<"can't open file "<<f_name<<endl;
     exit(1);
  }
  if(fp_out.fail()){
  	cerr<<"can't open file \"path.txt\""<<endl;
  	exit(1);
  }
  tmp_row=0;
  while(fp>>maze[tmp_row++]){
   }
   fp.close();
   find_path(maze,0,0,0,row,col,row,col);
   fp_out.close();
   return 0;
}
