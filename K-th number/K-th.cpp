/**********************************************
K-th Number
Time Limit: 20000MS  Memory Limit: 65536K
Total Submissions: 14857  Accepted: 3687
Case Time Limit: 2000MS

Description

You are working for Macrohard company in data structures department. After failing your previous task about key insertion you were asked to write a new data structure that would be able to return quickly k-th order statistics in the array segment.
That is, given an array a[1...n] of different integer numbers, your program must answer a series of questions Q(i, j, k) in the form: "What would be the k-th number in a[i...j] segment, if this segment was sorted?"
For example, consider the array a = (1, 5, 2, 6, 3, 7, 4). Let the question be Q(2, 5, 3). The segment a[2...5] is (5, 2, 6, 3). If we sort this segment, we get (2, 3, 5, 6), the third number is 5, and therefore the answer to the question is 5.
Input

The first line of the input file contains n --- the size of the array, and m --- the number of questions to answer (1 <= n <= 100 000, 1 <= m <= 5 000).
The second line contains n different integer numbers not exceeding 109 by their absolute values --- the array for which the answers should be given.
The following m lines contain question descriptions, each description consists of three numbers: i, j, and k (1 <= i <= j <= n, 1 <= k <= j - i + 1) and represents the question Q(i, j, k).
Output

For each question output the answer to it --- the k-th number in sorted a[i...j] segment.
Sample Input

7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
Sample Output

5
6
3

*******************************************/
//sort the number and store the sequence number, then just find the subscript
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 5TH APRIL 2009

#include <cstdio>
#include <algorithm>
using namespace std;
struct num
{
      int val;
      int seq;
};
bool cmp(num a,num b)
{
      return a.val<b.val;
}

void main()
{
      int n,i;
      short k;
      num a[100000];
      scanf("%d%d",&n,&k);
      for(i=0;i<n;i++){
            scanf("%d",&a[i].val);
            a[i].seq=i;
      }
      sort(a,a+n,cmp);
      int l,u,s,c;
      while(k--){
            scanf("%d%d%d",&l,&u,&s);
            c=0;
            for(i=0;i<n;i++){
                  if(a[i].seq>=l-1&&a[i].seq<=u-1){
                        c++;
                 if(c==s){
                        printf("%d\n",a[i].val);
                        break;
                  }
            }
            }
      }
}
