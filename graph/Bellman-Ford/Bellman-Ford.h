#ifndef BELLMAN_FORD_H__
#define BELLMAN_FORD_H__
#include "graph.h"

class Bellman_graph : public Graph
{
private:
	int src;
	int dest;
	void init();
	bool check() const;
public:
	Bellman_graph(int, int, int, int, int);
	~Bellman_graph();
	void compute();
};

#endif
