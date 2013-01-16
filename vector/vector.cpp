#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void say(int i)
{
     cout<<i<<" "<<endl;
}
int main()
{
    vector<int> room(10,2);
    vector<int>:: iterator it=room.begin();
    for(;it!=room.end();it++){
                            cout<<*it<<endl;
                            }
    vector<int> chamber(room);
    it=chamber.begin();
    for(;it!=chamber.end();it++){cout<<*it<<endl;}
    cout<<room.size()<<endl;
    system("PAUSE");
}
