//classic problem: solving Tower of Hanio using Recursion
//Author: LIHAO
//VENUE: DORMITORY
//DATE: Jan 22

#include <iostream>
using namespace std;

void move(int i,char a,char b,char c,int& counter)
{
     counter++;
     cout<<"move "<<i<<" from "<<a<<" to "<<b<<endl;
}

void hanio(int i,char a,char b,char c,int& counter)
{
     if(i==1){
              move(i,a,b,c,counter);
              return;
     }
     hanio(i-1,a,c,b,counter);
     move(i,a,b,c,counter);
     hanio(i-1,c,b,a,counter);
}

int main()
{
    int n;
    int counter=0;
    cout<<"how many disks do you have?"<<endl;
    cin>>n;
    cout<<"the movement of the disks from peg A to peg C through peg B is:"<<endl;
    hanio(n,'A','C','B',counter);
    cout<<counter<<endl;
    system("PAUSE");
    return 0;
}
