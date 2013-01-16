#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <climits>
#include <iostream>

class Graph
{
private:
    //Adjacency Matrix implementation
    int **matrix_node;
    //Adjacency List implementation
    struct Node
    {
        int id;
        int weight;
        Node *next;
    };

    Node **list_node;
    
    Node* makenode(int id, int weight) {
        Node *tmp = new Node;
        tmp->id = id;
        tmp->weight = weight;
        tmp->next = NULL;
        return tmp;
    }
    
    void add_node(int id, Node* node)
	{
		if (list_node[id] != NULL) {
			node->next = list_node[id]->next;
		 list_node[id] = node;
		}
		else {
		 list_node[id] = node;
			node->next = NULL;
		}
	}

protected:
    //Edge number
    int edge_num;
    //Node number
    int node_num;
    int implementation;
    int is_directed;
    int is_weighted;	//distance to 
	int *distance;
	
public:
    static const int MATRIX = 1;
    static const int WEIGHTED = 1;
    static const int DIRECTED = 1;
    static const int INFINITY = INT_MAX;

    Graph(int node_num, int edge_num, int weighted, int directed, int implementation);
    ~Graph();
    void construct();
    int get_edge_num();
    int get_node_num();
    std::vector<int> get_adjacent_node(int) const;
    int get_weight(int, int) const;
    void relax(int, int);
};



#endif // GRAPH_H_
