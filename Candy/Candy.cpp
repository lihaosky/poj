/***********************
Candy Distribution
Time Limit: 1000MS  Memory Limit: 65536K
Total Submissions: 3284  Accepted: 1657

Description

N children standing in circle who are numbered 1 through N clockwise are waiting their candies. Their teacher distributes the candies by in the following way:

First the teacher gives child No.1 and No.2 a candy each. Then he walks clockwise along the circle, skipping one child (child No.3) and giving the next one (child No.4) a candy. And then he goes on his walk, skipping two children (child No.5 and No.6) and giving the next one (child No.7) a candy. And so on.

Now you have to tell the teacher whether all the children will get at least one candy?

Input

The input consists of several data sets, each containing a positive integer N (2 ¡Ü N ¡Ü 1,000,000,000).

Output

For each data set the output should be either "YES" or "NO".

Sample Input

2
3
4
Sample Output

YES
NO
YES
Source

POJ Monthly--2007.09.09, ailyanlu@zsu
***************/

//it seems n should be power of 2, but why?
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 19 APRIL 2009
#include <iostream>
using namespace std;
int main()
{
      __int64 n;
      while(cin>>n){
           puts(n&n-1?"NO":"YES");
      }
}
