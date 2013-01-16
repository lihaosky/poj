#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double c, x, root, x0;
    double epsilon = 1e-8;
    int itnum = 1;
    cout << "Input value: ";
    cin >> c;
    cout << "Input initial value: ";
    cin >> x0;
    x = x0;
    while (fabs(x * x * x - c) >= epsilon) {
         x = x - (x * x * x - c) / (3 * x * x);

    }

    root = x;

    x = x0;
    while (fabs(x * x * x - c) >= epsilon) {
        x = x - (x * x * x - c)/ (3 * x * x);
        cout << "Iteration " << itnum++ << " , X is " << x << ", error is " << fabs(x - root) << endl;
    }

    cout << "Root is: " << x << endl;
    return 0;
}

