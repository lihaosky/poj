//game of hangman
//input a file name  which contains lots of words and then input level of game 
//level represents the length of the words
//you have 7 chances to guess the word
//same word will not count as a chance 
//if you fail to guess the word will come out at last
//AUTHOR: LIHAO
//DATE:2 Dec 2008
//VENUE: dormitoty

#include<iostream>
#include<fstream>
using namespace std;
void add_word(string file_name,int level,string word[],int &num)
{
       ifstream file;
       file.open(file_name.c_str());
       if(file.fail()){
                       cout<<"fail in open file"<<endl;
                       system("PAUSE");
                       exit(1);
       }
       if(level==1){
                    string temp;
                    while(file>>temp){
                                      if(temp.length()<=3){
                                                           word[num++]=temp;
                                                           }
                    }
       }
       if(level==2){
                    string temp;
                    while(file>>temp){
                                      if(temp.length()>3&&temp.length()<=8){
                                                           word[num++]=temp;
                                                           }
                    }
       }
       if(level==3){
                    string temp;
                    while(file>>temp){
                                      if(temp.length()>=8){
                                                           word[num++]=temp;
                                                           }
       }
       }
       file.close();
}
string pick_word(string word[],int num)
{
       int i;
       srand(time(NULL));
       i=rand()%num;
       return word[i];
}
bool is_win(char temp[],int len)
{
     for(int i=0;i<len;i++){
             if(temp[i]=='-'){
                              return false;
                              }
     }
     return true;
}

bool is_in(char c,char input[],int in_num)
{
     for(int i=0;i<in_num;i++){
             if(input[i]==c){return true;}
             }
     return false;
}
int main()
{
    string file;
    int level;
    cout<<"Input the file name of resourses and the level of the game:"<<endl;
    cin>>file>>level;
    string word1[100];
    int num=0;
    add_word(file,level,word1,num);
    string word=pick_word(word1,num);
    int counter=7;
    char c;
    char temp[100];
    char input[100];
    int in_num=0;
    cout<<"\t[";
    int len=word.length();
    for(int i=0;i<word.length();i++){
            temp[i]='-';
            cout<<'-';
    }
    cout<<"]"<<endl;
    while(counter){
                   int flag=0;
                   cout<<"("<<counter<<")"<<"[abcdefghijklmnopqrstuvwxyz]:";
                   cin>>c;
                   for(int i=0;i<word.length();i++){
                           if(word[i]==c){
                                          flag=1;
                                          temp[i]=c;
                                          }
                   }
                   if(flag==1){
                               if(is_win(temp,len)){
                                                    cout<<"["<<word<<"]"<<"  you win!"<<endl;system("PAUSE");return 0;
                                                    }
                   }
                   else{
                        if(!is_in(c,input,in_num)){
                                                   counter--;
                                                   input[in_num++]=c;
                        }
                   }
                   cout<<"\t";
                   for(int i=0;i<len;i++){
                           cout<<temp[i];
                   }
                   cout<<endl;
    }
    cout<<"["<<word<<"]"<<"  you lose  ";
    system("PAUSE");
    return 0;
}
                   
                   
