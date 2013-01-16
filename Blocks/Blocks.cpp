/*
Blocks
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 1141		Accepted: 397

Description

Panda has received an assignment of painting a line of blocks. Since Panda is such an intelligent boy, he starts to think of a math problem of painting. Suppose there are N blocks in a line and each block can be paint red, blue, green or yellow. For some myterious reasons, Panda want both the number of red blocks and green blocks to be even numbers. Under such conditions, Panda wants to know the number of different ways to paint these blocks.

Input

The first line of the input contains an integer T(1≤T≤100), the number of test cases. Each of the next T lines contains an integer N(1≤N≤10^9) indicating the number of blocks.

Output

For each test cases, output the number of ways to paint the blocks in a single line. Since the answer may be quite large, you have to module it by 10007.

Sample Input

2
1
2

Sample Output

2
6

Source
PKU Campus 2009 (POJ Monthly Contest – 2009.05.17), Simon
*/

//there is a formula, which is 4^(n-1) + 2^(n-1). It is derived from permutation and combination and binomial coefficient.

//AUTHRO: LIHAO
//DATE: 20 MAY 2009
//VENUE: DORMITORY

#include <iostream>
using namespace std;

int compute(int n)
{
	if (n == 0){
		return 1;
	}
	if (n == 1){
		return 2;
	}
	int x = compute(n >> 1);
	if (n & 1){
		return (x * x * 2) % 10007;
	}
	else{
		return (x * x) % 10007;
	}
}

int main()
{
	int t, n, a, x1, x2;
	cin >> t;
	while (t--){
		cin >> n;
		x1 = compute(n - 1);
		cout << x1 << endl;
		a = (x1 + x1 * x1) % 10007;
		cout << a << endl;
	}
}
