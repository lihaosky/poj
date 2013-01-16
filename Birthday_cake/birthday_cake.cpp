/*Description
7月17日是Mr.W的生日，ACM-THU为此要制作一个体积为Nπ的M层生日蛋糕，每层都是一个圆柱体。
设从下往上数第i(1 <= i <= M)层蛋糕是半径为Ri, 高度为Hi的圆柱。当i < M时，要求Ri > Ri+1且Hi > Hi+1。
由于要在蛋糕上抹奶油，为尽可能节约经费，我们希望蛋糕外表面（最下一层的下底面除外）的面积Q最小。
令Q = Sπ
请编程对给出的N和M，找出蛋糕的制作方案（适当的Ri和Hi的值），使S最小。
（除Q外，以上所有数据皆为正整数）


Input
有两行，第一行为N（N <= 10000），表示待制作的蛋糕的体积为Nπ；第二行为M(M <= 20)，表示蛋糕的层数为M。

Output
仅一行，是一个正整数S（若无解则S = 0）。

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
