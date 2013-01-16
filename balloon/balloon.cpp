/*Description

游乐园的天空中飘满了气球，明明对这些气球突然有了兴趣，他需要你的帮助　
你将会被告知气球的数量以及每个气球的颜色
相同颜色的气球数量被称为这种颜色的频率。


Input

第一行为N(N<=100)，接下来的N行为1～N个气球的颜色(单词的长度不超过14个字母)

Output

第一行为气球颜色的总数.
从第二行开始，按照以下规则输出：
先输出最大频率（占一行）；
再按词典顺序输出是这种频率的颜色，一种颜色占一行。
对其它所有频率按从大到小的顺序进行相同的操作（要保证操作了所有的频率与颜色）。

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

