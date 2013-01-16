//this solve the time problem of set1_randselect
//this will find m numbers in just m steps
//really tricky!! By Bob Floyd
//AUTHOR: LIHAO
//VENUE:DORMITORY
//DATE: Jan 12th 2009

#include<iostream>
#include<set>
using namespace std;
int main()
{
    unsigned int m,n;
    set<int> s;
    cin>>m>>n;
    clock_t start=clock();
    for(int j=n-m;j<n;j++){
            int t=rand()%(j+1);
            if(s.find(t)==s.end()){
                  s.insert(t);
                  }
            else{
                 s.insert(j);
                 }
    }
    clock_t end=clock();
    double t=(end-start)*1.0/CLOCKS_PER_SEC;
    set<int>::iterator i;

    cout<<endl;
    cout<<t<<endl;
    system("PAUSE");
}
