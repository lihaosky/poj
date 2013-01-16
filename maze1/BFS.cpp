#include <iostream>
#include <queue>
using namespace std;
int row,col;
char maze[100][100];
bool used[100][100];
struct Re
{
      int row,col;
      int pre_r,pre_c;
      int label;
}re[1000];
int size;
void solve()
{
      size=0;
      bool exist=false;
      Re tmp;
      queue<Re> myqueue;
      tmp.label=0;
      tmp.row=0;
      tmp.col=0;
      re[size++]=tmp;
      myqueue.push(tmp);
      used[0][0]=true;
      while(!myqueue.empty()){
            tmp=myqueue.front();
            if(tmp.row-1>=0&&maze[tmp.row-1][tmp.col]=='.'&&used[tmp.row-1][tmp.col]==false){
                  Re tmp1;
                  tmp1.row=tmp.row-1;
                  tmp1.col=tmp.col;
                  tmp1.pre_r=tmp.row;
                  tmp1.pre_c=tmp.col;
                  tmp1.label=tmp.label+1;
                  myqueue.push(tmp1);
                  used[tmp.row-1][tmp.col]=true;
                  re[size++]=tmp1;
                  if(tmp1.row==row-1&&tmp1.col==col-1){
                        exist=true;
                        break;
                  }
            }
            if(tmp.row+1<row&&maze[tmp.row+1][tmp.col]=='.'&&used[tmp.row+1][tmp.col]==false){
                  Re tmp1;
                  tmp1.row=tmp.row+1;
                  tmp1.col=tmp.col;
                  tmp1.label=tmp.label+1;
                  tmp1.pre_r=tmp.row;
                  tmp1.pre_c=tmp.col;
                  myqueue.push(tmp1);
                  used[tmp.row+1][tmp.col]=true;
                  re[size++]=tmp1;
                  if(tmp1.row==row-1&&tmp1.col==col-1){
                        exist=true;
                        break;
                  }
            }
            if(tmp.col-1>=0&&maze[tmp.row][tmp.col-1]=='.'&&used[tmp.row][tmp.col-1]==false){
                  Re tmp1;
                  tmp1.row=tmp.row;
                  tmp1.col=tmp.col-1;
                  tmp1.pre_r=tmp.row;
                  tmp1.pre_c=tmp.col;
                  tmp1.label=tmp.label+1;
                  myqueue.push(tmp1);
                  used[tmp.row][tmp.col-1]=true;
                  re[size++]=tmp1;
                  if(tmp1.row==row-1&&tmp1.col==col-1){
                        exist=true;
                        break;
                  }
            }
            if(tmp.col+1<col&&maze[tmp.row][tmp.col+1]=='.'&&used[tmp.row][tmp.col+1]==false){
                  Re tmp1;
                  tmp1.row=tmp.row;
                  tmp1.col=tmp.col+1;
                  tmp1.pre_r=tmp.row;
                  tmp1.pre_c=tmp.col;
                  tmp1.label=tmp.label+1;
                  myqueue.push(tmp1);
                  used[tmp.row][tmp.col+1]=true;
                  re[size++]=tmp1;
                  if(tmp1.row==row-1&&tmp1.col==col-1){
                        exist=true;
                        break;
                  }
            }
            myqueue.pop();
      }
      if(exist==false){
            cout<<"not exist"<<endl;
            return;
      }
      int num=re[size-1].label,pre_r,pre_c;
      pre_r=re[size-1].row;
      pre_c=re[size-1].col;
      for(int i=size-1;i>=0;i--){
            if(re[i].label==num&&pre_r==re[i].row&&pre_c==re[i].col){
                  cout<<re[i].row+1<<" "<<re[i].col+1<<endl;
                  pre_r=re[i].pre_r;
                  pre_c=re[i].pre_c;
                  num--;
            }
      }
}

int main()
{

      cin>>row>>col;
      for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                  cin>>maze[i][j];
                  used[i][j]=false;
            }
      }
      solve();
}
