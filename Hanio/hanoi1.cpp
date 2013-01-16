/********************************************************
Tower of Hanoi
Time Limit: 1000MS  Memory Limit: 131072K
Total Submissions: 833  Accepted: 220

Description

The Tower of Hanoi is a puzzle consisting of three pegs and a number of disks of different sizes which can slide onto any peg. The puzzle starts with the disks neatly stacked in order of size on one peg, the smallest at the top, thus making a conical shape. The objective of the puzzle is to move the entire stack to another peg, obeying the following rules:

Only one disk may be moved at a time.
Each move consists of taking the upper disk from one of the pegs and sliding it onto another peg, on top of the other disks that may already be present on that peg.
No disk may be placed on top of a smaller disk.
For n disks, it is a well-known result that the optimal solution takes 2n − 1 moves.

To complicate the puzzle a little, we allow multiple disks to be of the same size. Moreover, equisized disks are mutually distinguishable. Their ordering at the beginning should be preserved at the end, though it may be disturbed during the process of solving the puzzle.

Given the number of disks of each size, compute the number of moves that the optimal solution takes.

Input

The input contains multiple test cases. Each test case consists of two lines. The first line contains two integers n and m (1 ≤ n ≤ 100, 1 ≤ m ≤ 106). The second lines contains n integers a1, a2, …, an (1 ≤ a1, a2, …, an ≤ 105). For each 1 ≤ i ≤ n, there are ai disks of size i. The input ends where EOF is met.

Output

For each test case, print the answer modulo m on a separate line.

Sample Input

1 1000
2
5 1000
1 1 1 1 1
5 1000
2 2 2 2 2
5 1000
1 2 1 2 1
Sample Output

3
31
123
41
Source

PKU Campus 2008 (POJ Founder Monthly Contest – 2008.05.10), xfxyjwf
***********************************************************************************/

//read concrete mathematics you know what to do
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 19 MAR 2009
#include <iostream>
using namespace std;

int a[101];
int n;
int size;

int A(int i)
{
      int re=0;
      for(int j=1;j<i;j++){
            re=(re+a[j])*2%n;
      }
      re=(re+a[i])%n;
      return re;
}

int B(int i)
{
      if(a[i]==1){
            return A(i);
      }
      if(i==1){
            return 2*a[i]-1;
      }
      return (2*A(i-1)+2*a[i]+B(i-1))%n;
}

int main()
{
      while(cin>>size>>n){
            for(int i=1;i<=size;i++){
                  cin>>a[i];
            }
            cout<<B(size)<<endl;
      }
      return 0;
}
