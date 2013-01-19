#include <iostream>
#include <cmath>

using namespace std;

string ip;
int n;

int convert(int s, int e) {
	int i = 0, o = 0;
	for (int j = s; j >= e; j--) {
		if (ip[j] == '1') {
			o += pow(2, i);
		}
		i++;
	}
	return o;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ip;
		cout << convert(7, 0) << "." << convert(15, 8) << "." << convert(23, 16) << "." << convert(31, 24) << endl;
	}
	return 0;
}
			
