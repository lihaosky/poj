/*
Distance on Chessboard
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 12790		Accepted: 4464

Description
国际象棋的棋盘是黑白相间的8 * 8的方格，棋子放在格子中间。如下图所示：

王、后、车、象的走子规则如下：

    * 王：横、直、斜都可以走，但每步限走一格。
    * 后：横、直、斜都可以走，每步格数不受限制。
    * 车：横、竖均可以走，不能斜走，格数不限。
    * 象：只能斜走，格数不限。



写一个程序，给定起始位置和目标位置，计算王、后、车、象从起始位置走到目标位置所需的最少步数。

Input
第一行是测试数据的组数t（0 <= t <= 20）。以下每行是一组测试数据，每组包括棋盘上的两个位置，第一个是起始位置，第二个是目标位置。位置用"字母-数字"的形式表示，字母从"a"到"h"，数字从"1"到"8"。

Output
对输入的每组测试数据，输出王、后、车、象所需的最少步数。如果无法到达,就输出"Inf".

Sample Input

2
a1 c3
f5 f8

Sample Output

2 1 2 1
3 1 1 Inf

Source
POJ Monthly--2004.05.15 Liu Rujia@POJ
*/

//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: MAY 16TH 2009
#include <iostream>
using namespace std;
int main()
{
	int testCase;
	char startPosition[2];
	char endPosition[2];
	int startRow, startCol, endRow, endCol;
	int kingMove, queenMove, rookMove, bishopMove;
	cin >> testCase;
	while (testCase--){
		cin >> startPosition >> endPosition;
		bishopMove = -1;
		startRow = startPosition[0] - 96;
		startCol = startPosition[1] - 48;
		endRow = endPosition[0] - 96;
		endCol = endPosition[1] - 48;
		int rowDiff = startRow > endRow ? (startRow - endRow) : (endRow - startRow);
		int colDiff = startCol > endCol ? (startCol - endCol) : (endCol - startCol);
		kingMove = rowDiff > colDiff ? rowDiff : colDiff;
		if ( startRow == endRow || startCol == endCol){
			if (startRow == endRow && startCol == endCol){
				queenMove = rookMove = bishopMove = 0;
			}
			else{
			    queenMove = rookMove = 1;
			}
		}
		else{
			rookMove = 2;
			if (rowDiff == colDiff){
				queenMove = 1;
				bishopMove = 1;
			}
			else{
				queenMove = 2;
			}
		}
		if (bishopMove != -1){
			cout << kingMove << " " << queenMove << " " << rookMove << " " << bishopMove << endl;
		}
		else{
			if ((startRow + startCol) % 2 == (endRow + endCol ) % 2){
				cout << kingMove << " " << queenMove << " " << rookMove << " " << 2 << endl;
			}
			else{
				cout << kingMove << " " << queenMove << " " << rookMove << " " << "Inf" << endl;
			}
		}
	}
}
