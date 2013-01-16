#include <iostream>
using namespace std;
struct Num
{
       int digit[100];
       int remain[100];
       int dig_size;
       int remain_size;
}num[101];
void init()
{
     for (int i = 0; i < 101; i++) {
         num[i].dig_size = 0;
         num[i].remain_size = 1;
         num[i].remain[0] = 1;
     }
}
void compute()
{
     for (int i = 2; i < 101; i++) {
         while (1) {
               int x = num[i].remain[num[i].remain_size - 1] * 10;
               bool flag = false;
               while (x < i) {
                     for (int j = 0; j < num[i].remain_size; j++) {
                         if (x == num[i].remain[j]) {
                               flag = true;
                               break;
                         }
                     }
                     if (flag) {
                               break;
                     }
                     num[i].digit[num[i].dig_size++] = 0;
                     num[i].remain[num[i].remain_size++] = x;
                     x *= 10;
               }
               if (flag) {
                         break;
               }
               int r = x % i;
               if (!r) {
                     num[i].digit[num[i].dig_size++] = x / i;
                     break;
               }
               num[i].digit[num[i].dig_size++] = x / i;
               for (int j = 0; j < num[i].remain_size; j++) {
                   if (num[i].remain[j] == r) {
                       flag = true;
                       break;
                   }
               }
               if (flag) {
                    break;
               }
               else {
                    num[i].remain[num[i].remain_size++] = r;
               }
         }
     }
}
int main()
{
    init();
    compute();
    int n, k;
    while (cin >> n >> k) {
          int count = 0;
          for (int i = 2; i <= n; i++) {
              for (int j = 0; j < num[i].dig_size; j++) {
                  if (num[i].digit[j] == k) {
                                      count++;
                  }
              }
          }
          cout << count << endl;
    }
}
