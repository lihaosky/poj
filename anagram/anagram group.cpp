/*************************************************
Anagram Groups
Time Limit: 1000MS  Memory Limit: 65536K
Total Submissions: 1499  Accepted: 445

Description

World-renowned Prof. A. N. Agram's current research deals with large anagram groups. He has just found a new application for his theory on the distribution of characters in English language texts. Given such a text, you are to find the largest anagram groups.

A text is a sequence of words. A word w is an anagram of a word v if and only if there is some permutation p of character positions that takes w to v. Then, w and v are in the same anagram group. The size of an anagram group is the number of words in that group. Find the 5 largest anagram groups.
Input

The input contains words composed of lowercase alphabetic characters, separated by whitespace(or new line). It is terminated by EOF. You can assume there will be no more than 30000 words.
Output

Output the 5 largest anagram groups. If there are less than 5 groups, output them all. Sort the groups by decreasing size. Break ties lexicographically by the lexicographical smallest element. For each group output, print its size and its member words. Sort the member words lexicographically and print equal words only once.
Sample Input

undisplayed
trace
tea
singleton
eta
eat
displayed
crate
cater
carte
caret
beta
beat
bate
ate
abet

Sample Output

Group of size 5: caret carte cater crate trace .
Group of size 4: abet bate beat beta .
Group of size 4: ate eat eta tea .
Group of size 1: displayed .
Group of size 1: singleton .

Source

Ulm Local 2000
***********************************************************/
//just use hash table a_a :-) good
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 5 APRIL 2009
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

#define M 50023
using namespace std;
struct Word
{
      string ang[15];
      int number;
      int size;
};
Word myword[30000];



struct Table
{
      string key;
      int pos;
      Table* next;
};
Table *mytable[M];

int hash_fun(string a)
{
      int val=0;
      for(int i=0;i<a.length()-1;i++){
            val=((val+a[i])*128)%60013;
      }
      val=(val+a[a.length()-1])%60013;
      return val;
}
void insert(Table*& a,string b,int pos)
{
      if(!a){
            a=new Table;
            a->next=NULL;
            a->key=b;
            a->pos=pos;
            return ;
      }
      Table* tmp=new Table;
      tmp->key=b;
      tmp->pos=pos;
      tmp->next=a;
      a=tmp;
}

Table* find(Table* a,string b)
{
      while(a){
            if(a->key==b){
                  return a;
            }
            a=a->next;
      }
      return NULL;
}

bool find_word(Word a,string b)
{
      for(int i=0;i<a.number;i++){
            if(a.ang[i]==b){
                  return true;
            }
      }
      return false;
}
void sort(string& temp)
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

bool cmp(Word a,Word b)
{
      if(a.size>b.size){
            return true;
      }
      if(a.size<b.size){
            return false;
      }
      else{
            return a.ang[0]<b.ang[0];
      }
}

int main()
{
      string input,tmp;
      memset(mytable,NULL,M);
      for(int i=0;i<30000;i++){
            myword[i].number=0;
            myword[i].size=0;
      }
      int size=0,hash_val;
      while(cin>>input){
            tmp=input;
            sort(tmp);
            hash_val=hash_fun(tmp);
            Table* p=find(mytable[hash_val],tmp);
            if(p){
                  if(!find_word(myword[p->pos],input)){
                        myword[p->pos].ang[myword[p->pos].number++]=input;
                  }
                  myword[p->pos].size++;
            }
            else{
                  insert(mytable[hash_val],tmp,size);
                  myword[size].ang[myword[size].number++]=input;
                  myword[size].size++;
                  size++;
            }
      }
      for(int i=0;i<size;i++){
            sort(myword[i].ang,myword[i].ang+myword[i].number);
      }
      sort(myword,myword+size,cmp);
      for(int i=0;i<5&&i<size;i++){
            cout<<"Group of size "<<myword[i].size<<": ";
            for(int j=0;j<myword[i].number;j++){
                  cout<<myword[i].ang[j]<<" ";
            }
            cout<<"."<<endl;
      }
}
