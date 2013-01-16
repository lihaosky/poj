/***************************************************
* Compute maximum flow with Edmonds-Karp algorithm *
***************************************************/

#include <iostream>
#include <queue>
#include <cstring>
#define V_NUM 100

using namespace std;

int graph[V_NUM][V_NUM];
int e_num, v_num;
bool is_used[V_NUM];
int parent[V_NUM];
int mf = 0;

void init()
{
	for (int i = 0; i < e_num; i++) {
		for (int j = 0; j < e_num; j++) {
			graph[i][j] = 0;
		}
	}
}

bool find_path()
{
	for (int i = 0; i < v_num; i++) {
		is_used[i] = false;
	}
	queue<int> s_path;
	bool is_exist = false;
	bool is_found = false;
	is_used[0] = true;
	s_path.push(0);
	do {
		is_exist = false;
		int v = s_path.front();
		s_path.pop();
		for (int i = 0; i < v_num; i++) {
			if (!is_used[i] && graph[v][i] > 0) {
				is_exist = true;
				if (i == v_num - 1) {
					parent[i] = v;
					is_found = true;
					break;
				}
				else {
					s_path.push(i);
					parent[i] = v;
					is_used[i] = true;
				}
			}
		}
		if (is_found) {
			break;
		}
	} while (!s_path.empty());
	//No path
	if (!is_exist) {
		return false;
	}
	int min = graph[parent[v_num - 1]][v_num - 1];
	int pre = parent[v_num - 1];
	int cur = v_num - 1;
	//Find minimum edge weight on the path
	while (cur) {
		if (min > graph[pre][cur]) {
			min = graph[pre][cur];
		}
		cur = pre;
		pre = parent[cur];
	}
	mf += min;
	pre = parent[v_num - 1];
	cur = v_num - 1;
	//Update all the edges
	while (cur) {
		graph[pre][cur] -= min;
		graph[cur][pre] += min;
		cur = pre;
		pre = parent[cur];
	}
	return true;
}

void Edmonds_Karp()
{
	while (find_path());
}

int main()
{
	int u, v, w;
	cin >> v_num >> e_num;
	//Source is 0 and sink is v_num - 1
	for (int i = 0; i < e_num; i++) {
		cin >> u >> v >> w;
		graph[u][v] = w;
		graph[v][u] = 0;
	}
	Edmonds_Karp();
	cout << "Maximum flow: " << mf << endl;
}
