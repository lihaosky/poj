/*��ѩ
Time Limit: 1000MS  Memory Limit: 65536K
Total Submissions: 23793  Accepted: 8073

Description

Michaelϲ����ѩ���Ⲣ����֣� ��Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б�����ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ������������㡣Michael��֪����һ����������׻��¡�������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�������һ������

 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

һ���˿��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶ȼ�С��������������У�һ���ɻ��еĻ���Ϊ24-17-16-1����Ȼ25-24-23-...-3-2-1��������ʵ�ϣ��������һ����
Input

����ĵ�һ�б�ʾ���������R������C(1 <= R,C <= 100)��������R�У�ÿ����C������������߶�h��0<=h<=10000��
Output

��������ĳ��ȡ�
Sample Input

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

Sample Output

25
*/
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: FEB 8TH 2009
//Using dynamic programming
//sort the array and find the path from the lowest height to the highest the height
//


#include <iostream>
#include <algorithm>
using namespace std;
struct rout
{
      short height;
      int length;
};

struct tmp
{
      short height;
      int subscript;
};

bool cmp(tmp a,tmp b)
{
      return a.height<b.height;
}

int longest(rout way[],int row,int col,int n)
{
      int tmplength=way[n].length;
      int i;
      for(i=1;i<=row;i++){
            if(i*col>=n){
                  break;
            }
      }
      if(row==1&&n==1){
            if(way[n].height>way[n+1].height){
                  tmplength=(way[n+1].length+1);
            }
            way[n].length=tmplength;
            return tmplength;
      }
      if(row==1&&n==col){
            if(way[n].height>way[n-1].height){
                  tmplength=(way[n-1].length+1);
            }
            way[n].length=tmplength;
            return tmplength;
      }
      if(row==1&&n!=1&&n!=col){
            if(way[n].height>way[n-1].height){
                  tmplength=(way[n-1].length+1);
            }
            if(way[n].height>way[n+1].height){
                  if(way[n+1].length+1>tmplength){
                        tmplength=(way[n+1].length+1);
                  }
            }
            way[n].length=tmplength;
            return tmplength;
      }
      if(col==1&&n==1){
            if(way[n].height>way[n+1].height){
                  tmplength=(way[n+1].length+1);
            }
            way[n].length=tmplength;
            return tmplength;
      }
      if(col==1&&n==row){
            if(way[n].height>way[n-1].height){
                  tmplength=(way[n-1].length+1);
            }
            way[n].length=tmplength;
            return tmplength;
      }
      if(col==1&&n!=1&&n!=row){
            if(way[n].height>way[n-1].height){
                  tmplength=(way[n-1].length+1);
            }
            if(way[n].height>way[n+1].height){
                  if(way[n+1].length+1>tmplength){
                        tmplength=(way[n+1].length+1);
                  }
            }
            way[n].length=tmplength;
            return tmplength;
      }
      if(i==1&&(n%col==1)){
            if(way[n].height>way[n+1].height){
                  tmplength=(way[n+1].length+1);
            }
            if(way[n].height>way[n+col].height){
                  if(way[n+col].length+1>tmplength){
                        tmplength=(way[n+col].length+1);
                  }
            }
      }
      if(i==1&&(n%col==0)){
            if(way[n].height>way[n-1].height){
                  tmplength=(way[n-1].length+1);
            }
            if(way[n].height>way[n+col].height){
                  if(way[n+col].length+1>tmplength){
                        tmplength=(way[n+col].length+1);
                  }
            }
      }
      if(i==row&&(n%col==1)){
            if(way[n].height>way[n+1].height){
                  tmplength=(way[n+1].length+1);
            }
            if(way[n].height>way[n-col].height){
                  if(way[n-col].length+1>tmplength){
                  tmplength=(way[n-col].length+1);
                  }
            }
      }
      if(i==row&&(n%col==0)){
            if(way[n].height>way[n-1].height){
                  tmplength=(way[n-1].length+1);
            }
            if(way[n].height>way[n-col].height){
                  tmplength=(way[n-col].length+1);
            }
      }
      if(i==1&&(n%col!=1&&n%col!=0)){
            if(way[n].height>way[n-1].height){
                  tmplength=(way[n-1].length+1);
            }
            if(way[n].height>way[n+1].height){
                  if(way[n+1].length+1>tmplength){
                        tmplength=(way[n+1].length+1);
                  }
            }
            if(way[n].height>way[n+col].height){
                  if(way[n+col].height+1>tmplength){
                        tmplength=(way[n+col].length+1);
                  }
            }
      }
      if(i==row&&(n%col!=0&&n%col!=1)){
            if(way[n].height>way[n-1].height){
                  tmplength=(way[n-1].length+1);
            }
            if(way[n].height>way[n+1].height){
                  if(way[n+1].length+1>tmplength){
                        tmplength=(way[n+1].length+1);
                  }
            }
            if(way[n].height>way[n-col].height){
                  if(way[n-col].length+1>tmplength){
                        tmplength=(way[n-col].length+1);
                  }
            }
      }
      if(i>1&&i<row&&(n%col==1)){
            if(way[n].height>way[n+1].height){
                  tmplength=(way[n+1].length+1);
            }
            if(way[n].height>way[n+col].height){
                  if(way[n+col].length+1>tmplength){
                        tmplength=(way[n+col].length+1);
                  }
            }
            if(way[n].height>way[n-col].height){
                  if(way[n-col].length+1>tmplength){
                        tmplength=(way[n-col].length+1);
                  }
            }
            if(way[n].height>way[n+col].height){
                  if(way[n+col].length+1>tmplength){
                        tmplength=(way[n+col].length+1);
                  }
            }
      }
      if(i>1&&i<row&&n%col==0){
            if(way[n].height>way[n-1].height){
                  tmplength=(way[n-1].length+1);
            }
            if(way[n].height>way[n+col].height){
                  if(way[n+col].length+1>tmplength){
                        tmplength=(way[n+col].length+1);
                  }
            }
            if(way[n].height>way[n-col].height){
                  if(way[n-col].length+1>tmplength){
                        tmplength=(way[n-col].length+1);
                  }
            }
            if(way[n].height>way[n+col].height){
                  if(way[n+col].length+1>tmplength){
                        tmplength=(way[n+col].length+1);
                  }
            }
      }
      if(i>1&&i<row&&n%col!=0&&n%col!=1){
            if(way[n].height>way[n-1].height){
                  tmplength=(way[n-1].length+1);
            }
            if(way[n].height>way[n+1].height){
                  if(way[n+1].length+1>tmplength){
                        tmplength=(way[n+1].length+1);
                  }
            }
            if(way[n].height>way[n+col].height){
                  if(way[n+col].length+1>tmplength){
                        tmplength=(way[n+col].length+1);
                  }
            }
            if(way[n].height>way[n-col].height){
                  if(way[n-col].length+1>tmplength){
                        tmplength=(way[n-col].length+1);
                  }
            }
            if(way[n].height>way[n+col].height){
                  if(way[n+col].length+1>tmplength){
                        tmplength=(way[n+col].length+1);
                  }
            }
      }
      way[n].length=tmplength;
      return tmplength;
}


int main()
{
      int row,col;
      int long_path=0;
      cin>>row>>col;
      rout * way =new rout[row*col+1];
      tmp * buff =new tmp[row*col+1];
      buff[0].height=-1;
      buff[0].subscript=-1;
      for(int i=1;i<=row*col;i++){
            cin>>way[i].height;
            way[i].length=1;
            buff[i].height=way[i].height;
            buff[i].subscript=i;
      }
      if(row==1&&col==1){
            cout<<1<<endl;
            return 0;
      }
      stable_sort(buff,buff+row*col+1,cmp);
      for(int i=1;i<=row*col;i++){
            int t=longest(way,row,col,buff[i].subscript);
            if(t>long_path){
                  long_path=t;
            }
      }
      cout<<long_path<<endl;
      return 0;

}
