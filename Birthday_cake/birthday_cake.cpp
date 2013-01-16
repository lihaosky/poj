/*Description
7��17����Mr.W�����գ�ACM-THUΪ��Ҫ����һ�����ΪN�е�M�����յ��⣬ÿ�㶼��һ��Բ���塣
�������������i(1 <= i <= M)�㵰���ǰ뾶ΪRi, �߶�ΪHi��Բ������i < Mʱ��Ҫ��Ri > Ri+1��Hi > Hi+1��
����Ҫ�ڵ�����Ĩ���ͣ�Ϊ�����ܽ�Լ���ѣ�����ϣ����������棨����һ����µ�����⣩�����Q��С��
��Q = S��
���̶Ը�����N��M���ҳ�����������������ʵ���Ri��Hi��ֵ����ʹS��С��
����Q�⣬�����������ݽ�Ϊ��������


Input
�����У���һ��ΪN��N <= 10000������ʾ�������ĵ�������ΪN�У��ڶ���ΪM(M <= 20)����ʾ����Ĳ���ΪM��

Output
��һ�У���һ��������S�����޽���S = 0����

Sample Input


100
2

Sample Output


68
*/
//AUTHOR:LIHAO
//DATE:Jan 31 2009
//VENUE: DORMITORY
//seems not perfect, can't find all the possible solutions"perhaps"
//




#include<iostream>
#include<cmath>
using namespace std;
int R[20];
int H[20];
int counter;
int area;
bool find(int r,int h,int m,int n)
{
      if(m==0){
            return false;
      }
      int i,j;
      for( i=r;m*i*i<=n;i++){
            for(j=h;m*j<=n;j++){
                  if(m*i*i*j>n){
                        break;
                  }
                  if(i*i*j==n&&m==1){
                        R[counter]=i;
                        H[counter++]=j;
                        area+=i*i;
                        area+=2*i*j;
                        return true;
                  }
                  if(i*i*j<n){
                        if(find(i+1,j+1,m-1,n-i*i*j)){
                              R[counter]=i;
                              H[counter++]=j;
                              area+=2*i*j;
                             return true;
                        }
                  }
            }
      }
      return false;
}


void main()
{
      int n;
      int m;
      int min=1000000;
      bool is_exist=false;
      cin>>n>>m;
      for(int k=1;m*k*k<=n;k++){
            for(int l=1;m*l<=n;l++){
                  if(m*k*k*l>n){
                        break;
                  }
                  area=0;
                  counter=0;
                  if(find(k,l,m,n)){
                        if(area<min){
                              min=area;
                        }
                        for(int i=0;i<counter;i++){
                              cout<<R[i]<<" "<<H[i]<<endl;
                        }
                        cout<<endl<<endl;
                        is_exist=true;
                  }
            }
      }
      if(is_exist){
            cout<<min<<endl;
      }
      else{
            cout<<0<<endl;
      }
      return;
}
