#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    unsigned int max = (1 << 31);
    srand(time(NULL));
    ofstream fp;
    fp.open("data.txt");
    fp << 99 << endl;;
    for (int i = 1; i < 100; i++) {
        unsigned int A = rand() % max;
        unsigned int B = rand() % max;
        if (A > B) {
            unsigned int tmp = A;
            A = B;
            B = tmp;
        }
        int k = rand() % 83 + 1;
        fp << A << " " << B << " " << k << endl;
    }
    fp.close();
}
