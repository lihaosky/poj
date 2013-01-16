/*
To the Max
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 12846  Accepted: 6481

Description

Given a two-dimensional array of positive and negative integers, a sub-rectangle is any contiguous sub-array of size 1*1 or greater located within the whole array. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle.
As an example, the maximal sub-rectangle of the array:

0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
is in the lower left corner:

9 2
-4 1
-1 8
and has a sum of 15.

Input

The input consists of an N * N array of integers. The input begins with a single positive integer N on a line by itself, indicating the size of the square two-dimensional array. This is followed by N^2 integers separated by whitespace (spaces and newlines). These are the N^2 integers of the array, presented in row-major order. That is, all numbers in the first row, left to right, then all numbers in the second row, left to right, etc. N may be as large as 100. The numbers in the array will be in the range [-127,127].
Output

Output the sum of the maximal sub-rectangle.
Sample Input

4
0 -2 -7 0 9 2 -6 2
-4 1 -4  1 -1

8  0 -2
Sample Output

15
Source

Greater New York 2001
*/

//using DP, get consecutive maximum sub_array using Bently's O(n) algorithm would solve this in O(n^3)
//AUTHOR: LIHAO
//DATE: MAR 2ND 2009
//VENUE: FORMITORY

#include <iostream>
using namespace std;

void get_sum(int matrix[][100],int sum[][100],int size)
{
      for(int i=0;i<size;i++){
            for(int j=1;j<size;j++){
                  sum[j][i]=(sum[j-1][i]+matrix[j][i]);
            }
      }
}

int get_max(int sum[][100],int size)
{
      int max=-1000000000;
      int temp,ans;
      for(int i=0;i<size;i++){
            temp=0;
            ans=0;
            for(int k=0;k<size;k++){
                  if(temp>0){
                        temp+=sum[i][k];
                  }
                  else{
                        temp=sum[i][k];
                  }
                  if(temp>ans){
                        ans=temp;
                  }
            }
            if(ans>max){
                  max=ans;
            }
            for(int j=0;j<i;j++){
                  temp=ans=0;
                  for(int p=0;p<size;p++){
                        if(temp>0){
                              temp+=(sum[i][p]-sum[j][p]);
                        }
                        else{
                              temp=(sum[i][p]-sum[j][p]);
                        }
                        if(temp>ans){
                              ans=temp;
                        }
                  }
                  if(ans>max){
                        max=ans;
                  }
            }
      }
      return max;
}

int main()
{
      int matrix[100][100];
      int sum[101][100];
      int size;
      cin>>size;
      for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                  cin>>matrix[i][j];
            }
      }
      for(int i=0;i<size;i++){
            sum[0][i]=matrix[0][i];
      }
      get_sum(matrix,sum,size);
      cout<<get_max(sum,size)<<endl;
}
