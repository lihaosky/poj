/**************************************************
* This is the tictactoe game, AI vs Human
* No one will win if both take best moves
*
* AUTHOR: LIHAO
* DATE: 8th, OCTOBER 2009
* VENUE: DORM
*
**************************************************/
#include <iostream>

using namespace std;


/*
* Display board
*/
void display(char board[][3])
{
    cout << "  0   1   2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << (char)(i + 97) << " ";
        for (int j = 0; j < 3; j++) {
            if (j != 2) {
                cout << board[i][j] << " | ";
            }
            else {
                cout << board[i][j] << endl;
            }
        }
        cout << "  ";
        if (i != 2) {
            for (int j = 0; j < 5; j++) {
                if (j % 2 == 1) {
                    cout << "+ ";
                }
                else {
                    cout << "- ";
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}

/*
* Check if certain player wins
*/
bool isWin(char board[][3], char piece)
{
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == piece && board[i][1] == piece && board[i][2] == piece) {
            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] == piece && board[1][j] == piece && board[2][j] == piece) {
            return true;
        }
    }

    if (board[0][0] == piece && board[1][1] == piece && board[2][2] == piece) {
        return true;
    }
    if (board[0][2] == piece && board[1][1] == piece && board[2][0] == piece) {
        return true;
    }
    return false;
}

/*
* Check if it is draw
*/
bool isDraw(char board[][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

/*
* Copy a board
*/
void copy(char model[][3], char des[][3])
{
    char a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            des[i][j] = model[i][j];
        }
    }
}

/*
* Core part, determine best moves for AI
*/
int compute(char board[][3], char AIPiece, char HumanPiece, int& x, int& y, int state)
{
    if (isDraw(board)) {
        return 0;
    }
    if (state) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    char cBoard[3][3];
                    copy(board, cBoard);
                    cBoard[i][j] = AIPiece;
                    if (isWin(cBoard, AIPiece)) {
                        return 1;
                    }
                }
            }
        }
        int curBest = -1;
        int curX;
        int curY;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    char cBoard[3][3];
                    copy(board, cBoard);
                    cBoard[i][j] = AIPiece;
                    int cur = compute(cBoard, AIPiece, HumanPiece, x, y, 1 - state);
                    if (cur == 1) {
                        x = i;
                        y = j;
                        return 1;
                    }
                    if (cur >= curBest) {
                        curBest = cur;
                        curX = i;
                        curY = j;
                    }
                }
            }
        }
        x = curX;
        y = curY;
        return curBest;
    }
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    char cBoard[3][3];
                    copy(board, cBoard);
                    cBoard[i][j] = HumanPiece;
                    if (isWin(cBoard, HumanPiece)) {
                        return -1;
                    }
                }
            }
        }
        int curBest = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    char cBoard[3][3];
                    copy(board, cBoard);
                    cBoard[i][j] = HumanPiece;
                    int cur = compute(cBoard, AIPiece, HumanPiece, x, y, 1 - state);
                    if (cur == -1) {
                        return -1;
                    }
                    if (cur <= curBest) {
                        curBest = cur;
                    }
                }
            }
        }
        return curBest;
    }
}

void AIplay(char board[][3], int& x, int& y, char AIPiece, char HumanPiece)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                char cBoard[3][3];
                copy(board, cBoard);
                cBoard[i][j] = AIPiece;
                if (isWin(cBoard, AIPiece)) {
                    x = i;
                    y = j;
                    return;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                char cBoard[3][3];
                copy(board, cBoard);
                cBoard[i][j] = HumanPiece;
                if (isWin(cBoard, HumanPiece)) {
                    x = i;
                    y = j;
                    return;
                }
            }
        }
    }
    compute(board, AIPiece, HumanPiece, x, y, 1);
}



int main()
{
    char board[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    char HumanPiece;
    char AIPiece;
    char choice;
    char pos[2];
    int x, y;
    cout << "Player 1" << endl;
    cout << "Player 2" << endl;
    cin >> choice;
    if (choice == '1') {
        HumanPiece = 'X';
        AIPiece = 'O';

        while (1) {
            display(board);
            cin >> pos;
            x = pos[0] - 97;
            y = pos[1] - 48;
            board[x][y] = HumanPiece;
            if (isWin(board, HumanPiece)) {
                cout << "Human wins" << endl;
                return 0;
            }
            if (isDraw(board)) {
                cout << "Draw" << endl;
                return 0;
            }
            AIplay(board, x, y, AIPiece, HumanPiece);
            board[x][y] = AIPiece;
            if (isWin(board, AIPiece)) {
                cout << "AI wins" << endl;
                return 0;
            }
            if (isDraw(board)) {
                cout << "Draw" << endl;
                return 0;
            }
        }
    }
    else {
        HumanPiece = 'O';
        AIPiece = 'X';
        while (1) {
            AIplay(board, x, y, AIPiece, HumanPiece);
            board[x][y] = AIPiece;
            if (isWin(board, AIPiece)) {
                cout << "AI wins" << endl;
                return 0;
            }
            if (isDraw(board)) {
                cout << "Draw" << endl;
                return 0;
            }
            display(board);
            cin >> pos;
            x = pos[0] - 97;
            y = pos[1] - 48;
            board[x][y] = HumanPiece;
            if (isWin(board, HumanPiece)) {
                cout << "Human wins" << endl;
                return 0;
            }
            if (isDraw(board)) {
                cout << "Draw" << endl;
                return 0;
            }
        }
    }
}
