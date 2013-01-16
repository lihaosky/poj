/*Dividing
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 19062  Accepted: 4620

Description

Marsha and Bill own a collection of marbles. They want to split the collection among themselves so that both receive an equal share of the marbles. This would be easy if all the marbles had the same value, because then they could just split the collection in half. But unfortunately, some of the marbles are larger, or more beautiful than others. So, Marsha and Bill start by assigning a value, a natural number between one and six, to each marble. Now they want to divide the marbles so that each of them gets the same total value. Unfortunately, they realize that it might be impossible to divide the marbles in this way (even if the total value of all marbles is even). For example, if there are one marble of value 1, one of value 3 and two of value 4, then they cannot be split into sets of equal value. So, they ask you to write a program that checks whether there is a fair partition of the marbles.
Input

Each line in the input file describes one collection of marbles to be divided. The lines contain six non-negative integers n1 , . . . , n6 , where ni is the number of marbles of value i. So, the example from above would be described by the input-line "1 0 1 2 0 0". The maximum total number of marbles will be 20000.
The last line of the input file will be "0 0 0 0 0 0"; do not process this line.
Output

For each collection, output "Collection #k:", where k is the number of the test case, and then either "Can be divided." or "Can't be divided.".
Output a blank line after each test case.
Sample Input

1 0 1 2 0 0
1 0 0 0 1 1
0 0 0 0 0 0
Sample Output

Collection #1:
Can't be divided.

Collection #2:
Can be divided.
*/
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: FEB 7TH 2009

#include <iostream>
#include <ctime>
using namespace std;
bool is_divisible(int a[],int q)
{
      for(int i=0;i<=a[6];i++){
            for(int j=0;j<=a[5];j++){
                  for(int k=0;k<=a[4];k++){
                        for(int m=0;m<=a[3];m++){
                              for(int n=0;n<=a[2];n++){
                                    for(int s=0;s<=a[1];s++){
                                          int sum=0;
                                          sum+=(i*6+j*5+k*4+m*3+n*2+s);
                                          if(sum==q){
                                                return true;
                                          }
                                    }
                              }
                        }
                  }
            }
      }
      return false;
}


int main()
{
      int a[7];
      int sum;
      int counter=1;
      while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]&&(a[1]||a[2]||a[3]||a[4]||a[5]||a[6])){
            sum=0;
            for(int i=1;i<=6;i++){
                  sum+=a[i]*i;
            }
            if(sum%2){
                  cout<<"Collection #"<<counter<<":"<<endl;
                  cout<<"Can't be divided."<<endl<<endl;
                  counter++;
                  continue;
            }
            if(a[6]>=8){
                  if(a[6]%2){
                        a[6]=7;
                  }
                  else{
                        a[6]=6;
                  }
            }
            if(a[5]>=13){
                  if(a[5]%2){
                        a[5]=11;
                  }
                  else{
                        a[5]=12;
                  }
            }
            if(a[4]>=8){
                  if(a[4]%2){
                        a[4]=7;
                  }
                  else{
                        a[4]=8;
                  }
            }
            if(a[3]>=8){
                  if(a[3]%2){
                        a[3]=7;
                  }
                  else{
                        a[3]=8;
                  }
            }
            if(a[2]>=4){
                  if(a[2]%2){
                        a[2]=3;
                  }
                  else{
                        a[2]=4;
                  }
            }
            if(a[1]>=6){
                  a[1]=6;
            }
            sum=0;
            for(int i=1;i<=6;i++){
                  sum+=a[i]*i;
            }
            sum/=2;
            if(is_divisible(a,sum)){
                  cout<<"Collection #"<<counter<<":"<<endl;
                  cout<<"Can be divided."<<endl<<endl;;
                  counter++;
            }
            else{
                  cout<<"Collection #"<<counter<<":"<<endl;
                  cout<<"Can't be divided."<<endl<<endl;
                  counter++;
            }
      }
      return 0;
}
