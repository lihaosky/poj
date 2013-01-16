/*Description

����԰�������Ʈ����������������Щ����ͻȻ������Ȥ������Ҫ��İ�����
�㽫�ᱻ��֪����������Լ�ÿ���������ɫ
��ͬ��ɫ��������������Ϊ������ɫ��Ƶ�ʡ�


Input

��һ��ΪN(N<=100)����������N��Ϊ1��N���������ɫ(���ʵĳ��Ȳ�����14����ĸ)

Output

��һ��Ϊ������ɫ������.
�ӵڶ��п�ʼ���������¹��������
��������Ƶ�ʣ�ռһ�У���
�ٰ��ʵ�˳�����������Ƶ�ʵ���ɫ��һ����ɫռһ�С�
����������Ƶ�ʰ��Ӵ�С��˳�������ͬ�Ĳ�����Ҫ��֤���������е�Ƶ������ɫ����

Sample Input


5
green
red
blue
red
red

3
pink
orange
pink


Sample Output


3*/

//AUTHOR:LIHAO
//VENUE:DORMITORY
//DATE: Jan 19 2009



#include <iostream>
#include <string>
#include<map>
#include<algorithm>

using namespace std;
struct balloon
{
      string val;
      int num;
};

bool cmp(balloon a,balloon b)
{
      return a.num>b.num;
}

using namespace std;
int main()
{
            string str;
            map<string,int> a;
            balloon  b[100];
            int size=0;
            int n;
            cin>>n;
            for(int i=0;i<n;i++){
                  cin>>str;
                  a[str]++;
            }
            map<string,int>::iterator it;
            for(it=a.begin();it!=a.end();it++){
                  b[size].num=(*it).second;
                  b[size++].val=(*it).first;
            }
            stable_sort(b,b+size,cmp);
            cout<<b[0].num<<endl<<b[0].num<<endl<<b[0].val<<endl;
            int pre=b[0].num;
            for(int i=1;i<size;i++){
                  if(pre!=b[i].num){
                  cout<<b[i].num<<endl<<b[i].val<<endl;
                  pre=b[i].num;
                  }
                  else{
                        cout<<b[i].val<<endl;
                  }
            }
}

