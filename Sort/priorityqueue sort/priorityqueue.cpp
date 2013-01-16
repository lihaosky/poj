//demostrating the usage of priority queue
//big elements are parents


#include<iostream>
#include<ctime>
using namespace std;
template<class T>
class priqueue
{
      int n,maxsize;
      T*x;
      void swap(int i,int j){
           T t=x[i];
           x[i]=x[j];
           x[j]=t;
           }
public:
       priqueue(int m)
       {maxsize=m;
       x=new T[maxsize+1];
       n=0;
       }
       //insert elements
       void insert(T t)
       {
            int i,p;
            x[++n]=t;
            for(i=n;i>1&&x[p=i/2]<x[i];i=p){
                                            swap(p,i);
            }
            }
       //extract big elements
       T extractmax()
       {int i,c;
       T t=x[1];
       x[1]=x[n--];
       for(i=1;(c=2*i)<=n;i=c){
                               if(c+1<=n&&x[c+1]>x[c]){
                                                       c++;
                                                       }
                               if(x[i]>=x[c]){
                                              break;
                                              }
                               swap(c,i);
       }
       return t;
       }
};

int main()
{
    priqueue<int> b(100000);
    srand(time(NULL));
    clock_t start=clock();
    for(int i=0;i<5000;i++){
            b.insert(rand()%10000);
            }
    clock_t end=clock();
    double t=(end-start)*1.0/CLOCKS_PER_SEC;
    cout<<t<<endl;
    for(int i=0;i<5000;i++){
            cout<<b.extractmax()<<" ";
            }
    cout<<endl;
    system("PAUSE");
    return 0;
}
    
