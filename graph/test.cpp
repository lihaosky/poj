#include <iostream>
#include "graph.h"
#include <vector>

using namespace std;


int main()
{
	Graph g(4, 3, 0, 0, 1);
	g.construct();
	
	vector<int> adj_nodes;
	adj_nodes = g.get_adjacent_node(0);
	for (int i = 0; i < adj_nodes.size(); i++) {
		cout << adj_nodes[i] << " ";
	}
	cout << endl;
}
