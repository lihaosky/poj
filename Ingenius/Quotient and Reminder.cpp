/*
*     Description:  Find a mod b and a div b using integer variables and avoiding explicit div and mod operation
*                            (Except divided by 2 or multiply by 2, since it can be done by bit shifting)
*
*/

#include <iostream>

using namespace std;

void compute(int a, int b)
{
    int b1 = b;
    while (b1 <= a) {
        b1 = b1 << 1;
    }
    /* b1 > a, b1 = b * (integer power of 2)*/
    int q = 0;
    int r = a;
    /*
    *invariant relation: q, r are quotient and remainder when a is divided by b1; b1 = b * (some integer power of 2)
    */
    while (b1 != b) {
        b1 = b1 >> 1;
        q = q << 1;
        /* a = b1 * q + r, 0 <= r < 2 * b1*/
        if (r >= b1) {
            r -= b1;
            q += 1;
        }
    }
    cout << q << " " << r << endl;
}

int main()
{
    int a, b;
    cin >> a >> b;
    compute(a, b);
}
