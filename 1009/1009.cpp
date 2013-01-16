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

// How many rows this number cover
int rowsCovered(int posInData) {
	if (data[posInData].end - data[posInData].start + 1 <= 2 * colNum + 3) {
		return 2;
	}
	
	int dist = data[posInData].end - data[posInData].start;
	if (dist % colNum == 0) {
		return dist / colNum + 1;
	}
	int col = dist / colNum;
	if (data[posInData].end % colNum < (data[posInData].start + (col + 1) * colNum)) {
		return col + 2;
	}
	return col + 1;
}

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
			return abs(num - data[curPos].num);
		case 3:
		case 4:
		case 5:
		case 6:
			while (posInImage > data[curPos].end) {
				curPos++;
				/*cout << "curPos is " << curPos << endl;
				cout << "pos is " << posInImage << endl;
				cout << "point is " << pos << endl;*/
			}
			return abs(num - data[curPos].num);
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
	int maxVal = -2;
	
	for (int i = 0; i < 8; i++) {
		maxVal = max(maxVal, findLocal(posInImage, posInData, num, i));
	}

	return maxVal;
}

// Solve the problem
void solve() {
	int lastNum, lastCount, firstEnd, firstStart;
	lastNum = -1;
	lastCount = -1;
	for (int i = 0; i < dataSize; i++) {
		int rows = rowsCovered(i);
		if (rows <= 2) {
			if (i == 0 && data[i].start % colNum == 0 && data[i].end % colNum == (colNum - 1) && i != dataSize - 1 && data[i+1].start % colNum == 0 && data[i+1].end % colNum == (colNum - 1)) {
				int num = findMax(data[i].start, i, data[i].num);
				if (lastNum == -1) {
					lastNum = num;
					lastCount = colNum;
				} else {
					if (lastNum == num) {
						lastCount += colNum;
					} else {
						cout << lastNum << " " << lastCount << endl;
						lastNum = num;
						lastCount = colNum;
					}
				}
				if (data[i].end - data[i].start > colNum - 1) {
					num = findMax(data[i].end, i, data[i].num);
					if (lastNum == num) {
						lastCount += colNum;
					} else {
						cout << lastNum << " " << lastCount << endl;
						lastNum = num;
						lastCount = colNum;
					}
				}
				continue;
			}
			if (i == 0 && i == dataSize - 1 && data[i].start % colNum == 0 && data[i].end % colNum == (colNum - 1)) {
				lastNum = 0;
				if (data[i].end - data[i].start > colNum - 1) {
					lastCount = colNum * 2;
				} else {
					lastCount = colNum;
				}
				continue;
			}
			if (i == dataSize - 1 && data[i].start % colNum == 0 && data[i].end % colNum == (colNum - 1) && data[i - 1].start % colNum == 0 && data[i - 1].end % colNum == (colNum - 1)) {
				int num = findMax(data[i].start, i, data[i].num);
				if (lastNum == -1) {
					lastNum = num;
					lastCount = colNum;
				} else {
					if (lastNum == num) {
						lastCount += colNum;
					} else {
						cout << lastNum << " " << lastCount << endl;
						lastNum = num;
						lastCount = colNum;
					}
				}
				if (data[i].end - data[i].start > colNum - 1) {
					num = findMax(data[i].end, i, data[i].num);
					if (lastNum == num) {
						lastCount += colNum;
					} else {
						cout << lastNum << " " << lastCount << endl;
						lastNum = num;
						lastCount = colNum;
					}
				}
				continue;
			}
			if (i != 0 && i != dataSize - 1 && data[i].start % colNum == 0 && data[i].end % colNum == (colNum - 1) && data[i - 1].start % colNum == 0 && data[i - 1].end % colNum == (colNum - 1) && data[i + 1].start % colNum == 0 && data[i + 1].end % colNum == (colNum - 1)) {
				int num = findMax(data[i].start, i, data[i].num);
				if (lastNum == -1) {
					lastNum = num;
					lastCount = colNum;
				} else {
					if (lastNum == num) {
						lastCount += colNum;
					} else {
						cout << lastNum << " " << lastCount << endl;
						lastNum = num;
						lastCount = colNum;
					}
				}
				if (data[i].end - data[i].start > colNum - 1) {
					num = findMax(data[i].end, i, data[i].num);
					if (lastNum == num) {
						lastCount += colNum;
					} else {
						cout << lastNum << " " << lastCount << endl;
						lastNum = num;
						lastCount = colNum;
					}
				}
				continue;
			}
			
			for (int j = data[i].start; j <= data[i].end; j++) {
				int num = findMax(j, i, data[i].num);
				if (lastNum == -1) {
					lastNum = num;
					lastCount = 0;
				}
				if (num == lastNum) {
					lastCount++;
				} else {
					cout << lastNum << " " << lastCount << endl;
					lastNum = num;
					lastCount = 1;
				}
			}
		}
		if (rows == 3) {
			bool lookAll = false;
			if (data[i].start % colNum == 0 && data[i].end % colNum != (colNum - 1) && data[i].start + colNum * 2 >= data[i].end) {
				lookAll = true;
			}
		 	if (data[i].start % colNum != 0 && data[i].end % colNum != (colNum - 1) && data[i].start + colNum * 2 > (data[i].end - 2)) {
		 		lookAll = true;
		 	} 
		 	if (data[i].end % colNum == (colNum - 1) && data[i].start % colNum != 0 && data[i].start + colNum * 2 >= data[i].end) {
		 		lookAll = true;
		 	}
		 	if (lookAll) {
				for (int j = data[i].start; j <= data[i].end; j++) {
					int num = findMax(j, i, data[i].num);
					if (lastNum == -1) {
						lastNum = num;
						lastCount = 0;
					}
					if (num == lastNum) {
						lastCount++;
					} else {
						cout << lastNum << " " << lastCount << endl;
						lastNum = num;
						lastCount = 1;
					}
				}
			} else {
				if (data[i].start % colNum == 0 && data[i].end % colNum == (colNum - 1)) {
					firstEnd = data[i].start + colNum - 1;
					firstStart = data[i].start + colNum * 2;
				} 
				if (data[i].start % colNum == 0 && data[i].end % colNum != (colNum - 1)) {
					firstEnd = data[i].start + colNum - 1;
					firstStart = data[i].end - colNum;
				} 
				if (data[i].start % colNum != 0 && data[i].end % colNum == (colNum - 1)) {
					firstEnd = data[i].start + colNum;
					firstStart = data[i].end - colNum + 1;
				}
				if (data[i].start % colNum != 0 && data[i].end % colNum != (colNum - 1)) {
					firstEnd = data[i].start + colNum;
					firstStart = data[i].end - colNum;
				}
				for (int j = data[i].start; j <= firstEnd; j++) {
					int num = findMax(j, i, data[i].num);
					if (lastNum == -1) {
						lastNum = num;
						lastCount = 0;
					} 
					if (num == lastNum) {
						lastCount++;
					} else {
						cout << lastNum << " " << lastCount << endl;
						lastNum = num;
						lastCount = 1;
					}
				}
				int count = firstStart - firstEnd - 1;
				if (lastNum == 0) {
					lastCount += count;
				} else {
					cout << lastNum << " " << lastCount << endl;
					lastNum = 0;
					lastCount = count;
				}
				for (int j = firstStart; j <= data[i].end; j++) {
					int num = findMax(j, i, data[i].num);
					if (lastNum == -1) {
						lastNum = num;
						lastCount = 0;
					} 
					if (num == lastNum) {
						lastCount++;
					} else {
						cout << lastNum << " " << lastCount << endl;
						lastNum = num;
						lastCount = 1;
					}
				}	
			}
		}
		if (rows >= 4) {
			if (data[i].start % colNum == 0) {
				firstEnd = data[i].start + colNum - 1;
			} else {
				firstEnd = data[i].start + colNum;
			}
			if (data[i].end % colNum == (colNum - 1)) {
				firstStart = data[i].end - colNum + 1;
			} else {
				firstStart = data[i].end - colNum;
			}
			for (int j = data[i].start; j <= firstEnd; j++) {
				int num = findMax(j, i, data[i].num);
				if (lastNum == -1) {
					lastNum = num;
					lastCount = 0;
				} 
				if (num == lastNum) {
					lastCount++;
				} else {
					cout << lastNum << " " << lastCount << endl;
					lastNum = num;
					lastCount = 1;
				}
			}
			int count = firstStart - firstEnd - 1;
			if (lastNum == 0) {
				lastCount += count;
			} else {
				cout << lastNum << " " << lastCount << endl;
				lastNum = 0;
				lastCount = count;
			}
			for (int j = firstStart; j <= data[i].end; j++) {
				int num = findMax(j, i, data[i].num);
				if (lastNum == -1) {
					lastNum = num;
					lastCount = 0;
				} 
				if (num == lastNum) {
					lastCount++;
				} else {
					cout << lastNum << " " << lastCount << endl;
					lastNum = num;
					lastCount = 1;
				}
			}
		}
	}
	cout << lastNum << " " << lastCount << endl;
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
			start = start + dataCount;
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
