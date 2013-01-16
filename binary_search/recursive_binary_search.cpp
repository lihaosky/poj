#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binary_search(vector<int> a,int low,int high,int x)
{
    int l=low;
    int h=high;
    if(low>high){return -1;}  //termination condition
    int mid=(l+h)/2;
    if(a[mid]==x){return mid;} //found
    else if(a[mid]>x){return binary_search(a,low,mid-1,x);}//smaller than current find in lower bounds
    else{return binary_search(a,mid+1,high,x);}  //bigger than current find in upper bounds
}


int main()
{
    vector<int> a(100);
    srand(time(NULL));
    for(int i=0;i<100;i++){
            a[i]=rand()%1000;   //generate random array
            }
    sort(a.begin(),a.end());    //sort the array
    for(int i=0;i<100;i++){
            cout<<a[i]<<" ";
            }
    int x;
    cout<<endl;
    cout<<"input the number you want to search:";
    cin>>x;
    int pos;
    pos=binary_search(a,0,99,x);
    if(pos==-1){cout<<"not exist in the array!"<<endl;}
    else{cout<<"index of the number is :"<<pos<<endl;}
    system("PAUSE");
    return 0;
}
    
