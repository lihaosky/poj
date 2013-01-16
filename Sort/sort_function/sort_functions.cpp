///////////////////////////////////////////////////////////////////////////////////////////////////
//a few sort functions in algorithm.h/////////////////////////////////////////////////////////////
//included sort_heap(),stable_sort(),sort()///////////////////////////////////////////////////////
//quite useful because stable_sort(),sort_heap can sort not only numbers but also other data type/
//LIHAO 17/NOV/2008///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool com(int i,int j)
{  
     return j<i;
}
bool cmp(string a,string b)     //these are comparison functions
{
     return a>b;
}
struct stu{
       int birth;
       int id;
       };
bool cam(stu a,stu b)
{
     return a.birth<b.birth;
}
int main()
{
    vector<int> a;
    string my[10];
    stu cla[]={12,13,10,14,9,15};
    for(int j=0;j<20;j++){
            a.push_back(j);
            }
    random_shuffle(a.begin(),a.end());  //random shuffle make the elements in vector in random order
    for(int j=0;j<a.size();j++){
            cout<<a[j]<<" ";
            }
            cout<<endl;
    make_heap(a.begin(),a.end()); //make heap before sort would give a sorted vector otherwise it is not    //sort heap
    sort_heap(a.begin(),a.end());
    for(int j=0;j<a.size();j++){
            cout<<a[j]<<" ";
            }
    cout<<endl;
    cout<<"input string"<<endl;
    for(int j=0;j<3;j++){
            cin>>my[j];
    }
    stable_sort(my,my+3,cmp);  //see what is stable_sort it can sort string
    for(int j=0;j<3;j++){
            cout<<my[j]<<" ";
            }
    cout<<endl;
    stable_sort(cla,cla+3,cam); //stable sort sort a structure
    for(int j=0;j<3;j++){
            cout<<cla[j].birth<<" ";
            }
    cout<<endl;
    system("PAUSE");
}
    
