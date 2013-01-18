#include <iostream>
#include <algorithm>

using namespace std;

struct Cake {
	bool used;
	int size;
	int llx;
	int lly;
	int urx;
	int ury;
};

int testNum, cakeNum, bigCakeSize;
Cake cakes[16];

bool cmp(Cake c1, Cake c2) {
	return c1.size > c2.size;
}

bool check(int num, int llx, int lly, int urx, int ury) {
	for (int i = 0; i < cakeNum; i++) {
		if (i == num || !cakes[i].used) {
			continue;
		}
		if (!(llx >= cakes[i].urx || urx <= cakes[i].llx || lly >= cakes[i].ury || ury <= cakes[i].lly)) {
			return false;
		}
	}
	return true;
}

bool dfs(int num) {
	if (num >= cakeNum) {
		return true;
	}
	for (int i = 0; i < cakeNum; i++) {
		if (cakes[i].used || (i != 0 && cakes[i - 1].size == cakes[i].size && !cakes[i - 1].used && !cakes[i].used)) {
			continue;
		}
		bool f = false;
		for (int x = 0; x <=  bigCakeSize - cakes[i].size; x++) {
			for (int y = 0; y <= bigCakeSize - cakes[i].size; y++) {
				// This can fit
				if (check(i, x, y, x + cakes[i].size, y + cakes[i].size)) {
					cakes[i].used = true;
					cakes[i].llx = x;
					cakes[i].lly = y;
					cakes[i].urx = x + cakes[i].size;
					cakes[i].ury = y + cakes[i].size;
					if (dfs(num + 1)) {
						return true;
					}
					cakes[i].used = false;
					f = true;
					break;
				}
			}
			if (f) {
				break;
			}
		}
	}
	return false;
}

void solve() {
	if (dfs(0)) {
		cout << "KHOOOOB!" << endl;
	} else {
		cout << "HUTUTU!" << endl;
	}
}



int main() {
	int totalSize;
	cin >> testNum;
	for (int i = 0; i < testNum; i++) {
		totalSize = 0;
		cin >> bigCakeSize >> cakeNum;
		for (int j = 0; j < cakeNum; j++) {
			cin >> cakes[j].size;
			totalSize += (cakes[j].size * cakes[j].size);
			cakes[j].used = false;
		}
		if (totalSize != bigCakeSize * bigCakeSize) {
			cout << "HUTUTU!" << endl;
			continue;
		}
		sort(cakes, cakes + cakeNum, cmp);
		solve();
	}
	return 0;
}
		
