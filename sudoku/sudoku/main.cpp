#include"sudu.h"
#include<iostream>
#include <ctime>
using namespace std;

int main()
{

    bool end=false;
    bool fail=false;
    cout<<"********************************************************************************"<<endl;
    cout<<"        ___      _   _       ___           ___        _  _        _   _      "<<endl;
    cout<<"      /  __|    | | | |     |  _ \\        / _ \\      | |/ /      | | | |      "<<endl;
    cout<<"      \\__  \\    | |_| |     | (_| |      | (_| |     |   |       | |_| |      "<<endl;
    cout<<"      |____/     \\__,_|     |___ /        \\___/      |_|\\_\\       \\__,_|     "<<endl;
    cout<<"                                                                            "<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"Input your number, input space as 0"<<endl;
    sudu a;
    cout<<endl<<endl;
    clock_t start=clock();
    a.show();
    if(!a.isvalid()){cout<<"This sudoku is invalid!"<<endl;system("PAUSE");return 0;}
    a.indata();
    while(1){
            if(a.check()){a.forward();}
            else{
                 if(!a.isflow()){a.increase();}
                 else{a.backward();};
                 }
            if(a.isend()){end=true;break;}
            if(a.isfail()){fail=true;break;}
    }
    if(fail){cout<<endl<<endl<<"No answer"<<endl;}
    if(end){ cout<<endl<<endl<<"The answer is:"<<endl; a.print();}
    clock_t t=clock();
    double time=(t-start)*1.0/CLOCKS_PER_SEC;
    cout<<"Take "<<time<<" seconds to compute."<<endl;
    system("PAUSE");
}
