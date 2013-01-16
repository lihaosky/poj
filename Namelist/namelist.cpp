#include <iostream>
#include <string>
using namespace std;
struct namelist
{
      string name;
      namelist* next;
};

namelist* append(namelist* h,string str)
{
      namelist* p=h;
      //go to the rear of the list
      while(p->next){
            p=p->next;
      }
      namelist* node=new namelist;
      node->name=str;
      node->next=NULL;
      p->next=node;
      return h;
}

namelist* Delete(namelist *h,string str)
{
      namelist*p =h->next;
      namelist*q=h;
      while(p){
            if(p->name==str){
                  q->next=p->next;
                  delete p;
                  p=q->next;
            }
            else{
                  q=q->next;
                  p=p->next;
            }
      }
      return h;
}

namelist* reverse(namelist *h)
{
      namelist*p=h->next;
      namelist*q=h;
      delete q;
      q=p;
      namelist *newh=NULL;
      while(p){
            namelist*node=new namelist;
            node->name=p->name;
            node->next=newh;
            newh=node;
            p=p->next;
            delete q;
            q=p;
      }
      namelist* temp=new namelist;
      temp->next=newh;
      newh=temp;
      return newh;
}

namelist* shuffle(namelist*h)
{
      namelist *p=h->next;
      int counter=1;
      namelist *pre;
      namelist* q=h;
      while(p){
            if(counter==2){
                  pre=h->next;
            }
            if(counter!=1&&counter%2){
                  namelist *t=p->next;
                  p->next=pre->next;
                  pre->next=p;
                  q->next=t;
                  pre=p;
                  p=t;
                  counter++;
            }
            else{
                        p=p->next;
                        q=q->next;
                  counter++;
            }
      }
        return h;
}



void output(namelist*h)
{
      namelist* p=h->next;
      while(p){
            cout<<p->name<<" ";
            p=p->next;
      }
      cout<<endl;
}

void main()
{
      namelist *h=new namelist;
      h->next=NULL;
      int a;
      string command,name;
      while(cin>>command){
           if(command=="append"){
                 cin>>name;
                 h=append(h,name);
                 output(h);
           }
           else if(command=="delete")
           {
                 cin>>name;
                 h=Delete(h,name);
                 output(h);
           }
           else if(command=="reverse"){
                 h=reverse(h);
                 output(h);
           }
           else if(command=="shuffle"){
                 h=shuffle(h);
                 output(h);
           }
      }
      return;
}


