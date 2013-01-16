/***********************************************************************
Parkside's Triangle
Time Limit: 1000MS  Memory Limit: 65536K
Total Submissions: 3710  Accepted: 2228

Description

Bessie taught the cows to make Parkside's Triangle. It is generated from two numbers: the size and the seed. The size N (1 <= N <= 20) determines how many rows are in the triangle and the seed S (1 <= S <= 9) determines the first number in the triangle. Here are two examples:


 N=5, S=3                  N=6, S=1

3 4 6 9 4                1 2 4 7 2 7
  5 7 1 5                  3 5 8 3 8
    8 2 6                    6 9 4 9
      3 7                      1 5 1
        8                        6 2
                                   3
The first line of any triangle has no blanks at its front.

Analyze the above examples, discover the rule, and write a program that will generate Parkside's Triangle given any size N (1 <= N <= 20) and any seed S (1 <= S <= 9).
Input

Line 1: Two space-separated integers: N and S
Output

Lines 1..N: Parkside's Triangle as above; no trailing blanks on any line.
Sample Input

5 3
Sample Output

3 4 6 9 4
  5 7 1 5
    8 2 6
      3 7
        8
Source

USACO 2006 December Bronze
***************************************************************************************/
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 4 APRIL 2009
#include <iostream>
using namespace std;
int main()
{
      int size,seed,next_first;
      cin>>size>>seed;
      next_first=seed;
      for(int i=1;i<=size;i++){
            for(int j=0;j<2*(i-1);j++){
                  cout<<" ";
            }
            seed=next_first;
            cout<<seed<<" ";
            for(int k=i;k<=size-1;k++){
                  seed+=k;
                  if(seed%9==0){
                        seed=9;
                  }
                  else{
                        seed%=9;
                  }
                  cout<<seed<<" ";
                  if(k==i){
                        if(seed==9){
                              next_first=1;
                        }
                        else{
                              next_first=seed+1;
                        }
                  }
            }
            cout<<endl;
      }
}
