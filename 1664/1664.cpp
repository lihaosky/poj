#include <iostream>

using namespace std;

int t, m, n, count;

void compute(int left, int bound, int depth) {
	if (depth == n - 1 && left > bound) {
		return;
	}
	if (depth == n - 1) {
		count++;
		return;
	}
	for (int i = 0; i <= left && i <= bound; i++) {
		compute(left - i, i, depth + 1);
	}
}

void solve() {
	compute(m, m, 0);
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n;
		count = 0;
		solve();
		cout << count << endl;
	}
	return 0;
}
