//pyramids aha

#include <iostream>
using namespace std;

int main()
{
      int h;
      cin>>h;
      int first_space=38;
      int second_space=1;
       for(int i=1;i<=40;i++){
             cout<<" ";
       }
       cout<<"*"<<endl;
       for(int i=1;i<=39;i++){
             cout<<" ";
       }
       cout<<"***"<<endl;
       for(int i=3;i<=h;i++){
             for(int j=1;j<=first_space;j++){
                   cout<<" ";
             }
             cout<<"**";
             for(int k=1;k<=second_space;k++){
                   cout<<"*";
             }
             cout<<"**"<<endl;
             first_space--;
             second_space+=2;
       }
       cout<<endl;
}
