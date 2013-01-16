/****************************************
World Cup
Time Limit: 1000MS  Memory Limit: 65536K
Total Submissions: 3555  Accepted: 1854

Description

A World Cup of association football is being held with teams from around the world. The standing is based on the number of points won by the teams, and the distribution of points is done the usual way. That is, when a teams wins a match, it receives 3 points; if the match ends in a draw, both teams receive 1 point; and the loser doesn¡¯t receive any points.

Given the current standing of the teams and the number of teams participating in the World Cup, your task is to determine how many matches ended in a draw till the moment.

Input

The input contains several test cases. The first line of a test case contains two integers T and N, indicating respectively the number of participating teams (0 ¡Ü T ¡Ü 200) and the number of played matches (0 ¡Ü N ¡Ü 10000). Each one of the T lines below contains the name of the team (a string of at most 10 letter and digits), followed by a whitespace, then the number of points that the team obtained till the moment. The end of input is indicated by T = 0.

Output

For each one of the test cases, your program should print a single line containing an integer, representing the quantity of matches that ended in a draw till the moment.

Sample Input

3 3
Brasil 3
Australia 3
Croacia 3
3 3
Brasil 5
Japao 1
Australia 1
0 0
Sample Output

0
2
Source

South America 2006, Brazil Subregion
*************************************************/
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 27 MAR, 2009

#include <stdio.h>
int main()
{
      char a[10];
      int n,j,k,t;
      while(scanf("%d%d",&n,&j)&&n){
            t=0;
            for(int i=0;i<n;i++){
                  scanf("%s%d",a,&k);
                  t+=k;
            }
           printf("%d\n",3*j-t);
      }
}
