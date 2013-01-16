#include <iostream>
#include <string.h>

using namespace std;

int line1[50010];
int line2[50010];
char dna1[50010];
char dna2[50010];
int map1[100][100];

int min3(int a, int b,  int c)
{
    int min = (a < b ? a : b);
    return (min < c ? min : c);
}

inline int compute()
{
    int len1 = strlen(dna1);
    int len2 = strlen(dna2);
    bool jumper = false;

    for (int i = 0; i < len2; i++) {
        line1[i] = 3 * (i + 1);
 //       cout << line1[i] << " ";
    }

 //   cout << endl;

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (!jumper) {
                if (!i && !j) {
                    line2[j] = map1[dna2[j]][dna1[i]];
                }
                else if (!i && j) {
                    line2[j] = min3(map1[dna2[j]][dna1[i]] + line1[j - 1], line1[j] + 3, line2[j - 1] + 3);
                }
                else if (i && !j) {
                    line2[j] = min3(map1[dna2[j]][dna1[i]] + 3 * i, 3 * (i + 2), line1[0] + 3);
                }
                else {
                    line2[j] = min3(map1[dna2[j]][dna1[i]] + line1[j - 1], line1[j] + 3, line2[j - 1] + 3);
                }
   //             cout << line2[j] << " ";
            }
            else {
                if (!i && !j) {
                    line1[j] = map1[dna2[j]][dna1[i]];
                }
                else if (!i && j) {
                    line1[j] = min3(map1[dna2[j]][dna1[i]] + line2[j - 1], line2[j] + 3, line1[j - 1] + 3);
                }
                else if (i && !j) {
                    line1[j] = min3(map1[dna2[j]][dna1[i]] + 3 * i, 3 * (i + 2), line2[0] + 3);
                }
                else {
                    line1[j] = min3(map1[dna2[j]][dna1[i]] + line2[j - 1], line2[j] + 3, line1[j - 1] + 3);
                }
      //          cout << line1[j] << " ";
            }
        }
        jumper = 1 - jumper;
   //     cout << endl;
    }
    if (!jumper) {
        return line1[len2 - 1];
    }
    return line2[len2 - 1];
}

int main()
{
map1['A']['A'] = 0;
map1['A']['G'] = 5;
map1['A']['C'] = 5;
map1['A']['T'] = 5;
map1['G']['G'] = 0;
map1['G']['C'] = 4;
map1['G']['T'] = 5;
map1['C']['C'] = 0;
map1['C']['T'] = 5;
map1['T']['T'] = 0;
map1['G']['A'] = 5;
map1['C']['A'] = 5;
map1['C']['G'] = 4;
map1['T']['A'] = 5;
map1['T']['G'] = 5;
map1['T']['C'] = 5;

    while (cin >> dna1 >> dna2) {
        cout << compute() << endl;
    }
}
