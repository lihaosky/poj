/****************************************
CoIns
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 554  Accepted: 168

Description

һ��Ӳ�ҹ���Mö��ÿһö�������泯�ϡ�ȡ���������һöӲ�ң����������Ż�ԭ����Ȼ��ȡ���������2öӲ�ң�������һ������ٷŻ�ԭ������ȡ3ö��ȡ4ö��ֱ��Mö��Ȼ���ٴ�����Ӳ���������һö��ʼ���ظ��ղŵ�����������һֱ����ȥ��ֱ������Ӳ���е�ÿһö�ֶ������泯��Ϊֹ��
Input

��һ���ǲ������ݵ�����t��0 <= t <= 20��������ÿ����һ��������ݣ�ÿ�н��е�һ������������Ӳ�ҵ�ö��M��0< M< 10^8��
Output

�������ÿ��������ݣ����Ϊ��ʹ����Ӳ���е�ÿһö�ֶ������泯�������跭�Ĵ���������ĳ����п�����Ҫʹ��64λ���������������������
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
