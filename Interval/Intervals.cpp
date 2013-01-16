/*
Intervals
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 3757  Accepted: 1480

Description

There is given the series of n closed intervals [ai; b i], where i=1,2,...,n. The sum of those intervals may berepresented as a sum of closed pairwise non−intersecting intervals. The task is to find such representation with the minimal number of intervals. The intervals of this representation should be written in the output file in acceding order. We say that the intervals [a; b] and [c; d] are in ascending order if, and only if a <= b < c <= d.
Task
Write a program which:
.reads from the std input the description of the series of intervals,
.computes pairwise non−intersecting intervals satisfying the conditions given above,
.writes the computed intervals in ascending order into std output
Input

In the first line of input there is one integer n, 3 <= n <= 50000. This is the number of intervals. In the (i+1)−st line, 1 <= i <= n, there is a description of the interval [ai; bi] in the form of two integers ai and bi separated by a single space, which are respectively the beginning and the end of the interval,1 <= ai <= bi <= 1000000.
Output

The output should contain descriptions of all computed pairwise non−intersecting intervals. In each line should be written a description of one interval. It should be composed of two integers, separated by a single space, the beginning and the end of the interval respectively. The intervals should be written into the output in ascending order.
Sample Input

5
5 6
1 4
10 10
6 9
8 10
Sample Output

1 4
5 10
Source

POI VIII Stage 1 Problem 2
*/
//AUTHOR: LIHAO
//DATE: 7 MAY 2009
//VENUE: DORMITORY

#include <iostream>
#include <algorithm>
using namespace std;
struct Interval
{
      int l,r;
}interval[50001];
bool cmp(Interval a,Interval b)
{
      if(a.l!=b.l){
            return a.l<b.l;
      }
      return a.r<b.r;
}
int main()
{
      int n,left,right;
      scanf("%d",&n);
      for(int i=0;i<n;i++){
            scanf("%d%d",&interval[i].l,&interval[i].r);
      }
      sort(interval,interval+n,cmp);
      left=interval[0].l;
      right=interval[0].r;
      for(int i=1;i<n;i++){
            if(interval[i].l>right){
                  printf("%d %d\n",left,right);
                  left=interval[i].l;
                  right=interval[i].r;
            }
            else{
                  if(interval[i].r>right){
                        right=interval[i].r;
                  }
            }
      }
      printf("%d %d\n",left,right);
}
