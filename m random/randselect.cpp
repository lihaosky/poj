//the program generate m random integers from n numbers
//output the m integers in increasing order
//AUTHOR: LIHAO
//VENUE: dormitory
//DATE: Jan 12 2009


#include<iostream>
using namespace std;
int main()
{
    unsigned int m,n;
    cout<<"input number of number you want to get and number of total numbers:"<<endl;
    cin>>m>>n;
    for(int i=0;i<n;i++){
            if(rand()%(n-i)<m){
                cout<<i<<" ";
                m--;
                }
    }
    cout<<endl;
    system("PAUSE");
}
