/*
*   _____                              __                              __
*  |   ___|_  _ _____   _______|  |___ ______   __  __(__)_______  ______
*  |  |__|  |/ /  __    |/  ___/__    ___/   __    \|   |/ / |   |_____   /    __   \
*  |   __|  ./ |  (__|  |   (____   |   |__ |  (__)    |   . /   |   |   ____/_|   ____|
*  |__|  |_|   \___,__|\____/    |____ \______/|__|     |__|_______| \_____|
*
*


#include <iostream>

using namespace std;

/*
*  If n is 1, it has no prime factor
* Else, find its prime factor from 2, note that if some number can be divided by n, it must be
* a prime number, since if it is composite number, it can be divided by prime number smaller than it and it can't be composite
* Good observation!!!
*/
void factorize(int n)
{
    if (n == 1) {
        cout << n << " " << endl;
        return;
    }
    else {
        int t = 2;
        while (n != 1) {
            if (!(n % t)) {
                cout << t << " ";
                n /= t;
            }
            else {
                t++;
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Input the number you want to factorize: ";
    cin >> n;
    factorize(n);
}
