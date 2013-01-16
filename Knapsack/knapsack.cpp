//AUTHOR: LIHAO
//DATE: March 16th, 2010
//Knapsack problem

#include <iostream>

using namespace std;

int size;
int capacity;
int w[100];
int v[100];
int dp[100][200];

int main()
{
    cout << "Input capacity: ";
    cin >> capacity;
    cout << "Input data size: ";
    cin >> size;
    cout << "Input data: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0) {
                if (j >= w[i]) {
                    dp[0][j] = v[0];
                }
                else {
                    dp[0][j] = 0;
                }
            }
            else {
                if (j >= w[i] && dp[i - 1][j - w[i]] + v[i] > dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j - w[i]] + v[i];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    cout << "Maximum value: " << dp[size - 1][capacity] << endl;

    int c = capacity;

    cout << "DP Table:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= capacity; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = size - 1; i > 0; i--) {
        if (dp[i][c] > dp[i - 1][c]) {
            cout << i << endl;
            c = c - w[i];
        }
    }
}
