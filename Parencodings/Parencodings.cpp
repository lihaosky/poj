/*
Parencodings
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 6079		Accepted: 3583

Description
Let S = s1 s2...s2n be a well-formed string of parentheses. S can be encoded in two different ways:
q By an integer sequence P = p1 p2...pn where pi is the number of left parentheses before the ith right parenthesis in S (P-sequence).
q By an integer sequence W = w1 w2...wn where for each right parenthesis, say a in S, we associate an integer which is the number of right parentheses counting from the matched left parenthesis of a up to a. (W-sequence).

Following is an example of the above encodings:


	S		(((()()())))

	P-sequence	    4 5 6666

	W-sequence	    1 1 1456


Write a program to convert P-sequence of a well-formed string to the W-sequence of the same string.

Input
The first line of the input contains a single integer t (1 <= t <= 10), the number of test cases, followed by the input data for each test case. The first line of each test case is an integer n (1 <= n <= 20), and the second line is the P-sequence of a well-formed string. It contains n positive integers, separated with blanks, representing the P-sequence.

Output
The output file consists of exactly t lines corresponding to test cases. For each test case, the output line should contain n integers describing the W-sequence of the string corresponding to its given P-sequence.

Sample Input

2
6
4 5 6 6 6 6
9 
4 6 6 6 6 8 9 9 9

Sample Output

1 1 1 4 5 6
1 1 2 4 5 1 1 3 9
*/
//AUTHOR: LIHAO
//DATE: MAR 8TH 2009
//VENUE: DORMITORY
//easy problem


#include <iostream>
using namespace std;
int main()
{
	int a[21];
	int pre,cur,size,n;
	cin>>size;
	for(int i=0;i<size;i++){
		cin>>n;
		pre=0;
		for(int j=1;j<=n;j++){
			cin>>cur;
			a[j]=cur-pre;
			pre=cur;
		}
		for(int j=1;j<=n;j++){
			int k=j;
			while(!a[k]){
				k--;
			}
			a[k]--;
			cout<<j-k+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}
