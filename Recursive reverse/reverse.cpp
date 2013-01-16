//recursively reverse a array
//easy recursion
//AUTHOR: LIHAO
//DATE: Jan 27 2009
//VENUE: DORMITORY


#include <iostream>
#include <ctime>
using namespace std;

void reverse(int a[],int l,int u)
{
      if(l>=u){
            return;
      }
      int temp=a[l];
      a[l]=a[u];
      a[u]=temp;
      reverse(a,l+1,u-1);
}

void main()
{
      int n,a[100];
      cout << "How many numbers do you want? " << endl;
      cin>>n;
      cout << "The original numbers are: " << endl;
      srand(time(NULL));
      for(int i=0;i<n;i++){
            a[i]=rand()%100;
            cout<<a[i]<<" ";
      }
      cout << endl;
      cout << "The numbers after reverse are: " << endl;
      reverse(a,0,n-1);
      for(int i=0;i<n;i++){
            cout << a[i] << " ";
      }
      cout << endl;
}
