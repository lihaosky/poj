/****************************************
CoIns
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 554  Accepted: 168

Description

一摞硬币共有M枚，每一枚都是正面朝上。取下最上面的一枚硬币，将它翻面后放回原处。然后取下最上面的2枚硬币，将他们一起翻面后再放回原处。再取3枚，取4枚厖直至M枚。然后再从这摞硬币最上面的一枚开始，重复刚才的做法。这样一直做下去，直到这摞硬币中的每一枚又都是正面朝上为止。
Input

第一行是测试数据的组数t（0 <= t <= 20）。以下每行是一组测试数据，每行仅有的一个数字是这摞硬币的枚数M，0< M< 10^8。
Output

对输入的每组测试数据，输出为了使这摞硬币中的每一枚又都是正面朝上所必需翻的次数。在你的程序中可能需要使用64位的整数来保存这个次数。
Sample Input

4
4
1
30
9

Sample Output

11
2
899
80
Source

POJ Monthly--2004.05.15 BearL@pku
**********************************/
//this is really a ridiculous problem, guess
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 15 APRIL 2009
//
#include <iostream>
using namespace std;
int main()
{
      __int64 t_case,n,k,flag,pos,counter;
      __int64 ans,tmp;
      cin>>t_case;
      while(t_case--){
            cin>>n;
            if(n==1){
                  cout<<2<<endl;
                  continue;
            }
            flag=0;
            pos=1;
            counter=0;
            if(n%2){
                  k=n/2+1;
                  do{
                        if(pos%2){
                              flag=1-flag;
                              pos=(n-pos)/2+1;
                        }
                        else{
                              pos=k+pos/2;
                        }
                        counter++;
                  }while(pos!=1);
            }
            else{
                  k=n/2;
                  do{
                        if(pos%2){
                              pos=k+(pos+1)/2;
                        }
                        else{
                              flag=1-flag;
                              pos=(n-pos)/2+1;
                        }
                        counter++;
                  }while(pos!=1);
            }
            tmp=counter;
            ans=n*tmp-flag;
            cout<<ans<<endl;
      }
}
