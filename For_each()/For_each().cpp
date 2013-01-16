//file: vector.cpp
//auhor: LIHAO
//function: to illustrate the various usage of c++ vectors
/*content:
          1.vector constructor
          2.vector member funtions
*/


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
    vector<int> a0;       //constructor vector<T> a, without parameters
    vector<int> a1(10,2); //constructor vector<T> a(i,j), where i is number of type, j is value of type
    vector<int> a2(10);   //constructor vector<T> a(i), where i is the number of type
    vector<int> a3(a1);   //constructor vector<T> a(a1), where a1 is a vector: a copy of a1
    vector<int> a4(a1.begin(),a1.end());//constructor vector<T> a(a.begin(),a.end()) a copy of a
    vector<int>:: iterator it; //demostrate usage of iterator
    for(it=a1.begin();it!=a1.end();it++){
                cout<<*it<<" ";
    }
    cout<<endl;
    a0.assign(10,2);     //member function assign, give vector a new value
    a1.assign(a0.begin()+1,a0.end());
    int my[]={1,2,3,4};
    a3.assign(my,my+4);
    cout<<a0.size()<<" "<<a1.size()<<" "<<a2.size()<<" "<<a3.size()<<endl;
    cout<<a0.back()<<" "<<a1.back()<<" "<<a2.back()<<" "<<a3.back()<<endl;//use of member function back(), it return the last item
    cout<<a0.front()<<" "<<a1.front()<<" "<<a2.front()<<" "<<a3.front()<<endl;//use of member function front(),it return first item
    //notice member funtion begin() and end() only return a iterator instead of value
    cout<<a0.capacity()<<endl;// capacity member function
    a0.clear();//clear() will drop all the element size become 0 
    cout<<a0.size()<<endl;
    cout<<a0.empty()<<endl;//empty() show whether the vector is empty
    a1.erase(a1.begin(),a1.begin()+3);//earase() earase the elements
    for(int i=0;i<a1.size();i++){cout<<a1[i]<<" ";}
    cout<<endl;
    a1.pop_back();        //pop_back() remove last element in the vector
    for(int i=0;i<a1.size();i++){cout<<a1[i]<<" ";}
    a1.push_back(12); //input element in the vector
    cout<<endl;
    for(int i=0;i<a1.size();i++){cout<<a1[i]<<" ";}
    cout<<endl;
    a1.resize(12);  //resize() assign new size of the 
    for(int i=0;i<a1.size();i++){cout<<a1[i]<<" ";}
    a1.swap(a3); //exchange the content of vectors size can be different
    cout<<endl;
    for(int i=0;i<a1.size();i++){cout<<a1[i]<<" ";}
    system("PAUSE");
}
