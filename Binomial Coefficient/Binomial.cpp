/*****************************************************
Binomial Coefficients
Time Limit: 1000MS  Memory Limit: 131072K
Total Submissions: 3494  Accepted: 1327

Description

The binomial coefficient C(n, k) has been extensively studied for its importance in combinatorics. Binomial coefficients can be recursively defined as follows:

C(n, 0) = C(n, n) = 1 for all n > 0;
C(n, k) = C(n − 1, k − 1) + C(n − 1, k) for all 0 < k < n.

Given n and k, you are to determine the parity of C(n, k).

Input

The input contains multiple test cases. Each test case consists of a pair of integers n and k (0 ≤ k ≤ n < 231, n > 0) on a separate line.

End of file (EOF) indicates the end of input.

Output

For each test case, output one line containing either a “0” or a “1”, which is the remainder of C(n, k) divided by two.

Sample Input

1 1
1 0
2 1
Sample Output

1
1
0
Source
***************************************************/
//just compute the number of 2 in n,k,and n-k and compare the number
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 15 APRIL 2009
#include <iostream>
using namespace std;
int main()
{
      int n,k,a,b,c,m;
      while(cin>>n>>k){
            m=n-k;
            a=b=c=0;
            while(n){
                  a+=n/2;
                  n/=2;
            }
            while(k){
                  b+=k/2;
                  k/=2;
            }
            while(m){
                  c+=m/2;
                  m/=2;
            }
            if(a>b+c){
                  cout<<0<<endl;
            }
            else{
                  cout<<1<<endl;
            }
      }
}
