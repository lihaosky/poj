#include <iostream>
using namespace std;

void insert(int x[],int i)
{
     x[i>>5]|=(1<<(i&31));
}

bool test(int x[],int i)
{
     return (x[i>>5]&(1<<(i&31)));
}
int main()
{
    cout<<(1<<31)<<endl;
    int x;
    cin>>x;
    int *set= new int[1+x/32];
    for(int i=0;i<1+x/32;i++){
            set[i]=0;
            }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
            int a;
            cin>>a;
            insert(set,a);
            }
    for(int i=0;i<=x;i++){
            if(test(set,i)){
                        cout<<i<<" ";
                        }
    }
    cout<<endl;
    system("PAUSE");
}
