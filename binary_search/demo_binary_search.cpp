#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    while(1){
    int x;
    vector<int> a(100);
    srand(time(NULL));
    for(int i=0;i<100;i++){
            a[i]=rand()%1000;
            }
   
    sort(a.begin(),a.end());
     for(int i=0;i<100;i++){
            cout<<a[i]<<" ";
            }
     cout<<endl;
    int low=0;
    int high=99;
    int counter=0;
    int mid;
    cin>>x;
    while(low<=high){
            mid=(low+high)/2;
            if(a[mid]<x){
                         low=mid+1;
                         }
            else if(a[mid]>x){
                         high=mid-1;
                         }
                     
            else{
                 break;
                 }
            counter++;
            }
    if(low>high){cout<<"no found"<<endl;}
    else{cout<<"number in the array is"<<mid<<endl;}
    cout<<"need "<<counter<<" comparisons!"<<endl;
    }
    system("PAUSE");
    return 0;
}
