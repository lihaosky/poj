//find the maximum subvector of a array
//compute in just linear time
//Author:LIHAO
//Date:Dec 16 2008
//Venue:Dormitory


#include<iostream>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

int maxsubvector(int a[],int n)
{
    int maxsofar=0;
    int maxendhere=0;
    for(int i=0;i<n;i++){
            maxendhere=max(maxendhere+a[i],0);
            maxsofar=max(maxendhere,maxsofar);
            }
    return maxsofar;
}

int main()
{
    int n,a[100];
    cout<<"input the size of the array:";
    cin>>n;
    cout<<"input the elements of the array:"<<endl;
    for(int i=0;i<n;i++){
            cin>>a[i];
            }
    cout<<"the sum of maximum subvector is: "<<maxsubvector(a,n)<<endl;
    system("PAUSE");
    return 0;
}
