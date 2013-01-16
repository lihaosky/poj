/*
2D-Nim
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 1130  Accepted: 458

Description

The 2D-Nim board game is played on a grid, with pieces on the grid points. On each move, a player may remove any positive number of contiguous pieces in any row or column. The player who removes the last piece wins. For example, consider the left grid in the following figure.

The player on move may remove (A), (B), (A, B), (A, B, C), or (B,F), etc., but may not remove (A, C), (D, E), (H, I) or (B, G).
For purposes of writing 2D-Nim-playing software, a certain programmer wants to be able to tell whether or not a certain position has ever been analyzed previously. Because of the rules of 2D-Nim, it should be clear that the two boards above are essentially equivalent. That is, if there is a winning strategy for the left board, the same one must apply to the right board. The fact that the contiguous groups of pieces appear in different places and orientations is clearly irrelevant. All that matters is that the same clusters of pieces (a cluster being a set of contiguous pieces that can be reached from each other by a sequence of one-square vertical or horizontal moves) appear in each. For example, the cluster of pieces (A, B, C, F, G) appears on both boards, but it has been reflected (swapping left and right), rotated, and moved. Your task is to determine whether two given board states are equivalent in this sense or not.
Input

The first line of the input file contains a single integer t (1 ¡Ü t ¡Ü 10), the number of test cases, followed by the input data for each test case. The first line of each test case consists of three integers W, H, and n (1 ¡Ü W, H ¡Ü 100). W is the width, and H is the height of the grid in terms of the number of grid points. n is the number of pieces on each board. The second line of each test case contains a sequence of n pairs of integers xi , yi, giving the coordinates of the pieces on the first board (0 ¡Ü xi < W and 0 ¡Ü yi < H). The third line of the test case describes the coordinates of the pieces on the second board in the same format.
Output

Your program should produce a single line for each test case containing a word YES or NO indicating whether the two boards are equivalent or not.
Sample Input

2
8 5 11
0 0 1 0 2 0 5 0 7 0 1 1 2 1 5 1 3 3 5 2 4 4
0 4 0 3 0 2 1 1 1 4 1 3 3 3 5 2 6 2 7 2 7 4
8 5 11
0 0 1 0 2 0 5 0 7 0 1 1 2 1 5 1 3 3 6 1 4 4
0 4 0 3 0 2 1 1 1 4 1 3 3 3 5 2 6 2 7 2 7 4
Sample Output

YES
NO
*/
//find each point's ajacent points and sort it and compare one to one
//AUTHOR: LIHAO
//DATE: MAR 4TH 2009
//VENUE: DORMITORY


#include <iostream>
#include <algorithm>
using namespace std;

struct nim
{
      bool is_exist;
      int vertical;
      int horizon;
};


void get(nim a[][100],int i,int j,int row,int col)
{
      int m=i;
      while(m>=0&&a[m][j].is_exist){
            a[i][j].horizon++;
            m--;
      }
      m=i+1;
      while(m<row&&a[m][j].is_exist){
            a[i][j].horizon++;
            m++;
      }
      m=j;
      while(m>=0&&a[i][m].is_exist){
            a[i][j].vertical++;
            m--;
      }
      m=j+1;
      while(m<col&&a[i][m].is_exist){
            a[i][j].vertical++;
            m++;
      }
      if(a[i][j].vertical>a[i][j].horizon){
            int temp=a[i][j].vertical;
            a[i][j].vertical=a[i][j].horizon;
            a[i][j].horizon=temp;
      }
}

bool cmp(const nim&a,const nim&b)
{
      if(a.horizon<b.horizon){
            return true;
      }
      else if(a.horizon>b.horizon){
            return false;
      }
      else{
            return a.vertical<b.vertical;
      }
}

bool decide(nim a[],nim b[],int size)
{
      for(int i=0;i<size;i++){
            if(a[i].vertical!=b[i].vertical||a[i].horizon!=b[i].horizon){
                  return false;
            }
      }
      return true;
}

int main()
{
      int case_num,width,length,number,x,y;
      cin>>case_num;
      for(int i=0;i<case_num;i++){
            nim a[100][100],b[100][100];
            nim a1[10000],b1[10000];
            int size=0;
            cin>>length>>width>>number;
            for(int m=0;m<width;m++){
                  for(int n=0;n<length;n++){
                        a[m][n].is_exist=false;
                        b[m][n].is_exist=false;
                        a[m][n].horizon=0;
                        a[m][n].vertical=0;
                        b[m][n].horizon=0;
                        b[m][n].vertical=0;
                  }
            }
            for(int j=0;j<number;j++){
                  cin>>x>>y;
                  a[y][x].is_exist=true;
            }
            for(int m=0;m<width;m++){
                  for(int n=0;n<length;n++){
                        if(a[m][n].is_exist){
                              get(a,m,n,width,length);
                              a1[size++]=a[m][n];
                        }
                  }
            }
            sort(a1,a1+number,cmp);
            size=0;
            for(int j=0;j<number;j++){
                  cin>>x>>y;
                  b[y][x].is_exist=true;
            }
            for(int m=0;m<width;m++){
                  for(int n=0;n<length;n++){
                        if(b[m][n].is_exist){
                              get(b,m,n,width,length);
                              b1[size++]=b[m][n];
                        }
                  }
            }
            sort(b1,b1+number,cmp);
            if(decide(a1,b1,number)){
                  cout<<"YES"<<endl;
            }
            else{
                  cout<<"NO"<<endl;
            }
      }
      return 0;
}
