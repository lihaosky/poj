//compute the power of 2 the power can be as large as 10000 it will take some time to do it
//display the first 500 digits place 0 when no number exits
//AUTHOR: LIHAO
//DATE: 2 Dec 2008
#include<iostream>
using namespace std;
    int a[1000000];
int main()
{
    unsigned long p;
    unsigned long digit=1;
    int carry=0;
    a[1]=2;
    cin>>p;
    for(int i=1;i<p;i++){
            for(int j=1;j<=digit;j++){
                             int k=a[j];
                             a[j]=carry+(a[j]*2)%10;
                             carry=(2*k)/10;
                             }
              
                    if(carry){
                              a[digit+1]=1;
                              digit++;
                              }
                    carry=0;
    }
    a[1]--;
    cout<<digit<<endl;
    if(digit>=500){
     for(int i=500;i>=1;i--){
             if(i%50==0){
                         cout<<endl;
                         }
             else{
             cout<<a[i];
             }
             }
             }
     else{
                  for(int j=digit, k=1;j>=1;j--,k++){
                          if(k%50==0){
                                          cout<<endl;
                                          }
                          else{
                               cout<<a[j];
                               }
                               }
                  int k=digit%50+1;
                  for(int j=digit+1;j<=500;k++,j++){
                          if(k%50==0){
                                          cout<<endl;
                                          }
                          else{
                               cout<<"0";
                               }
                          }
     }                  
     cout<<endl;               
     system("PAUSE");
}
