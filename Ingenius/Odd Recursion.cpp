/*
*   Description: f(0) = 0, f(1) = 1, f(2n) = f(n), f(2n + 1) = f(n) + f(n + 1), given n, compute f(n)
*                        the number of operations should be of order logn
*   Author: E. Dijkstra
*
*/

/*
*  Recursion form
*/

#include <iostream>

using namespace std;

int operation = 0;
int f(int n)
{
    operation++;
    if (!n) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if ((n % 2) == 1) {
        return (f(n / 2) + f(n / 2 + 1));
    }
    return f(n / 2);
}

/*
*      O(lgn)
*/
int dijkstra(int n)
{
    int k = n;
    int a = 1;
    int b = 0;
    /*
    *   invariant relation: 0 <= k, f(n) = a * f(k) + b * f(k + 1), this holds all the time
    */
    while (k) {
        if (k % 2 == 0) {
            int l = k / 2;
            /*
            *  k = 2 * l, f(k) = f(l), f(k + 1) = f(2 * l + 1) = f(l) + f(l + 1), f(n) = a * f(k) + b * f(k + 1) = (a + b) * f(1) + b * f(l + 1)
            */
            k = l;
            a += b;
        }
        else {
            int l = k / 2;
            /*
            * k = 2 * l + 1, f(k) = f(l) + f(l + 1), f(k + 1) = f(2 * l + 2) = f(l + 1), f(n) = a * f(k) + b * f(k + 1) = a * f(l) + (a + b) * f(l + 1);
            */
            k = l;
            b += a;
        }
        operation++;
    }
    return b;
}

int main()
{
    int n;
    cin >> n;
   cout << f(n) << endl;
   cout << operation << endl << endl;
   operation = 0;
   cout << dijkstra(n) << endl;
    cout << operation << endl;
}
