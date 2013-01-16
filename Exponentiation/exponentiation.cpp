//using array to store digit to compute large exponentiation 
//AUTHOR:LIHAO
//VENUE:DORMITORY
//DATE: Jan 14th 2009

#include <iostream>
using namespace std;
void multiple(int a[],int&size,int x)
{
     int carry=0;
     for(int i=0;i<size;i++){
             int product=a[i]*x+carry;
             a[i]=product%10;
             carry=product/10;
             }
     while(carry){
                  a[size++]=carry%10;
                  carry/=10;
                  }
}
int main()
{
    while(1){
    cout<<"input the number(7 digits including decimal point) and exponent:"<<endl;
    char num[7];
    int size=0;
    int val=0;
    int  exp;
    cin>>num;
    cin>>exp;
    int a[100];
    bool l_deci=true;
    bool r_deci=true;
    short int dot_num=0;
    int i;
    for(i=5;i>=0;i--){
                      if(num[i]=='.'){
                                      break;
                                      }
    }
    for(int j=0;j<i;j++){
            if(num[j]!='0'){
                            l_deci=false;
                            break;
                            }
    }
    for(int j=i+1;j<=5;j++){
            if(num[j]!='0'){
                            r_deci=false;
                            break;
                            }
    }
    if(l_deci==true&&r_deci){
                             cout<<"0"<<endl;
                             return 0;
                             }
    else if((l_deci==true)&&(r_deci==false)){
         int m,n;
         for(m=i+1;m<=5;m++){
                 if(num[m]!='0'){break;}
                 } 
         
         for(n=5;n>i;n--){
                 if(num[n]!='0'){break;}
                 }
         dot_num=n-i;              
         for(int j=n;j>=m;j--){
                        a[size++]=num[j]-48;
         }
    }
    else if(l_deci==false&&r_deci){
         dot_num=0;
         for(int j=i-1;j>=0;j--){
                 a[size++]=num[j]-48;
                 }
    }
    else{
         int n;
         for(n=5;n>i;n--){
                          if(num[n]!='0'){break;}
                          }
         dot_num=n-i;
         for(;n>=0;n--){
                        if(num[n]=='.'){continue;}
                        a[size++]=num[n]-48;
                        }
     }
    for(int j=size-1;j>=0;j--){
            val=(val*10+a[j]);
          }
    for(i=0;i<exp-1;i++){
                       multiple(a,size,val);
                       }
    if(dot_num*exp-1>size){
                           cout<<".";
                           for(int j=dot_num*exp-size;j>0;j--){
                                   cout<<"0";
                                   }
                           for(i=size-1;i>=0;i--){
                                                 cout<<a[i];
                                                 }
    }
    else{
    for(i=size-1;i>=0;i--){
                           if(i==(dot_num*exp-1)){cout<<".";}
                           cout<<a[i];
                           }
    }
    cout<<endl;
   }
    system("PAUSE");
}
