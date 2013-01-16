//analog of move cursor to choose 
//因为 对于 上下左右 和别的一些扩展键 
//使用getch()会先返回一个0 再使用一次getch()这时返回的才是扫描码
//ASCII up:  72
//ASCII down:80
//ASCII left:75
//ASCII right:77
//system("cls") is to clear what is dipicted on the screen
//AUTHOR:LIAHO
//DATE: 2 Dec  2008
//VENUE:dormitory
//////////////////////////////////////////
#include <iostream> 
#include <conio.h> 
using namespace std; 

void menu(int pos)
{
     for(int i=0;i<5;i++){
             if(pos==i){cout<<"-->you are a genius"<<endl;}
             else{cout<<"   you are a genius"<<endl;}
             }
     return;
}
int main()
{
    char a;
    a=getch();
    if(a==-32){
               a=getch();
    }
    cout<<"The ascii code of the key is: "<<(int)a<<endl;
    int pos=0;
        while(1){
           cout<<"choose the book you like:"<<endl;
           menu(pos);
           char ans=getch();
           if(ans==-32){ans=getch();}
           if(ans==72){if(pos==0){pos=4;}else{pos--;}}
           if(ans==80){if(pos==4){pos=0;}else{pos++;}}
           if(ans==13){break;}
           system("cls");
    } 
    system("PAUSE");
    return 0;
}
