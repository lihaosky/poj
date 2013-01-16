/*
*    Description: f(0) = 13, f(1) = 17, f(2 * n) = 43 * f(n) + 57 * f(n + 1), f(2 * n + 1) = 91 * f(n) + 179 * f(n + 1) for n > 1
*                         given n, compute f(n)
*
*/
#include <iostream>

using namespace std;

double dijkstra(int n)
{
    int k = n;
    int a = 1;
    int b = 0;
    int c = 0;
    while (k) {
        if (k % 2) {
            k /= 2;
            c = 57 * b;
            b = 179 * a + 43 * b;
            a *= 91;
        }
        else {
            k /= 2;
            int tmp = a;
            a = 43 * a + 91 * b;
            b = 57 * tmp + 179 * b;
        }
    }
    return a * 13 + b * 17 * c * (-43 * 17 / 56.0);
}

int main()
{
    int n;
    cin >> n;
    cout << dijkstra(n) << endl;
}
