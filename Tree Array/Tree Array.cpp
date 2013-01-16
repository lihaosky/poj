/************************************************
*    AUTHOR: LIHAO
*    DATE: APRIL 26,2009
*    VENUE: LABORATORY
*
*    This is tree array implementation
*    An efficient data structure, useful :-)
*************************************************/

#include <iostream>
#include <cstring>
using namespace std;
int a[10000000];
int c[10000000];
int lowerbit(int x)
{
    return x&(x^(x-1));
}

void construct(int i)
{
    int l=lowerbit(i);
    while(l--){
        c[i]+=a[l];
    }
}

int get_sum(int i)
{
    int sum=0;
    while(i){
        sum+=c[i];
        i-=(lowerbit(i));
    }
    return sum;
}

void modify(int i,int j,int size)
{
    a[i]+=j;
    while(i<=size){
        c[i]+=j;
        i+=(lowerbit(i));
    }
}

int main()
{
    int n,low,up;
    cout << "how many do you want?" << endl;
    cin >> n;
    for(int i=0;i<=n;i++){
        a[i] = 1;
    }
    for(int i=1;i<=n;i++){
        construct(i);
    }
//    for(int i=1;i<=n;i++){
//        cout << c[i] << " ";
//    }
    cout << endl;
    cout << "Input the range of sum" << endl;
    cin >> low >> up;
    cout << get_sum(low) << " " << get_sum(up) << endl;
    cout<<"The sum between the range is:"<<get_sum(up)-get_sum(low)<<endl;
}
