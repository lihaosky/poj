//find a 6 digit number which have the same digit number when it multiplies 1-6
//LIHAO 18/NOV/2008


#include<iostream>
#include<algorithm>
using namespace std;
int num_digit(int n)
{
    int i=0;
    while(n){
             i++;
             n/=10;
             }
             return i;
}

void get_digit(int n,int a[])
{
     int i=0;
     while(n){
              a[i++]=n%10;
              n/=10;
              }
     sort(a,a+6);
}
bool cmp(int a[],int b[])
{
     for(int i=0;i<6;i++){
             if(a[i]!=b[i]){
                            return false;
                            }
     }
     return true;
}
int main()
{
    int digit[6];
    int digit1[6];
    long num;
    int flag;
    for(long i=100000;i<166666;i++){
             flag=0;
             get_digit(i,digit);
             for(int j=2;j<=6;j++){
                     get_digit(j*i,digit1);
                     if(!cmp(digit,digit1)){
                                            break;
                                            }
                     if(cmp(digit,digit1)&&j<6){continue;}
                     else{flag=1;}
                     }
             if(flag){
                      cout<<i<<endl;
                      }
    }
    system("PAUSE");
    return 0;
}
            
            
            
    
