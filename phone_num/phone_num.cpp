//In a city, the format of a phone number is one of the followings:
//„h xx-xxx-xxx
//„h xxxxxxxx
//„h xxxx-xxx-x
//where x is a digit between 0 to 9. Complete the following program which checks if an input
//phone number is valid.


#include<iostream>
#include<string>

using namespace std;
bool check(string);
int main()
{
    bool valid;
    string num;
    cin>>num;
    valid=check(num);
    if (valid){cout << "valid phone" << endl;}
    else{cout << "invalid phone" << endl;}
    system("PAUSE");
}

bool check(string a)
{
     int length=a.length();
     if(length!=8&&length!=10){return false;}
     if(length==8){
            for(int i=0;i<length;i++){
                    if(a[i]>57||a[i]<48){
                          return false;
                          }
                    }
            return true;
     }
     if(length==10){
              if(a[2]=='-'&&a[6]=='-'){
                         for(int i=0;i<length;i++){
                                 if(i==2||i==6){continue;}
                                 if(a[i]>57||a[i]<48){cout<<i<<"NO"<<endl;return false;}
                                 }
                         return true;
              }
              if(a[4]=='-'&&a[8]=='-'){
                        for(int i=0;i<length;i++){
                                 if(i==4||i==8){continue;}
                                 if(a[i]>57||a[i]<48){return false;}
                                 }
                         return true;
     }
             else{return false;}
             }
} 
