//Businesses like to have memorable telephone numbers. 
//One way to make a telephone number memorable is to have it spell a memorable word or phrase. 
//For example, you can call the University of Waterloo by dialing the memorable TUT-GLOP. 
//Sometimes only part of the number is used to spell a word. 
//When you get back to your hotel tonight you can order a pizza from Gino's by dialing 310-GINO. 
//Another way to make a telephone number memorable is to group the digits in a memorable way. 
//You could order your pizza from Pizza Hut by calling their ``three tens'' number 3-10-10-10. 

//The standard form of a telephone number is seven decimal digits with a hyphen between the third and fourth digits 
//(e.g. 888-1200). The keypad of a phone supplies the mapping of letters to numbers, as follows: 

//A, B, and C map to 2 
//D, E, and F map to 3 
//G, H, and I map to 4 
//J, K, and L map to 5 
//M, N, and O map to 6 
//P, R, and S map to 7 
//T, U, and V map to 8 
//W, X, and Y map to 9 

//There is no mapping for Q or Z. Hyphens are not dialed, and can be added and removed as necessary.
// The standard form of TUT-GLOP is 888-4567, the standard form of 310-GINO is 310-4466, 
//and the standard form of 3-10-10-10 is 310-1010. 

//Two telephone numbers are equivalent if they have the same standard form. (They dial the same number.) 

//Your company is compiling a directory of telephone numbers from local businesses. 
//As part of the quality control process you want to check that no two (or more) businesses in 
//the directory have the same telephone number. 


//Input

//The input will consist of one case. The first line of the input specifies the number of 
//telephone numbers in the directory (up to 100,000) as a positive integer alone on the line. 
//The remaining lines list the telephone numbers in the directory, with each number alone on a line. 
//Each telephone number consists of a string composed of decimal digits, uppercase letters (excluding Q and Z) and hyphens. 
//Exactly seven of the characters in the string will be digits or letters. 

//Output

//Generate a line of output for each telephone number that appears more than once in any form. 
//The line should give the telephone number in standard form, followed by a space, 
//followed by the number of times the telephone number appears in the directory. 
//Arrange the output lines by telephone number in ascending lexicographical order. 
//If there are no duplicates in the input print the line:




#include<iostream>
#include<string>
using namespace std;
struct directory
{string num;
int quantity;
directory* next;
};


int main()
{
    int n;
    cin>>n;
    directory*head=new directory;
    for(int i=0;i<n;i++){
            string temp;
            cin>>temp;
            for(int j=0;j<temp.length();j++){
                    if(temp[j]=='-'){temp.erase(j,1);}
                    }
            if(temp[3]!='-'){temp.insert(3,"-");}
            for(int k=0;k<temp.length();k++){
                    if(temp[k]=='A'||temp[k]=='B'||temp[k]=='C'){temp[k]='2';}
                    if(temp[k]=='D'||temp[k]=='E'||temp[k]=='F'){temp[k]='3';}
                    if(temp[k]=='E'||temp[k]=='G'||temp[k]=='H'){temp[k]='4';}
                    if(temp[k]=='L'||temp[k]=='J'||temp[k]=='K'){temp[k]='5';}
                    if(temp[k]=='O'||temp[k]=='M'||temp[k]=='N'){temp[k]='6';}
                    if(temp[k]=='P'||temp[k]=='R'||temp[k]=='S'){temp[k]='7';}
                    if(temp[k]=='T'||temp[k]=='U'||temp[k]=='V'){temp[k]='8';}
                    if(temp[k]=='W'||temp[k]=='X'||temp[k]=='Y'){temp[k]='9';}
            }
            if(!i){
                      head->num=temp;
                      head->quantity=1;
                      head->next=NULL;
                      }
            else{
                 directory*p=head;
                 while(p){
                          if(temp==p->num){
                                           p->quantity++;
                          }
                          if(p==head&&temp<p->num){
                                                   directory*node=new directory;
                                                   node->num=temp;
                                                   node->quantity=1;
                                                   node->next=head;
                                                   head=node;
                                                   break;
                                                   }
                          if(p->next==NULL&&temp>p->num){
                                                   directory*node=new directory;
                                                   node->num=temp;
                                                   node->quantity=1;
                                                   node->next=NULL;
                                                   p->next=node;
                                                   break;
                                                   }
                          if(temp>p->num&&temp<p->next->num){
                                                   directory*q=p->next;
                                                   directory*node=new directory;
                                                   node->num=temp;
                                                   node->quantity=1;
                                                   p->next=node;
                                                   node->next=q;
                                                   break;
                                                   }
                          p=p->next;
              }
            }
    }
    directory*p=head;
    bool exist=false;
    while(p){
             if(p->quantity!=1){
             exist=true;
             cout<<p->num<<" "<<p->quantity<<endl;
             }
             p=p->next;
    }
    if(!exist){cout<<"No duplicates."<<endl;}
    system("PAUSE");
    return 0;
}
