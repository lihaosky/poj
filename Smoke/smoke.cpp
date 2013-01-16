/*******************************************
Peter's smokes
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 9959		Accepted: 4055

Description
Peter has n cigarettes. He smokes them one by one keeping all the butts. Out of k > 1 butts he can roll a new cigarette.
How many cigarettes can Peter have?

Input
Input is a sequence of lines. Each line contains two integer numbers giving the values of n and k.

Output
For each line of input, output one integer number on a separate line giving the maximum number of cigarettes that Peter can have.

Sample Input

4 3
10 3
100 5

Sample Output

5
14
124

Source
The UofA Local 2000.10.14
*******************************************************/
//there is formular
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 18 APRIL 2009

#include <iostream>
using namespace std;
int main()
{
	long long k,n;
	while(cin>>n>>k){
		int x=(n-k)/(k-1);
		cout<<n+x+1<<endl;
	}
}
