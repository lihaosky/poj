/*************************************************************8
BST
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 4462		Accepted: 2512

Description
Consider an infinite full binary search tree (see the figure below), the numbers in the nodes are 1, 2, 3, .... In a subtree whose root node is X, we can get the minimum number in this subtree by repeating going down the left node until the last level, and we can also find the maximum number by going down the right node. Now you are given some queries as "What are the minimum and maximum numbers in the subtree whose root node is X?" Please try to find answers for there queries.

Input
In the input, the first line contains an integer N, which represents the number of queries. In the next N lines, each contains a number representing a subtree with root number X (1 <= X <= 231 - 1).

Output
There are N lines in total, the i-th of which contains the answer for the i-th query.

Sample Input

2
8
10

Sample Output

1 15
9 11

Source
POJ Monthly,Minkerui
*************************************************************************************/
// binary way 
// AUTHOR: LIHAO
// VENUE: DORMITORY
// DATE: 18 APRIL 2009
#include <iostream>
using namespace std;
int main()
{
	long long n,l,r,tar,mid;
	cin >> n;
	while(n--){
		cin >> tar;
		if(tar%2){
			cout << tar << " " << tar << endl;
			continue;
		}
		r=2;
		while(r < tar){
			r*=2;
		}
		if(r == tar){
			cout << 1 << " " << 2*r-1 <<endl;
			continue;
		}
		l=r/2+1;
		r--;
		while(1){
			mid = (l + r)/2;
			if(mid == tar){
				cout << l << " " << r << endl;
				break;
			}
			else if(mid > tar){
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
	}
}
