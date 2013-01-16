/*
Easy Finding
Time Limit: 1000MS  Memory Limit: 65536K
Total Submissions: 5369  Accepted: 1227

Description

Given a M¡ÁN matrix A. Aij ¡Ê {0, 1} (0 ¡Ü i < M, 0 ¡Ü j < N), could you find some rows that let every cloumn contains and only contains one 1.
Input

There are multiple cases ended by EOF. Test case up to 500.The first line of input is M, N (M ¡Ü 16, N ¡Ü 300). The next M lines every line contains N integers separated by space.
Output

For each test case, if you could find it output "Yes, I found it", otherwise output "It is impossible" per line.
Sample Input

3 3
0 1 0
0 0 1
1 0 0
4 4
0 0 0 1
1 0 0 0
1 1 0 1
0 1 0 0
Sample Output

Yes, I found it
It is impossible


*/

//Clumsy program I wrote
// AUTHOR: LIHAO
//DATE: 25TH SEMPTEMBER 2009
//VENUE: DORM

#include <iostream>

using namespace std;

struct Row
{
   int size;
   int mark[300];
}row[16];

int m, n;
int store[16];
int size;
int cur;
bool c[300];

inline bool check()
{
	for (int i = 0; i < n; i++) {
		if (!c[i]) {
			return false;
		}
	}
	return true;
}

inline int next()
{
	for (int i = 0; i < row[cur].size; i++) {
		if (c[row[cur].mark[i]]) {
			return 100;
		}
	}
	return cur;
}

inline void clear()
{
	for (int i = 0; i < row[store[size - 1]].size; i++) {
		c[row[store[size - 1]].mark[i]] = false;
	}
}

int main()
{
    while (cin >> m >> n) {
        for (int i = 0; i < m; i++) {
            row[i].size = 0;
        }
        bool v;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v;
                if (v) {
                   row[i].mark[row[i].size++] = j;
                }
            }
        }
        size = 0;
        store[size++] = 0;

        for (int i = 0; i < n; i++) {
        	c[i] = false;
        }
        for (int i = 0; i < row[0].size; i++) {
        	c[row[0].mark[i]] = true;
        }
        if (check()) {
        	cout << "Yes, I found it" << endl;
        	continue;
        }
        cur = 1;
        while (1) {
        	while (cur < m && next() == 100) {
        		cur++;
        	}
        	if (cur >= m) {
        		if (!size) {
        			cout << "It is impossible" << endl;
        			break;
        		}
        		clear();
        		cur = store[size - 1] + 1;
        		size--;
        	}
        	else {
        		for (int i = 0; i < row[cur].size; i++) {
        			c[row[cur].mark[i]] = true;
        		}
        		store[size++] = cur;
        		if (check()) {
        			cout << "Yes, I found it" << endl;
        			break;
        		}
        		else {
        			if (cur == m - 1) {
        				if (size == 1) {
        					cout << "It is impossible" << endl;
        					break;
        				}
        				clear();
        				size--;
        				clear();
        				cur = store[size - 1] + 1;
        				size--;
        			}
        			else {
        				cur++;
        			}
        		}
        	}
        }
   }
   return 0;
}
