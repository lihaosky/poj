/****************************************************
* Filename: Round Robin tournament scheduling
*----------------------------------------------
* Description: N tennis player play with each other,
* schedule it
*---------------------------------------------------
* Algorithm: Round Robin: Fix the first player and
* Rotate the chain
* Example N = 6 :
* 1 2 3        1 6 2      1 5 6
*        ===>        ===>        ===> .....
* 6 5 4        5 4 3      4 3 2
*----------------------------------------------------
* This is quite ingenoius method, if not most
* I give up and look it up on the internet...
*****************************************************/
#include <iostream>

using namespace std;

int first[200];
int second[200];
int size;

/*********************
* Initialize the chain
*********************/
void build(int n)
{
     if (n % 2 == 1) {
           //dummy player if it odd number
           for (int i = 0; i <= n / 2; i++) {
               first[i] = i;
               second[i] = n - i;
           }
           size = n / 2 + 1;
     }
     else {
          for (int i = 0; i < n / 2; i++) {
              first[i] = i + 1;
              second[i] = n - i;
          }
          size = n / 2;
     }
}
/********************
* Rotate
*********************/
void turn()
{
     int secondFirst = second[0];
     for (int i = 0; i < size - 1; i++) {
         second[i] = second[i + 1];
     }
     second[size - 1] = first[size - 1];
     for (int i = size - 1; i > 1; i--) {
         first[i] = first[i - 1];
     }
     first[1] = secondFirst;
}

int main()
{
    int n;
    int day = 1;
    cin >> n;
    build(n);
    cout << "Day " << day++ << ": ";
    if (first[0] == 0) {
        for (int i = 1; i < size; i++) {
            cout << "(" << first[i] << "," << second[i] << ")";
        }
        cout << endl;
    }
    else {
         for (int i = 0; i < size; i++) {
             cout << "(" << first[i] << "," << second[i] << ")";
         }
         cout << endl;
    }
    turn();
    while (second[0] != n) {
          cout << "Day " << day++ << ": ";
    if (first[0] == 0) {
        for (int i = 1; i < size; i++) {
            cout << "(" << first[i] << "," << second[i] << ")";
        }
        cout << endl;
    }
    else {
         for (int i = 0; i < size; i++) {
             cout << "(" << first[i] << "," << second[i] << ")";
         }
         cout << endl;
    }
    turn();
    }
}
