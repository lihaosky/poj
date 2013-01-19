#include <iostream>

using namespace std;

int m[100][100], n[100][100], s, l;

int main() {
	cin >> s;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> m[i][j];
			n[i][j] = -1;
		}
	}
	l = n[0][0] = m[0][0];
	for (int i = 1; i < s; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				n[i][0] = m[i][0] + n[i - 1][0];
			} else if (j == i) {
				n[i][i] = m[i][i] + n[i - 1][i - 1];
			} else {
				n[i][j] = max(n[i - 1][j - 1], n[i - 1][j]) + m[i][j];
			}
			l = max(l, n[i][j]);
		}
	}
	cout << l << endl;
}
			
