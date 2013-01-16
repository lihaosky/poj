//已知 n 个整数 x1,x2,…,xn，以及一个整数 k（k＜n）。从 n 个整数中任选 k 个整数相加，
//可分别得到一系列的和。例如当 n=4，k＝3，4 个整数分别为 3，7，12，19 时，可得全部的组合与它们的和为： 
//3＋7＋12=22 3＋7＋19＝29 7＋12＋19＝38 3＋12＋19＝34。 
//现在，要求你计算出和为素数共有多少种。 


#include<iostream>
using namespace std;
bool is_three(int a[],int size,int limit)
{
     int num=0;
     for(int i=0;i<size;i++){
             if(a[i]){num++;}
             if(num>limit){return false;}
             }
     if(num==limit){return true;}
     return false;
}

bool is_prime(int n)
{
     if(n==2){return true;}
     for(int i=2;i<n/2;i++){
             if(!(n%i)){return false;}
             }
     return true;
}
int main()
{
    int size;
    int limit;
    int prime=0;
    int a[100];
    int b[100];
    cout<<"input the size of number and limit of take number!"<<endl;
    cin>>size>>limit;
    cout<<"input all the number!"<<endl;
    for(int i=0;i<size;i++){
            cin>>a[i];
            b[i]=0;
            }
    int pivot=0;
    b[0]=1;
    while(1){
                      int k;
                      int sum=0;
                      for(k=0;k<=pivot;k++){
                                           if(b[k]==0){break;}
                                           }
                      cout<<k<<endl;
                      if(k>pivot&&(pivot==size-1)){
                                 break;
                                 }
                      if(k>pivot){pivot++;}
                      b[k]=1;
                      for(int j=0;j<k;j++){
                              b[j]=0;
                              }
                      if(is_three(b,size,limit)){
                                           for(int j=0;j<size;j++){
                                                   if(b[j]){
                                                            sum+=a[j];
                                                            }
                                           }
                                           if(is_prime(sum)){
                                                             prime++;
                                                             }
                      }
    }
    cout<<"there are "<<prime<<" prime sums in the number!"<<endl;
    system("PAUSE");
    return 0;
}                                       
                              
