/*********************************************************************************************
4 Values whose Sum is 0
Time Limit: 15000MS  Memory Limit: 228000K
Total Submissions: 6300  Accepted: 1563
Case Time Limit: 5000MS

Description

The SUM problem can be formulated as follows: given four lists A, B, C, D of integer values, compute how many quadruplet (a, b, c, d ) ¡Ê A x B x C x D are such that a + b + c + d = 0 . In the following, we assume that all lists have the same size n .
Input

The first line of the input file contains the size of the lists n (this value can be as large as 4000). We then have n lines containing four integer values (with absolute value as large as 228 ) that belong respectively to A, B, C and D .
Output

For each input file, your program has to write the number quadruplets whose sum is zero.
Sample Input

6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45

Sample Output

5

Hint

Sample Explanation: Indeed, the sum of the five following quadruplets is zero: (-45, -27, 42, 30), (26, 30, -10, -46), (-32, 22, 56, -46),(-32, 30, -75, 77), (-32, -54, 56, 30).
Source
***************************************/
//compute a[i]+b[i] and c[i]+d[i] respectively and sort them then find -a[i]-b[i] in c[i]+d[i] using binary search
//N^2log(N^2)
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 5 APRIL 2009

#include <cstdio>
#include <algorithm>
using namespace std;
int l1[16000000],l2[16000000],a[4000],b[4000],c[4000],d[4000];
void check(int l2[],int l,int u,int n,int&counter)
{
      if(l>u){
            return;
      }
      int mid=(l+u)/2;
      if(l2[mid]==n){
            counter++;
            check(l2,l,mid-1,n,counter);
            check(l2,mid+1,u,n,counter);
      }
      else if(l2[mid]>n){
            check(l2,l,mid-1,n,counter);
      }
      else{
            check(l2,mid+1,u,n,counter);
      }
}

int main()
{
      int n,size=0,counter=0;
      scanf("%d",&n);
      for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
      }
      for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                  l1[size]=a[i]+b[j];
                  l2[size++]=c[i]+d[j];
            }
      }
      sort(l1,l1+size);
      sort(l2,l2+size);
      printf("%d\n",size);
      for(int i=0;i<size;i++){
            printf("%d %d \n",l1[i],l2[i]);
      }
      for(int i=0;i<size;i++){
            n=0-l1[i];
            check(l2,0,size-1,n,counter);
      }
      printf("%d\n",counter);
      scanf("%d",&counter);
}
