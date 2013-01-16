#include <iostream>
#include "graph.h"
#include <vector>

using namespace std;

Graph::Graph(int node_num, int edge_num, int weighted, int directed, int implementation)
{
    this->node_num = node_num;
    this->edge_num = edge_num;
    this->is_directed = directed;
    this->is_weighted = weighted;
    this->implementation = implementation;
    matrix_node = NULL;
    list_node = NULL;
    distance = NULL;
}

void Graph::construct()
{
    int x, y, weight;
    //Adjacency Matrix
    distance = new int[node_num];
    
    if (implementation == Graph::MATRIX) {
        matrix_node = new int*[node_num];
        for (int i = 0; i < node_num; i++) {
            matrix_node[i] = new int[node_num];
            for (int j = 0; j < node_num; j++) {
                matrix_node[i][j] = Graph::INFINITY;
            }
        }

        if (is_weighted == Graph::WEIGHTED) {
            cout << "Please input edge and weight (starting node and ending node and weight)" << endl;
            for (int i = 0; i < edge_num; i++) {
                cin >> x >> y >> weight;
                if (x >= node_num || y >= node_num) {
                    cout << "Node number too large! Input again." << endl;
                    i--;
                }
                else {
                    if (is_directed == Graph::DIRECTED) {
                        matrix_node[x][y] = weight;
                    }
                    else {
                        matrix_node[x][y] = matrix_node[y][x] = weight;
                    }
                }
            }
        }
        else {
            cout << "Please input edge (starting node and ending node)" << endl;
            for (int i = 0; i < edge_num; i++) {
                cin >> x >> y;
                if (x >= node_num || y >= node_num) {
                    cout << "Node number too large! Input again." << endl;
                    i--;
                }
                else {
                    if (is_directed == Graph::DIRECTED) {
                        matrix_node[x][y] = 1;
                    }
                    else {
                        matrix_node[x][y] = matrix_node[y][x] = 1;
                    }
                }
            }
        }
    }
    //Adjacency list implementation
    else {
        list_node = new Node*[node_num];
        for (int i = 0; i < node_num; i++) {
            list_node[i] = NULL;
        }
        if (is_weighted == Graph::WEIGHTED) {
            cout << "Please input edge and weight (starting node and ending node and weight)" << endl;
            for (int i = 0; i < edge_num; i++) {
                cin >> x >> y >> weight;
                if (x >= node_num || y >= node_num) {
                    cout << "Node number too large! Input again." << endl;
                    i--;
                }
                else {
                    if (is_directed == Graph::DIRECTED) {
                        Node *new_node = makenode(y, weight);
                        add_node(x, new_node);
                    }
                    else {
                        Node *new_node = makenode(y, weight);
                        add_node(x, new_node);
                        new_node = makenode(x, weight);
                        add_node(y, new_node);
                    }
                }
            }
        }
        else {
            cout << "Please input edge (starting node and ending node)" << endl;
            for (int i = 0; i < edge_num; i++) {
                cin >> x >> y;
                if (x >= node_num || y >= node_num) {
                    cout << "Node number too large! Input again." << endl;
                    i--;
                }
                else {
                    if (is_directed == Graph::DIRECTED) {
                        Node *new_node = makenode(y, 0);
                        add_node(x, new_node);
                    }
                    else {
                        Node *new_node = makenode(y, 0);
                        add_node(x, new_node);
                        new_node = makenode(x, 0);
                        add_node(y, new_node);
                    }
                }
            }
        }
    }
}

inline int Graph::get_edge_num()
{
    return edge_num;
}

inline int Graph::get_node_num()
{
    return node_num;
}

vector<int> Graph::get_adjacent_node(int node) const
{
    vector<int> adjacent_node;
    if (implementation == Graph::MATRIX) {
        for (int i = 0; i < node_num; i++) {
            if (matrix_node[node][i] != Graph::INFINITY) {
                adjacent_node.push_back(i);
            }
        }
        return adjacent_node;
    }
    else {
        Node *p = list_node[node];
        while (p) {
            adjacent_node.push_back(p->id);
            p = p->next;
        }
        return adjacent_node;
    }
}

int Graph::get_weight(int u, int v) const
{
	if (u == v) {
		return 0;
	}
    if (implementation == Graph::MATRIX) {
        return matrix_node[u][v];
    }
    else {
        Node* p = list_node[u];
        while (p && p->id != v) {
            p = p->next;
        }
        if (p == NULL) {
            return Graph::INFINITY;
        }
        else {
            return p->weight;
        }
    }
}

void Graph::relax(int u, int v)
{
	if (distance[v] > distance[u] + get_weight(u, v)) {
		distance[v] = distance[u] + get_weight(u, v);
	}
}

Graph::~Graph()
{
	if (distance != NULL) {
		delete []distance;
		if (implementation) {
			for (int i = 0; i < node_num; i++) {
				delete matrix_node[i];
			}
			delete []matrix_node;
		}
		else {
			Node *cur, *pre;
			for (int i = 0; i < node_num; i++) {
				pre = cur = list_node[i];
				while (cur != NULL) {
					cur = pre->next;
					delete pre;
					pre = cur;
				}
			}
			delete []list_node;
		}
	}
}

