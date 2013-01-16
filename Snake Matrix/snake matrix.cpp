/**************************************
*   snake matrix
*   input number output snake matrix
*   input 3, output
*   1 3
*   2
*  author: lihao
*  date: Mar 14 2009
**************************************/
#include <iostream>
using namespace std;
int main()
{
      int a[100][100];
      a[1][1]=1;
      int n;
      cin>>n;
      for(int i=2;i<=n;i++){
            a[i][1]=a[i-1][1]+i-1;
      }
      for(int i=1;i<=n;i++){
            for(int j=2;j<=n-i+1;j++){
                  a[i][j]=a[i][j-1]+j+i-1;
            }
      }
      for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i+1;j++){
                  cout<<a[i][j]<<" ";
            }
            cout<<endl;
      }
      return 0;
}
