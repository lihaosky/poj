
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