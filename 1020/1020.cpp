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
bool used[41][41];

bool cmp(Cake c1, Cake c2) {
	return c1.size < c2.size;
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
	
	int y, x;
	for (y = 0; y < bigCakeSize; y++) {
		for (x = 0; x < bigCakeSize; x++) {
			if (!used[x][y]) {
				break;
			}
		}
		if (x != bigCakeSize) {
			break;
		}
	}
	
	int i;
	for (i = 0; i < cakeNum; i++) {
		if (!cakes[i].used) {
			break;
		}
	}
	if (y + cakes[i].size > bigCakeSize || x + cakes[i].size > bigCakeSize) {
		return false;
	}
	if (!check(i, x, y, x + cakes[i].size, y + cakes[i].size)) {
		return false;
	}
	
	cakes[i].used = true;
	cakes[i].llx = x;
	cakes[i].lly = y;
	cakes[i].urx = x + cakes[i].size;
	cakes[i].ury = y + cakes[i].size;
	for (int j = y; j < y + cakes[i].size; j++) {
		for (int k = x; k < x + cakes[i].size; k++) {
			used[k][j] = true;
		}
	}
	if (dfs(num + 1)) {
		return true;
	}
	for (int j = y; j < y + cakes[i].size; j++) {
		for (int k = x; k < x + cakes[i].size; k++) {
			used[k][j] = false;
		}
	}
	cakes[i].used = false;
	i++;
	for (; i < cakeNum; i++) {
		if (cakes[i].used || (i != 0 && cakes[i - 1].size == cakes[i].size && !cakes[i - 1].used)) {
			continue;
		}
		if (y + cakes[i].size > bigCakeSize || x + cakes[i].size > bigCakeSize) {
			break;
		}
		if (check(i, x, y, x + cakes[i].size, y + cakes[i].size)) {
			for (int j = y; j < y + cakes[i].size; j++) {
				for (int k = x; k < x + cakes[i].size; k++) {
					used[k][j] = true;
				}
			}
			cakes[i].used = true;
			cakes[i].llx = x;
			cakes[i].lly = y;
			cakes[i].urx = x + cakes[i].size;
			cakes[i].ury = y + cakes[i].size;
			if (dfs(num + 1)) {
				return true;
			}
			for (int j = y; j < y + cakes[i].size; j++) {
				for (int k = x; k < x + cakes[i].size; k++) {
					used[k][j] = false;
				}
			}
			cakes[i].used = false;
		} else {
			break;
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
		for (int j = 0; j < 41; j++) {
			for (int k = 0; k < 41; k++) {
				used[j][k] = false;
			}
		}
		sort(cakes, cakes + cakeNum, cmp);
		solve();
	}
	return 0;
}
		
