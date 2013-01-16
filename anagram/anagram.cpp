//read from file and store the words and the anagrams 
//you can look up the anagrams of any words if they do exist in the file
//ie. store "opt" "top" if you look up "top" it will out put "opt" as well
//author: LiHao
//date:  21/nov/2008 


#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct anagram
{
       string orignal;
       string varies[20];
       int var_num;
};

void find(anagram my[],int& my_num,string temp,string in_file)//sort the word by alphabetic order of it's element, find if any match
{
     bool flag=false;
     for(int i=0;i<my_num;i++){  //match store
             if(temp==my[i].orignal){
                                     for(int k=0;k<my[i].var_num;k++){
                                             if(in_file==my[i].varies[k]){return;}
                                             }
                                     my[i].varies[my[i].var_num++]=in_file;
                                     flag=true;
                                        }
     }
     if(!flag){      //not match create new items
               my[my_num].orignal=temp;
               my[my_num].varies[my[my_num].var_num++]=in_file;
               my_num++;
     }
     return;
}

void sort(string& temp) //sort the element in the word
{
     for(int i=temp.length();i>0;i--){
             for(int j=0;j<i-1;j++){
                     if(temp[j]>temp[j+1]){
                                           char a;
                                           a=temp[j];
                                           temp[j]=temp[j+1];
                                           temp[j+1]=a;
                                           }
                     }
     }
     return;
}
     
int main()
{
    clock_t t1=clock();
    anagram my[1000];
    for(int i=0;i<100;i++){
            my[i].var_num=0;
            }
    int my_num=0;
    ifstream file;
    char file_name[20];
    cout<<"input file name: "<<endl;
    gets(file_name);
    file.open(file_name);
    if(file.fail()){
                    cout<<"wrong in open file!"<<endl;
                    system("PAUSE");
                    exit(1);
                    }
    string in_file;
    while(file>>in_file){        //read from file
                       string temp=in_file;
                       sort(temp);     //sort elemet in word store it in struct
                       find(my,my_num,temp,in_file);
                       }
    file.close();
    for(int i=0;i<my_num;i++){
            cout<<my[i].orignal<<endl;
            for(int j=0;j<my[i].var_num;j++){
                    cout<<my[i].varies[j]<<endl;
            }
    }
    cout<<"input the word you want to look up anagram: "<<endl;
    string input_word;
    bool is_in=false;
    cin>>input_word;
    sort(input_word);
    for(int i=0;i<my_num;i++){    //look up the word
            if(input_word==my[i].orignal){
                                          is_in=true;
                                          cout<<"the word's anagram is: "<<endl;
                                          for(int j=0;j<my[i].var_num;j++){
                                                  cout<<my[i].varies[j]<<endl;
                                                  }
            }
    }
    if(!is_in){
               cout<<"no find any words of this anagram!"<<endl;
               }
    clock_t t2=clock();
    double t=(t2-t1)*1.0/CLOCKS_PER_SEC;
    cout<<t<<endl;
    system("PAUSE");
    return 0;
}
                       
