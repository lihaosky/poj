#include<iostream>
using namespace std;
int main(){
    char a;
    cout<<"Want lower letter or capital letter?(1 for lower and 2 for capital"<<endl;
    int i;
    cin>>i;
    switch(i){
    case 1:{
         for(a='a';a<='z';a++){
                               cout<<a<<" "<<(int)a<<endl;
                               }
                               break;
                               }
    case 2:{
         for(a='A';a<='Z';a++){
                               cout<<a<<" "<<(int)a<<endl;
                               }
                               break;
                               }
    }
    system("PAUSE");
}
