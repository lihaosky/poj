#include <iostream>

using namespace std;

int data[100];
int size;
int opt[100];

int main()
{
    cout << "Input data size: ";
    cin >> size;

    cout << "Input data:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }

    for (int i = 0; i < size; i++) {
        opt[i] = 1;
        for (int j = 0; j < i; j++) {
            if (data[i] > data[j] && opt[j] + 1 > opt[i]) {
                opt[i] = opt[j] + 1;
            }
            else {
                opt[i] = opt[j];
            }
        }
    }

    int counted = 0;

    cout << "Longest size: " << opt[size - 1] << endl;
    for (int i = size - 1; i > 0; i--) {
        if (opt[i] > opt[i - 1]) {
            cout << data[i] << " ";
            counted++;
        }
    }

    if (counted < opt[size - 1]) {
        cout << data[0] << endl;
    }
}
