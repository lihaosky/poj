#include <iostream>
#include <vector>

#define INFINITE 1000000

using namespace std;

struct Container {
	int weight;
	int id;
	int neighbor;
};
struct Vertex {
	int id;
	int weight;
	Vertex* next;
};
bool isVisited[100];

class Graph {
private:
	Vertex* vertex[100];
	int size;

public:
	Graph(int size) {
		this->size = size;
		for (int i = 0; i < size; i++) {
			vertex[i] = NULL;
		}
	}
	~Graph() {
		Vertex *p, *q;
		for (int i = 0; i < size; i++) {
			q = p = vertex[i];
			while (p) {
				q = p->next;
				delete(p);
				p = q;
			}
		}
	}
	void insert(int i, int j, int weight) {
		Vertex* tmp1 = new Vertex;
		tmp1->id = i;
		tmp1->weight = weight;
		tmp1->next = NULL;
		if (vertex[j] == NULL) {
			vertex[j] = tmp1;
		}
		else {
			tmp1->next = vertex[j];
			vertex[j] = tmp1;
		}
		Vertex* tmp2 = new Vertex;
		tmp2->id = j;
		tmp2->weight = weight;
		tmp2->next = NULL;
		if (vertex[i] == NULL) {
			vertex[i] = tmp2;
		}
		else {
			tmp2->next = vertex[i];
			vertex[i] = tmp2;
		}
	}
	vector<Vertex> getNeighbor(int id) {
		vector<Vertex> neighbors;
		Vertex* head = vertex[id];
		while (head) {
			neighbors.push_back(*head);
			head = head->next;
		}
		return neighbors;
	}
	void printGraph() {
		Vertex* p;
		for (int i = 0; i < size; i++) {
			cout << i << ": ";
			p = vertex[i];
			while (p) {
				cout << p->id << " ";
				p = p->next;
			}
			cout << endl;
		}
	}
};

class Heap {
private:
	int size;
	Container container[101];
	int idPos[100];
public:
	Heap() {
		size = 0;
	}
	void push(int id, int weight, int neighbor) {
		size++;
		container[size].weight = weight;
		container[size].id = id;
		container[size].neighbor = neighbor;
		idPos[id] = size;
		int tmpSize = size;
		while (tmpSize != 0 && container[tmpSize].weight < container[tmpSize / 2].weight) {
			Container tmp = container[tmpSize];
			idPos[container[tmpSize / 2].id] = tmpSize;
			idPos[container[tmpSize].id] = tmpSize / 2;
			container[tmpSize] = container[tmpSize / 2];
			container[tmpSize / 2] = tmp;
			tmpSize /= 2;
		}
	}
	void decrease(int id, int weight, int neighbor) {
		container[idPos[id]].weight = weight;
		container[idPos[id]].neighbor = neighbor;
		int tmpPos = idPos[id];
		while (tmpPos != 0 && container[tmpPos].weight < container[tmpPos / 2].weight) {
			Container tmp = container[tmpPos];
			idPos[container[tmpPos / 2].id] = tmpPos;
			idPos[container[tmpPos].id] = tmpPos / 2;
			container[tmpPos] = container[tmpPos / 2];
			container[tmpPos / 2] = tmp;
			tmpPos /= 2;
		}
	}
	Container extract() {
		Container tmp = container[1];
		container[1] = container[size--];
		idPos[container[1].id] = 1;
		int tmpPos = 1;
		while (tmpPos * 2 <= size) {
			Container cand;
			int pos;
			if (tmpPos * 2 + 1 <= size) {
				if (container[tmpPos * 2].weight < container[tmpPos * 2 + 1].weight) {
					cand = container[tmpPos * 2];
					pos = tmpPos * 2;
				}
				else {
					cand = container[tmpPos * 2 + 1];
					pos = tmpPos * 2 + 1;
				}
			}
			else {
				cand = container[tmpPos * 2];
				pos = tmpPos * 2;
			}
			if (container[tmpPos].weight > cand.weight) {
				idPos[container[tmpPos].id] = pos;
				idPos[cand.id] = tmpPos;
				container[pos] = container[tmpPos];
				container[tmpPos] = cand;
				tmpPos = pos;
			}
			else {
				break;
			}
		}
		return tmp;
	}
	bool isEmpty() {
		return size == 0 ? true : false;
	}
	int getWeight(int id) {
		return container[idPos[id]].weight;
	}
	void printHeap() {
		for (int i = 1; i <= size; i++) {
			cout << container[i].id << " " << container[i].weight << endl;
		}
	}
};



int main()
{	
	int vsize, esize, v1, v2, w, total;
	total = 0;
	cin >> vsize >> esize;
	Graph graph(vsize);
	Graph mst(vsize);
	Heap heap;
	for (int i = 0; i < vsize; i++) {
		isVisited[i] = false;
	}
	for (i = 1; i < vsize; i++) {
		heap.push(i, INFINITE, -1);
	}
	for (i = 0; i < esize; i++) {
		cin >> v1 >> v2 >> w;
		graph.insert(v1, v2, w);
	}
	isVisited[0] = true;
	vector<Vertex> neighbors = graph.getNeighbor(0);
	for (i = 0; i < neighbors.size(); i++) {
		heap.decrease(neighbors[i].id, neighbors[i].weight, 0);
	}
	while (heap.isEmpty() == false) {
		Container tmp = heap.extract();
		total += tmp.weight;
		mst.insert(tmp.id, tmp.neighbor, tmp.weight);
		isVisited[tmp.id] = true;
		vector<Vertex> nei = graph.getNeighbor(tmp.id);
		for (i = 0; i < nei.size(); i++) {
			if (isVisited[nei[i].id] == false && nei[i].weight < heap.getWeight(nei[i].id)) {
				heap.decrease(nei[i].id, nei[i].weight, tmp.id);
			}
		}
	}
	cout << "Total weight is: " << total << endl;
	cout << "The tree is: " << endl;
	mst.printGraph();
	return 0;
}
