//input a file find the longest common strings in the file
//AUTHOR:LIHAO
//DATE:Jan 17th 2009
//VENUE:Dormitory


#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

#define MAXN 50000000

char c[MAXN];  //strore characters in the file
char *a[MAXN]; //pointers point to the next posistion in c

bool cmp(char *a,char *b)
//compare two strings
{
      while(*a&&*b){
            if(*a==*b){
                  a++;
                  b++;
                  continue;
            }
            else if(*a<*b){
                  return true;
            }
            else{
                  return false;
            }
      }
      if(*a=='\0'){
            return true;
      }
      else{
            return false;
      }
}


int comlen(char*p,char *q)
//find the longest common string
{
      int i=0;
      while(*q&&*p++==*q++){
            i++;
      }
      return i;
}


using namespace std;
void main()
{
      string file_name;
      cout<<"input the file name:"<<endl;
      cin>>file_name;
      ifstream fp;
      fp.open(file_name.c_str());
      if(fp.fail()){
            cout<<"can't open file"<<endl;
            exit(1);
      }
      char ch;
      int n=0;
      while(1){
      //input characters from the file
            ch=fp.get();
            if(ch==EOF){
                break;
            }
            c[n]=ch;
            a[n]=&c[n++];
      }
      fp.close();
      stable_sort(a,a+n,cmp);
      int maxi=0;
      int maxlen=0;
      for(int i=0;i<n-1;i++){
            if(comlen(a[i],a[i+1])>maxlen){
                  maxlen=comlen(a[i],a[i+1]);
                  maxi=i;
            }
      }
       cout<<"the longest common string number is: "<<maxlen<<endl;
      cout<<"the longest common string is:"<<endl;
      for(int i=0;i<maxlen;i++){
            cout<<a[maxi][i];
      }
}

