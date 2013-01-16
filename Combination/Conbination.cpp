//find combination recursively

#include <iostream>
using namespace std;
int a[100],b[100];
int l=0;
void combination(int a[],int n,int m)
{
     if(n<0){
             return;
             }
     if(m==0){
              for(int i=1;i<=l;i++){
                      cout<<b[i]<<" ";
                      }
              cout<<endl;
              return;
     }
     b[m]=a[n];
     combination(a,n-1,m-1);
     combination(a,n-1,m);
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            a[i]=i;
    }
    l=m;
    combination(a,n,m);
    system("PAUSE");
}
     
