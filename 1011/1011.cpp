#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool used[64];
int sticks[64], n, level, num, len;

bool cmp(int a, int b) {
    return a > b;
}

bool dfs(int start, int left, int lel) {
	if (left == 0) {
		if (lel == level - 2) {
			return true;
		}
		int i;
		for (i = 0; used[i]; i++);
		used[i] = true;
		if (dfs(i + 1, len - sticks[i], lel + 1)) {
			return true;
		}
		used[i] = false;
		return false;
	} else {
		if (start >= num) {
			return false;
		}
		for (int i = start; i < num; i++) {
			if (used[i]) {
				continue;
			}
			if (sticks[i] == sticks[i - 1] && !used[i - 1]) {
				continue;
			}
			if (sticks[i] > left) {
				continue;
			}
			used[i] = true;
			if (dfs(i + 1, left - sticks[i], lel)) {
				return true;
			}
			used[i] = false;
		}
		return false;
	}		
}

int main() {
	while (cin >> num) {
		if (num == 0) {
			break;
		}
		
		int sum = 0;
		for (int i = 0; i < num; i++) {
			cin >> sticks[i];
			sum += sticks[i];
		}
		sort(sticks, sticks + num, cmp);
		bool end = false;
		for (len = sticks[0]; len <= sum / 2; len++) {
			if (sum % len == 0) {
				level = sum / len;
				used[0] = true;
				if (dfs(1, len - sticks[0], 0)) {
					end = true;
					cout << len << endl;
					break;
				}
				used[0] = false;
			}
		}
		if (!end) {
			cout << sum << endl;
		}
		memset(used, 0, 64);
	}
	return 0;
}
