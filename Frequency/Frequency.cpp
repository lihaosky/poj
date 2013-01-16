//small prog to find maximum freq in an array

#include <iostream>
using namespace std;

int freq(int a[],int l,int u)
{
    if(l==u){
             return a[l];
             }
    int x1=freq(a,l,(l+u)/2);
    int x2=freq(a,(l+u)/2+1,u);
    if(x1==x2){
               return x1;
               }
    int x1_count=0;
    int x2_count=0;
    for(int i=l;i<=u;i++){
            if(a[i]==x1){
                         x1_count++;
                         }
            if(a[i]==x2){
                         x2_count++;
                         }
    }
    if(x1_count>x2_count){
                          return x1;
                          }
    else{
         return x2;
    }
}

int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            }
    cout<<freq(a,1,n)<<endl;
}
