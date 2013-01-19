#include <iostream>
#include <cstring>

using namespace std;

bool used[10001];

int digitSum(int a) {
	int s = 0;
	while (a) {
		s += a % 10;
		a = a / 10;
	}
	return s;
}

void find(int a, bool isFirst) {
	if (a > 10000) {
		return;
	}
	if (!isFirst) {
		used[a] = true;
	} 
	find(a + digitSum(a), false);
}

int main() {
	memset(used, 0, sizeof(used));
	for (int i = 1; i < 10001; i++) {
		find(i, true);
	}
	for (int i = 1; i < 10001; i++) {
		if (!used[i]) {
			cout << i << endl;
		}
	}
	return 0;
}
