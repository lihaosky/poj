//dynamic programming to solve finbonacci 


#include<iostream>
using namespace std;

int main()
{
    int fin[1000];
    fin[0]=0;
    fin[1]=1;
    int n;
    cout<<"input the number of finbonaci you want:"<<endl;
    cin>>n;
    if(n==0){cout<<fin[0]<<endl;system("PAUSE");return 0;}
    if(n==1){cout<<fin[1]<<endl;system("PAUSE");return 0;}
    for(int i=2;i<n;i++){
            fin[i]=fin[i-1]+fin[i-2];
            }
    cout<<fin[n-1]<<endl;
    system("PAUSE");
    return 0;
}
    
