#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Data {
	int num;
	int start;
	int end;
};

Data data[1000];
int colNum, dataSize;
unsigned long rowNum;

// If is in left edge
bool isLeftEdge(int pos) {
	return (pos % colNum == 0);
}

// If is in right edge
bool isRightEdge(int pos) {
	return (pos % colNum == (colNum - 1));
}

// If is in upper edge
bool isUpperEdge(int pos) {
	return (pos < colNum);
}

// If is bottom edge
bool isLowerEdge(int pos) {
	return (pos / colNum) == (rowNum - 1);
}

int valueInPos(int posInImage, int posInData, int num, int pos) {
	int curPos = posInData;
	
	switch (pos) {
		case 0:
		case 1:
		case 2:
		case 7:
			while (posInImage < data[curPos].start) {
				curPos--;
			}
			return fabs(num - data[curPos].num);
		case 3:
		case 4:
		case 5:
		case 6:
			while (posInImage > data[curPos].end) {
				curPos++;
			}
			return fabs(num - data[curPos].num);
	}
}

int findLocal(int posInImage, int posInData, int num, int pos) {
	switch (pos) {
		// left upper corner
		case 0:
			if (isUpperEdge(posInImage) || isLeftEdge(posInImage)) {
				return -1;
			} else {
				return valueInPos(posInImage - colNum - 1, posInData, num, pos);
			}
		// Upper 
		case 1:
			if (isUpperEdge(posInImage)) {
				return -1;
			} else {
				return valueInPos(posInImage - colNum, posInData, num, pos);
			}
		// Right upper corner
		case 2:
			if (isUpperEdge(posInImage) || isRightEdge(posInImage)) {
				return -1;
			} else {
				return valueInPos(posInImage - colNum + 1, posInData, num, pos);
			}
		// Right 
		case 3:
			if (isRightEdge(posInImage)) {
				return -1;
			} else {
				return valueInPos(posInImage + 1, posInData, num, pos);
			}
		// Right lower corner
		case 4:
			if (isRightEdge(posInImage) || isLowerEdge(posInImage)) {
				return -1;
			} else {
				return valueInPos(posInImage + colNum + 1, posInData, num, pos);
			} 
		// Lower
		case 5:
			if (isLowerEdge(posInImage)) {
				return -1;
			} else {
				return valueInPos(posInImage + colNum, posInData, num, pos);
			}
		// Left lower
		case 6:
			if (isLowerEdge(posInImage) || isLeftEdge(posInImage)) {
				return -1;
			} else {
				return valueInPos(posInImage + colNum - 1, posInData, num, pos);
			}
		// Left
		case 7:
			if (isLeftEdge(posInImage)) {
				return -1;
			} else {
				return valueInPos(posInImage - 1, posInData, num, pos);
			}
	}
}


// Find the max diff given position in image, position in data and its number
int findMax(int posInImage, int posInData, int num) {
	int left, leftUpper, leftLower, upper, lower, rightUpper, right, rightLower;
	int maxVal = -2;
	
	for (int i = 0; i < 8; i++) {
		maxVal = max(maxVal, findLocal(posInImage, posInData, num, 0));
	}

	return maxVal;
}

// Solve the problem
void solve() {

}

int main() {
	int dataNum;
	int dataCount;
	int start;
	unsigned long pixelNum;
	
	while (cin >> colNum) {
		if (!colNum) {
			break;
		}
		dataSize = 0;
		start = 0;
		pixelNum = 0;
		while (cin >> dataNum >> dataCount) {
			if (!dataNum && !dataCount) {
				break;
			}
			data[dataSize].num = dataNum;
			data[dataSize].start = start;
			data[dataSize].end = start + dataCount - 1;
			start = start + dataCount - 1;
			dataSize++;
			pixelNum += dataCount;
		}
		rowNum = pixelNum / colNum;
		cout << colNum << endl;
		solve();
		cout << "0 0" << endl;
	}
	cout << "0" << endl;
	return 0;
}
