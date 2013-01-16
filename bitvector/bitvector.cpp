//demostrate the usage of bit vector
//turn on the corresponding number of bit if the corresponding number is 
//in the array
//output the sorted number 
//mainly to save space
//AUTHOR:LIHAO
//VENUE:DORMITORY
//DATE:Jan 13th 2009

#include <iostream>
using namespace std;

void insert(int x[],int i)
//turn on the bit
{
     x[i>>5]|=(1<<(31-i%32));
}

bool test(int x[],int i)
//check if the bit is turned on
{
     return (x[i>>5]&(1<<(31-i%32)));
}
int main()
{
    int x;
    cout<<"input the maximum number in the array"<<endl;
    cin>>x;
    int *set= new int[1+x/32];
    for(int i=0;i<1+x/32;i++){
            set[i]=0;
            }
    insert(set,x);
    int n;
    cout<<"how many numbers do you have left?"<<endl;
    cin>>n;
    cout<<"input the left numbers(must be smaller than the maximum number)"<<endl;
    for(int i=0;i<n;i++){
            int a;
            cin>>a;
            insert(set,a);
            }
    cout<<"the numebrs are:"<<endl;
    for(int i=0;i<=x;i++){
            if(test(set,i)){
                        cout<<i<<" ";
                        }
    }
    cout<<endl;
    delete []set;
    system("PAUSE");
}
