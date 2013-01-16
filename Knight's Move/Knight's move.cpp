/**********************************************************************
Knight Moves
Time Limit: 1000MS  Memory Limit: 30000K
Total Submissions: 7115  Accepted: 3113

Description

Background
Mr Somurolov, fabulous chess-gamer indeed, asserts that no one else but him can move knights from one position to another so fast. Can you beat him?
The Problem
Your task is to write a program to calculate the minimum number of moves needed for a knight to reach one point from another, so that you have the chance to be faster than Somurolov.
For people not familiar with chess, the possible knight moves are shown in Figure 1.




Input

The input begins with the number n of scenarios on a single line by itself.
Next follow n scenarios. Each scenario consists of three lines containing integer numbers. The first line specifies the length l of a side of the chess board (4 <= l <= 300). The entire board has size l * l. The second and third line contain pair of integers {0, ..., l-1}*{0, ..., l-1} specifying the starting and ending position of the knight on the board. The integers are separated by a single blank. You can assume that the positions are valid positions on the chess board of that scenario.
Output

For each scenario of the input you have to calculate the minimal amount of knight moves which are necessary to move from the starting point to the ending point. If starting point and ending point are equal,distance is zero. The distance must be written on a single line.
Sample Input

3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
Sample Output

5
28
0
Source

TUD Programming Contest 2001, Darmstadt, Germany
*************************************************************************/
//BFS solve it
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 19 APRIL 2009

#include <iostream>
#include <queue>
#include <string>
using namespace std;
bool used[310][310];
struct Point
{
      int x,y,label;
};
int size;
void solve(int x1,int y1,int x2,int y2)
{
      if(x1==x2&&y1==y2){
                cout<<0<<endl;
                return;
      }
      Point point;
      point.label=0;
      point.x=x1;
      point.y=y1;
      used[x1][y1]=true;
      queue<Point> path;
      path.push(point);
      while(!path.empty()){
            Point tmp=path.front();
            if(tmp.x-1>0&&tmp.y-2>0&&used[tmp.x-1][tmp.y-2]==false){
                  if(tmp.x-1==x2&&tmp.y-2==y2){
                        cout<<tmp.label+1<<endl;
                        return;
                  }
                  Point tmp1;
                  tmp1.x=tmp.x-1;
                  tmp1.y=tmp.y-2;
                  tmp1.label=tmp.label+1;
                  used[tmp1.x][tmp1.y]=true;
                  path.push(tmp1);
            }
            if(tmp.x-2>0&&tmp.y-1>0&&used[tmp.x-2][tmp.y-1]==false){
                  if(tmp.x-2==x2&&tmp.y-1==y2){
                        cout<< tmp.label+1<<endl;
                        return;
                  }
                  Point tmp1;
                  tmp1.x=tmp.x-2;
                  tmp1.y=tmp.y-1;
                  tmp1.label=tmp.label+1;
                  used[tmp1.x][tmp1.y]=true;
                  path.push(tmp1);
            }
            if(tmp.x<size&&tmp.y-2>0&&used[tmp.x+1][tmp.y-2]==false){
                  if(tmp.x+1==x2&&tmp.y-2==y2){
                        cout<< tmp.label+1<<endl;
                        return;
                  }
                  Point tmp1;
                  tmp1.x=tmp.x+1;
                  tmp1.y=tmp.y-2;
                  tmp1.label=tmp.label+1;
                  used[tmp1.x][tmp1.y]=true;
                  path.push(tmp1);
            }
            if(tmp.x+1<size&&tmp.y-1>0&&used[tmp.x+2][tmp.y-1]==false){
                  if(tmp.x+2==x2&&tmp.y-1==y2){
                        cout<< tmp.label+1<<endl;
                        return;
                  }
                  Point tmp1;
                  tmp1.x=tmp.x+2;
                  tmp1.y=tmp.y-1;
                  tmp1.label=tmp.label+1;
                  used[tmp1.x][tmp1.y]=true;
                  path.push(tmp1);
            }
            if(tmp.x-2>0&&tmp.y<size&&used[tmp.x-2][tmp.y+1]==false){
                  if(tmp.x-2==x2&&tmp.y+1==y2){
                        cout<< tmp.label+1<<endl;
                        return;
                  }
                  Point tmp1;
                  tmp1.x=tmp.x-2;
                  tmp1.y=tmp.y+1;
                  tmp1.label=tmp.label+1;
                  used[tmp1.x][tmp1.y]=true;
                  path.push(tmp1);
            }
            if(tmp.x-1>0&&tmp.y+1<size&&used[tmp.x-1][tmp.y+2]==false){
                  if(tmp.x-1==x2&&tmp.y+2==y2){
                        cout<<tmp.label+1<<endl;
                        return;
                  }
                  Point tmp1;
                  tmp1.x=tmp.x-1;
                  tmp1.y=tmp.y+2;
                  tmp1.label=tmp.label+1;
                  used[tmp1.x][tmp1.y]=true;
                  path.push(tmp1);
            }
            if(tmp.x<size&&tmp.y+1<size&&used[tmp.x+1][tmp.y+2]==false){
                  if(tmp.x+1==x2&&tmp.y+2==y2){
                        cout<<tmp.label+1<<endl;
                        return;
                  }
                  Point tmp1;
                  tmp1.x=tmp.x+1;
                  tmp1.y=tmp.y+2;
                  tmp1.label=tmp.label+1;
                  used[tmp1.x][tmp1.y]=true;
                  path.push(tmp1);
            }
            if(tmp.x+1<size&&tmp.y<size&&used[tmp.x+2][tmp.y+1]==false){
                  if(tmp.x+2==x2&&tmp.y+1==y2){
                        cout<<tmp.label+1<<endl;
                        return;
                  }
                  Point tmp1;
                  tmp1.x=tmp.x+2;
                  tmp1.y=tmp.y+1;
                  tmp1.label=tmp.label+1;
                  used[tmp1.x][tmp1.y]=true;
                  path.push(tmp1);
            }
            path.pop();
      }
}
int main()
{
      string start,end;
      int x1,x2,y1,y2,t;
      cin>>t;
      while(t--){
            cin>>size;
            for(int i=0;i<size+1;i++){
                  for(int j=0;j<size+1;j++){
                        used[i][j]=false;
                  }
            }
            cin>>x1>>y1>>x2>>y2;
            x1++;y1++;x2++;y2++;
            solve(x1,y1,x2,y2);
      }
}
