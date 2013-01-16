/**********************************************************************
* Compute shortest path with negtive edges with Bellman-Ford algorithm*
**********************************************************************/

//Include Bellman-Ford.h
#include "Bellman-Ford.h"
#include <iostream>

using namespace std;

Bellman_graph::Bellman_graph(int node_num, int edge_num, int source, int destination, int implementation) : Graph(node_num, edge_num, 1, 1, implementation)
{
	src = source;
	dest = destination;
}

Bellman_graph::~Bellman_graph()
{
}

void Bellman_graph::init()
{
	for (int i = 0; i < node_num; i++) {
		distance[i] = Graph::INFINITY;
	}
	distance[src] = 0;
}


bool Bellman_graph::check() const
{
	vector<int> adj_nodes;
	for (int i = 0; i < node_num; i++) {
		adj_nodes = get_adjacent_node(i);
		for (int j = 0; j < adj_nodes.size(); j++) {
			if (distance[adj_nodes[j]] > distance[i] + get_weight(i, adj_nodes[j])) {
				return false;
			}
		}
	}
	return true;
}

void Bellman_graph::compute()
{
	vector<int> adj_nodes;
	init();
	for (int k = 0; k < node_num; k++) {
	for (int i = 0; i < node_num; i++) {
		adj_nodes = get_adjacent_node(i);
		for (int j = 0; j <adj_nodes.size(); j++) {
			relax(i, adj_nodes[j]);
		}
	}
	}
	if (!check()) {
		cout << "Oops!There is negtive cycles!" << endl;
	}
	cout << "The shortest path is: ";
	cout << distance[dest] << endl;
	
	cout << "To all the nodes: " << endl;
	for (int i = 0; i < node_num; i++) {
		cout << i << ": " << distance[i] << endl;
	}
}
