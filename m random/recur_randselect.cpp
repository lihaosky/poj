//use recursion to generate the m numbers
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: Jan 12 2009

#include <iostream>
using namespace std;

void randselect(int m,int n)
{
     if(m<=0){return;}
     if((rand()%n)<m){
         randselect(m-1,n-1);
         cout<<n-1<<" ";
         
     }
     else{
          randselect(m,n-1);
     }
}

int main()
{
    int m,n;
    cin>>m>>n;
    randselect(m,n);
    cout<<endl;
    system("PAUSE");
}
