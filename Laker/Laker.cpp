/**************************************************
Lake Counting
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 6686		Accepted: 3310

Description
Due to recent rains, water has pooled in various places in Farmer John's field, which is represented by a rectangle of N x M (1 <= N <= 100; 1 <= M <= 100) squares. Each square contains either water ('W') or dry land ('.'). Farmer John would like to figure out how many ponds have formed in his field. A pond is a connected set of squares with water in them, where a square is considered adjacent to all eight of its neighbors.

Given a diagram of Farmer John's field, determine how many ponds he has.

Input
* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: M characters per line representing one row of Farmer John's field. Each character is either 'W' or '.'. The characters do not have spaces between them.

Output
* Line 1: The number of ponds in Farmer John's field.

Sample Input

10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

Sample Output

3

Hint
OUTPUT DETAILS:

There are three ponds: one in the upper left, one in the lower left,and one along the right side.

Source
USACO 2004 November
**************************************************/
//DFS mark all the adjacent
//AUTHOR: LIAHO
//DATE: 18 APRIL 2009
//VENUE: DORMITORY
#include <iostream>
using namespace std;
char farm[100][100];
int color[100][100],n,m,c,t;

void paint(int i,int j)
{
	if(color[i][j]>0||farm[i][j]=='.'||i<0||i>=n||j<0||j>=m){
		return;
	}
	color[i][j]=c;
	paint(i-1,j-1);
	paint(i-1,j);
	paint(i-1,j+1);
	paint(i,j+1);
	paint(i,j-1);
	paint(i+1,j+1);
	paint(i+1,j-1);
	paint(i+1,j);
}

int main()
{
	while(cin>>n>>m&&m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>farm[i][j];
			color[i][j]=0;
		}
	}
	c=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(farm[i][j]=='.'||color[i][j]){
				continue;
			}
			paint(i,j);
			c++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<color[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<c-1<<endl;
	}
}
			
