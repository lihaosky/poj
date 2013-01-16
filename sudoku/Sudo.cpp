/************************************************************************
Sudoku
Time Limit: 2000MS  Memory Limit: 65536K
Total Submissions: 3996  Accepted: 1803  Special Judge

Description

Sudoku is a very simple task. A square table with 9 rows and 9 columns is divided to 9 smaller squares 3x3 as shown on the Figure. In some of the cells are written decimal digits from 1 to 9. The other cells are empty. The goal is to fill the empty cells with decimal digits from 1 to 9, one digit per cell, in such way that in each row, in each column and in each marked 3x3 subsquare, all the digits from 1 to 9 to appear. Write a program to solve a given Sudoku-task.

Input

The input data will start with the number of the test cases. For each test case, 9 lines follow, corresponding to the rows of the table. On each line a string of exactly 9 decimal digits is given, corresponding to the cells in this line. If a cell is empty it is represented by 0.
Output

For each test case your program should print the solution in the same format as the input data. The empty cells have to be filled according to the rules. If solutions is not unique, then the program may print any one of them.
Sample Input

1
103000509
002109400
000704000
300502006
060000050
700803004
000401000
009205800
804000107
Sample Output

143628579
572139468
986754231
391542786
468917352
725863914
237481695
619275843
854396127
****************************************/
//backtracking easy
// AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: APRIL 11, 2009
#include <iostream>
#include <string>
using namespace std;
string a[9];
int m[9][9],cur_r,cur_c,t;
bool to_be_done[9][9];
bool check(int r,int c)
{
      for(int i=0;i<9;i++){
            if(i==c){
                  continue;
            }
            if(m[r][i]==m[r][c]){
                  return false;
            }
      }
      for(int i=0;i<9;i++){
            if(i==r){
                  continue;
            }
            if(m[i][c]==m[r][c]){
                  return false;
            }
      }
      for(int i=r/3*3;i<(r/3+1)*3;i++){
            for(int j=c/3*3;j<(c/3+1)*3;j++){
                  if(i==r&&j==c){
                        continue;
                  }
                  if(m[i][j]==m[r][c]){
                        return false;
                  }
            }
      }
      return true;
}
inline void proceed()
{
      cur_c--;
      if(cur_c==-1){
            cur_c=8;
            cur_r--;
      }
}
void backward()
{
      while(1){
            cur_c++;
            if(cur_c==9){
                  cur_c=0;
                  cur_r++;
            }
            if(to_be_done[cur_r][cur_c]){
                  return;
            }
      }
}

int main()
{
      cin>>t;
      while(t--){
      for(int i=0;i<9;i++){
            cin>>a[i];
      }
      for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                  m[i][j]=a[i][j]-48;
                  if(m[i][j]==0){
                        to_be_done[i][j]=true;
                  }
                  else{
                        to_be_done[i][j]=false;
                  }
            }
      }
      cur_r=cur_c=8;
      int i;
      while(cur_r>=0&&cur_c>=0){
            if(!to_be_done[cur_r][cur_c]){
                  proceed();
            }
            else{
                  while(1){
                        m[cur_r][cur_c]++;
                        if(check(cur_r,cur_c)){
                              break;
                        }
                  }
                  if(m[cur_r][cur_c]==10){
                        m[cur_r][cur_c]=0;
                        backward();
                  }
                  else{
                        proceed();
                  }
            }
      }
      for(i=0;i<9;i++){
            for(int j=0;j<9;j++){
                  cout<<m[i][j];
            }
            cout<<endl;
      }
      }
}

