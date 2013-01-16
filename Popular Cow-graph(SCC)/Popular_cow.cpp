/*******************************************************************************************
Popular Cows
Time Limit: 2000MS  Memory Limit: 65536K
Total Submissions: 4615  Accepted: 1858

Description

Every cow's dream is to become the most popular cow in the herd. In a herd of N (1 <= N <= 10,000) cows, you are given up to M (1 <= M <= 50,000) ordered pairs of the form (A, B) that tell you that cow A thinks that cow B is popular. Since popularity is transitive, if A thinks B is popular and B thinks C is popular, then A will also think that C is
popular, even if this is not explicitly specified by an ordered pair in the input. Your task is to compute the number of cows that are considered popular by every other cow.

Input

* Line 1: Two space-separated integers, N and M

* Lines 2..1+M: Two space-separated numbers A and B, meaning that A thinks B is popular.

Output

* Line 1: A single integer that is the number of cows who are considered popular by every other cow.

Sample Input

3 3
1 2
2 1
2 3

Sample Output

1

Hint

Cow 3 is the only cow of high popularity.

Source

USACO 2003 Fall
*********************************************************************************************/
//-_- at last got idea of graph, compute strongly connected components (SCC) , so classic, add oil
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: APRIL 13, 2009

#include <iostream>
#include <cstring>
#define V 10010
#define E 50010
using namespace std;
int in[E],out[E],order[V],e,flag[V],degree[V],pos,num,counter;
bool visit[V];
struct Point
{
      int id;
      Point* next;
}*mapa[V],*mapt[V];

void insert(int i,int j) //construct the graph, using adjacency list, and its transpose
{
            Point* tmp=new Point;
            tmp->id=j;
            tmp->next=mapa[i]->next;
            mapa[i]->next=tmp;

            Point* tmp1=new Point;
            tmp1->id=i;
            tmp1->next=mapt[j]->next;
            mapt[j]->next=tmp1;
}

void dfsa(Point* p) //depth first search, to compute SCC, need to record the coming sequence
{
      Point* k=p;
      visit[p->id]=true;
      while(p){
            if(!visit[p->id]){
                  dfsa(mapa[p->id]);
            }
            p=p->next;
      }
      order[e++]=k->id;
}

void dfst(Point* p) //depth first search in transpose, record the components by tag "e"
{
      visit[p->id]=true;
      flag[p->id]=e;
      while(p){
            if(!visit[p->id]){
                  dfst(mapt[p->id]);
            }
            p=p->next;
      }
}

int main()
{
      int v,n,x,y;
      memset(degree,0,sizeof(degree));
      e=0;
      counter=0;
      num=0;
      cin>>v>>n;
      for(int i=1;i<=v;i++){  //initialize the adjacency list
            mapa[i]=new Point;
            mapa[i]->id=i;
            mapa[i]->next=NULL;
            mapt[i]=new Point;
            mapt[i]->id=i;
            mapt[i]->next=NULL;
      }
      for(int i=1;i<=n;i++){ //construct graph
            cin>>x>>y;
            out[i]=x;
            in[i]=y;
            insert(x,y);
      }
      memset(visit,0,sizeof(visit));

      for(int i=1;i<=v;i++){  //first DFS
            if(!visit[i]){
                  dfsa(mapa[i]);
            }
      }
      memset(flag,0,sizeof(flag));
      memset(visit,0,sizeof(visit));
      e=0;
      for(int i=v-1;i>=0;i--){ //second DFS
            if(!visit[order[i]]){
                  dfst(mapt[order[i]]);
                  e++;
            }
      }
      for(int i=1;i<=n;i++){  //judge if the out edge connected with other components, to get the components not going out
            int ee=flag[out[i]];
            int ss=flag[in[i]];
            if(ee!=ss){
                  degree[ee]++;
            }
      }
      for(int i=0;i<e;i++){  //compute how many components there are without edge going out
            if(degree[i]==0){
                  pos=i;
                  counter++;
            }
      }
      if(counter>1){   //more than two indicate no popular cows
            cout<<0<<endl;
      }
      else{
            for(int i=1;i<=v;i++){  //get how many cows in this components
                  if(flag[i]==pos){
                        num++;
                  }
            }
            cout<<num<<endl;
      }
}
