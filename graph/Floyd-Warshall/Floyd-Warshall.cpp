/*************************************************************
* Compute all pair shortest path by Floyd-Warshall algorithm *
*************************************************************/

#include "graph.h"
#include <iostream>
#define V_NUM 100

using namespace std;

int d[V_NUM][V_NUM][V_NUM];

void init(const Graph& g, const int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
				d[i][j][0] = g.get_weight(i, j);
		}
	}
}

void Floyd_Warshall(const int n)
{
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][k][k - 1] == INT_MAX || d[k][j][k - 1] == INT_MAX) {
					d[i][j][k] = d[i][j][k - 1];
				}
				else {
					int min = d[i][j][k - 1] < d[i][k][k - 1] + d[k][j][k - 1] ? d[i][j][k - 1] : d[i][k][k - 1] + d[k][j][k - 1];
					d[i][j][k] = min;
				}
			}
		}
	}
}

int main()
{
	cout << INT_MAX << endl;
	Graph g(6, 10, 1, 1, 1);
	g.construct();
	init(g, 6);
	Floyd_Warshall(6);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << i << " " << j << " " << d[i][j][6 - 1] << endl;
		}
	}
}
