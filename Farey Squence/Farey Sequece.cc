/*
Farey Sequence
Time Limit: 1000MS  Memory Limit: 65536K
Total Submissions: 5232  Accepted: 1864

Description

The Farey Sequence Fn for any integer n with n >= 2 is the set of irreducible rational numbers a/b with 0 < a < b <= n and gcd(a,b) = 1 arranged in increasing order. The first few are
F2 = {1/2}
F3 = {1/3, 1/2, 2/3}
F4 = {1/4, 1/3, 1/2, 2/3, 3/4}
F5 = {1/5, 1/4, 1/3, 2/5, 1/2, 3/5, 2/3, 3/4, 4/5}

You task is to calculate the number of terms in the Farey sequence Fn.
Input

There are several test cases. Each test case has only one line, which contains a positive integer n (2 <= n <= 106). There are no blank lines between cases. A line with a single 0 terminates the input.
Output

For each test case, you should output one line, which contains N(n) ---- the number of terms in the Farey sequence Fn.

Sample Input

2
3
4
5
0
Sample Output

1
3
5
9

*/
//AUTHOR: LIHAO
//DATE: 20TH SEPTEMBER 2009
//VENUE: DORM

#include <iostream>
#define M 1000001
using namespace std;
struct Num
{
  bool notPrime;
  long long phi;
  int factor;
}num[M];
long long farey[M];
int main()
{
   for (int i = 2; i < M; i++) {
       if (num[i].notPrime) {
          continue;
       }
       for (int j = i * 2; j < M; j += i) {
            num[j].notPrime = true;
            num[j].factor = i;
       }
   }
   farey[1] = 0;
   for (int i = 2; i < M; i++) {
       if (!num[i].notPrime) {
          num[i].phi = i - 1;
       }
       else {
          int k = i / num[i].factor;
          if (k % num[i].factor) {
              num[i].phi = num[k].phi * (num[i].factor - 1);
          }
          else {
              num[i].phi = num[k].phi * num[i].factor;
          }
       }
       farey[i] = farey[i - 1] + num[i].phi;
   }
   int test;
   while (cin >> test && test) {
        cout << farey[test] << endl;
   }
}
