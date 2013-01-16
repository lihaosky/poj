//first find a random number within n
//check if it already exists
//if so find again, if not insert it into s and then find another
//but when m and n are close and large it may take long time to find appropriate numbers
//AUTHOR:LIHAO
//VENUE: DORMITORY
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
    while(m>0){
               int t=rand()%n;
               if(s.find(t)==s.end()){
                                      s.insert(t);
                                      m--;
               }
               clock_t end=clock();
               double time=(end-start)*1.0/CLOCKS_PER_SEC;
               if(time>10){break;}
    }
    set<int>::iterator i;
    for(i=s.begin();i!=s.end();i++){
                                    cout<<*i<<" ";
    }
    cout<<endl;
    system("PAUSE");
}
