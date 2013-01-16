/*****************************************************************************
Longest Ordered Subsequence
Time Limit: 2000MS  Memory Limit: 65536K
Total Submissions: 9055  Accepted: 3709

Description

A numeric sequence of ai is ordered if a1 < a2 < ... < aN. Let the subsequence of the given numeric sequence (a1, a2, ..., aN) be any sequence (ai1, ai2, ..., aiK), where 1 <= i1 < i2 < ... < iK <= N. For example, sequence (1, 7, 3, 5, 9, 4, 8) has ordered subsequences, e. g., (1, 7), (3, 4, 8) and many others. All longest ordered subsequences are of length 4, e. g., (1, 3, 5, 8).

Your program, when given the numeric sequence, must find the length of its longest ordered subsequence.
Input

The first line of input file contains the length of sequence N. The second line contains the elements of sequence - N integers in the range from 0 to 10000 each, separated by spaces. 1 <= N <= 1000
Output

Output file must contain a single integer - the length of the longest ordered subsequence of the given sequence.
Sample Input

7
1 7 3 5 9 4 8
Sample Output

4

Source

Northeastern Europe 2002, Far-Eastern Subregion
********************************************************************/
// easy problem using DP to solve it O(N^2)
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 4 APRIL 2009

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
      int a[1000],n,sequence[1000],tmp_max,max=0;
     for(int i=0;i<1000;i++){
           sequence[i]=1;
     }
      cin>>n;
      for(int i=0;i<n;i++){
            cin>>a[i];
            tmp_max=0;
            for(int j=0;j<i;j++){
                  if(a[j]<a[i]){
                        if(sequence[j]>tmp_max){
                              tmp_max=sequence[j];
                        }
                  }
            }
            sequence[i]+=tmp_max;
            if(sequence[i]>max){
                  max=sequence[i];
            }
      }
      cout<<max<<endl;
}
