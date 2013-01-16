/*
Parliament
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 7587  Accepted: 3239

Description

New convocation of The Fool Land's Parliament consists of N delegates. According to the present regulation delegates should be divided into disjoint groups of different sizes and every day each group has to send one delegate to the conciliatory committee. The composition of the conciliatory committee should be different each day. The Parliament works only while this can be accomplished.
You are to write a program that will determine how many delegates should contain each group in order for Parliament to work as long as possible.

Input

The input file contains a single integer N (5<=N<=1000 ).
Output

Write to the output file the sizes of groups that allow the Parliament to work for the maximal possible time. These sizes should be printed on a single line in ascending order and should be separated by spaces.
Sample Input

7
Sample Output

3 4
Source

Northeastern Europe 1998
*/

//NUMBER theory : see readme
//sequence would be the biggest: it's to find n1+n2+....+ n=N st: n1*n2*n3 is the maximum
//AUTHOR: LIHAO
//DATE: MAR 2ND 2009
//VENUE: DORMITORY

#include <iostream>
using namespace std;
int main()
{
      int n,a[100],sum=0;
      int size=0,diff;
      cin>>n;
      for(int i=2;;i++){
            sum+=i;
            if(sum==n){
                  a[size++]=i;
                  for(int j=0;j<size;j++){
                        cout<<a[j]<<" ";
                  }
                  cout<<endl;
                  return 0;
            }
            else if(sum>n){
                  diff=(n+i-sum);
                  break;
            }
            else{
                  a[size++]=i;
            }
      }
      for(int i=0;i<size;i++){
            a[i]+=(diff/size);
      }
      for(int i=size-1;i>size-1-diff%size;i--){
            a[i]++;
      }
      for(int i=0;i<size;i++){
            cout<<a[i]<<" ";
      }
      cout<<endl;
      return 0;
}
