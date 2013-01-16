/*
I
 Next generation contest ¨C 4
 Time Limit ¨C 4 secs

Investigating Div-Sum Property







An integer is divisible by 3 if the sum of its digits is also divisible by 3. For example, 3702 is divisible by 3 and 12(3+7+0+2) is also divisible by 3. This property also holds for the integer 9.

In this problem, we will investigate this property for other integers.

Input

The first line of input is an integer T(T<100) that indicates the number of test cases. Each case is a line containing 3 positive integers A, B and K. 1 <= A <= B < 2^31 and 0<K<10000.

Output

For each case, output the number of integers in the range [A, B] which is divisible by K and the sum of its digits is also divisible by K.

Sample Input
 Output for Sample Input

3

1 20 1

1 20 2

1 1000 4
 20

5

64




ProblemSetter: Sohel Hafiz
Special Thanks: Ivan Krasilnikov
*/
//DP problem, classic
/*********************************
* dp[][][][] store the length of
* current number, first digit, remainder
* of the number divided by sum of digit
* and remainder of number
* It can be computed this way
* dp[l][f][((f % k) + (s % k )) % k][((f * ex(l)) % k + n) % k] += dp[l - 1][lf][s][n];
* Then dp[x][y][0][0] store the number of number can be divided
* Note you have to compute the range, since dp[l][f][0][0] store all the number
* which can be divided by  length l, with first digit f.
**********************************/
//AUTHOR: LIHAO
//VENUE: DORM
//DATE: 6 OCTOBER, 2009

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

unsigned int A, B;
int k;
unsigned int dp[11][10][84][84];
string a, b;
int ansA, ansB, ans;

void init()
{
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 10; j++) {
            for (int s = 0; s < 84; s++) {
                for (int n = 0; n < 84; n++) {
                    dp[i][j][s][n] = 0;
                }
            }
        }
    }
}

unsigned int ex(int l)
{
    unsigned int s = 1;
    for (int i = 1; i < l; i++) {
        s *= 10;
    }
    return s;
}

void parse()
{
    a = "";
    b = "";
    while (A) {
        a += (A % 10 + 48);
        A /= 10;
    }
    while (B) {
        b += (B % 10 + 48);
        B /= 10;
    }
}

int sumofa()
{
    unsigned tmp = A;
    int sum = 0;
    while (tmp) {
        sum += tmp % 10;
        tmp /= 10;
    }
    return sum;
}

int main()
{
    ofstream fp;
    fp.open("out.txt");
    int t;
    cin >> t;
    while (t--) {
        cin >> A >> B >> k;
        /*if (k == 1) {
            cout << B - A + 1 << endl;
            continue;
        }*/
        if (k > 83) {
            cout << 0 << endl;
            continue;
        }
        init();
        ans = 0;
        ansA = ansB = 0;
        if (sumofa() % k == 0 && A % k == 0) {
            ans = 1;
        }
        cout << ans << endl;
        for (int i = 0; i < 10; i++) {
            dp[1][i][i % k][i % k] = 1;
        }
        for (int l = 2; l < 11; l++) {
            for (int f = 0; f < 10; f++) {
                for (int lf = 0; lf < 10; lf++) {
                    for (int s = 0; s < k; s++) {
                        for (int n = 0; n < k; n++) {
                            dp[l][f][((f % k) + (s % k )) % k][((f * ex(l)) % k + n) % k] += dp[l - 1][lf][s][n];
                        }
                    }
                }
            }
        }
        parse();
        int aSize = a.length();
        int bSize = b.length();
        for (int i = aSize - 1; i >= 0; i--) {
            if (i == aSize - 1) {
                for (int j = 1; j <= a[i] - 48; j++) {
                    ansA += dp[i + 1][j][0][0];
                }
            }
            else {
                for (int j = 1; j < 10; j++) {
                    ansA += dp[i + 1][j][0][0];
                }
            }
        }
        for (int i = bSize - 1; i >= 0; i--) {
            if (i == bSize - 1) {
                for (int j = 1; j <= b[i] - 48; j++) {
                    ansB += dp[i + 1][j][0][0];
                }
            }
            else {
                for (int j = 1; j < 10; j++) {
                    ansB += dp[i + 1][j][0][0];
                }
            }
        }
        unsigned int preS = 0;
        unsigned int preN = 0;
        int ma = 0;
        for (int i = aSize - 2; i >= 0; i--) {
            preS += (a[i + 1] - 48);
            preN += ((a[i + 1] - 48) * ex(i + 2));
            for (int j = a[i] - 47; j < 10; j++) {
                for (int s = 0; s < k; s++) {
                    for (int n = 0; n < k; n++) {
                        if ((s + (preS % k)) % k == 0 && (n + (preN % k)) % k == 0) {
                            ma += dp[i + 1][j][s][n];
                        }
                    }
                }
            }
        }
        preS = 0;
        preN = 0;
        int mb = 0;
        for (int i = bSize - 2; i >= 0; i--) {
            preS += (b[i + 1] - 48);
            preN += ((b[i + 1] - 48) * ex(i + 2));
            for (int j = b[i] - 47; j < 10; j++) {
                for (int s = 0; s < k; s++) {
                    for (int n = 0; n < k; n++) {
                        if ((s + (preS % k)) % k == 0 && (n + (preN % k)) % k == 0) {
                            mb += dp[i + 1][j][s][n];
                        }
                    }
                }
            }
        }
        //cout << ansB << ansA << mb << ma << endl;
        ans += (ansB - mb - ansA + ma);
        cout << ans << endl;
        fp << ans << endl;
    }
    fp.close();
}
