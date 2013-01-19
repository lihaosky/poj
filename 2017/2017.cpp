#include <iostream>

using namespace std;

int n, s, h, t, ph;

int main() {
	while (1) {
		cin >> n;
		if (n == -1) {
			return 0;
		}
		t = 0;
		for (int i = 0; i < n; i++) {
			cin >> s >> h;
			if (i == 0) {
				t += s * h;
			} else {
				t += s * (h - ph);
			}
			ph = h;
		}
		cout << t << " miles" << endl;
	}
	return 0;
}
