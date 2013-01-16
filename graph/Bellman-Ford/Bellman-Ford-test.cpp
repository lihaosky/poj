#include "Bellman-Ford.h"
#include <iostream>

using namespace std;

int main()
{
	//node number, edge number, src, destination, implementation = matrix
	Bellman_graph bg(5, 10, 0, 3, 1);
	bg.construct();
	bg.compute();
}
