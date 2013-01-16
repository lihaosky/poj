//read a file name
//the file contains nonnegtive integers and operators including + - *
//the format is two lines of integers and a line of operator
//the integers can be arbitrarily large
//AUTHOR: LIHAO
//DATE: Jan 26 2009
//VENUE: DORMITORY


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    int digit;
    Node* next;
    Node* previous;
};


void insert(Node* &h,Node* &e,int num)
{
    Node* p=h;
    if(!p){
          Node*temp=new Node;
          temp->digit=num;
          temp->next=NULL;
          temp->previous=NULL;
          h=temp;
          e=temp;
          return ;
    }
    while(p->next){
       p=p->next;
    }
    Node* temp=new Node;
    temp->digit=num;
    temp->next=NULL;
    temp->previous=p;
    p->next=temp;
    e=temp;
    return ;
}

Node* add(Node *e1,Node* e2)
{
    Node*p1=e1;
    Node*p2=e2;
    Node*p3=NULL;
    int carry=0;
    int digit=0;
    while(p1&&p2){
         digit=p1->digit+p2->digit+carry;
         carry=digit/10;
         digit%=10;
         Node* temp=new Node;
         temp->next=NULL;
         temp->digit=digit;
         temp->next=p3;
         p3=temp;
         p1=p1->previous;
         p2=p2->previous;
     }
     while(p1){
          digit=p1->digit+carry;
          carry=digit/10;
          digit%=10;
          Node* temp=new Node;
          temp->digit=digit;
          temp->next=p3;
          p3=temp;
          p1=p1->previous;
     }
     while(p2){
          int digit=p2->digit+carry;
          carry=digit/10;
          digit%=10;
          Node* temp=new Node;
          temp->digit=digit;
          temp->next=p3;
          p3=temp;
          p2=p2->previous;
     }
     if(carry){
          Node* temp=new Node;
          temp->digit=carry;
          temp->next=p3;
          p3=temp;
     }
     return p3;
}

Node* multiply(Node* h1,Node* e1,Node* h2,Node* e2)
{
   Node* p2=NULL;
   Node* pos=NULL;
   Node* p=NULL;
   Node* pre=NULL;
   int digit=0;
   int carry;
   while(e2){
        carry=0;
        p=e1;
        pre=pos;
        p2=pos;
        while(p){
             digit=(e2->digit*p->digit+carry);
             if(p2){
                    digit+=p2->digit;
                    p2->digit=digit%10;
                    carry=digit/10;
             }
             else if(!p2&&!pre){
                   Node* temp=new Node;
                   temp->next=NULL;
                   temp->previous=NULL;
                   temp->digit=digit%10;
                   carry=digit/10;
                   p2=temp;
                   pos=temp;
             }
             else{
                   Node* temp=new Node;
                   temp->next=pre;
                   temp->previous=NULL;
                   pre->previous=temp;
                   temp->digit=digit%10;
                   carry=digit/10;
                   p2=temp;
             }
             p=p->previous;
             pre=p2;
             p2=p2->previous;
         }
         if(carry){
                  Node* temp=new Node;
                  temp->digit=carry;
                  temp->next=pre;
                  pre->previous=temp;
                  temp->previous=NULL;
                  p2=temp;
                  pre=p2;
        }
        pos=pos->previous;
        e2=e2->previous;
    }
    return pre;
}


bool cmp_digit(Node* e1,Node* h1,Node* e2,Node* h2)
{
   int n_digit1=0;
   int n_digit2=0;
   Node* p1=e1;
   Node* p2=e2;
   Node* q1=h1;
   Node* q2=h2;
   while(p1){
       n_digit1++;
       p1=p1->previous;
   }
   while(p2){
       n_digit2++;
       p2=p2->previous;
   }
   if(n_digit1>n_digit2){
       return true;
   }
   else if(n_digit1<n_digit2){
       return false;
   }
   else{
        while(q1){
              if(q1->digit>q2->digit){
                     return true;
              }
              else if(q1->digit<q2->digit){
                     return false;
             }
             else{
                   q1=q1->next;
                   q2=q2->next;
             }
        }
    }
    return true;
}

Node* subtract(Node* h1,Node* e1,Node* h2,Node* e2)
{
    Node* p1h=h1;
    Node* p1e=e1;
    Node* p2h=h2;
    Node* p2e=e2;
    int digit=0;
    bool flag=(cmp_digit(p1e,p1h,p2e,p2h));
    if(flag==true){
             Node* p3=NULL;
             while(e2){
                  if(e2->digit>e1->digit){
                           digit=10+e1->digit-e2->digit;
                           e1->previous->digit--;
                           Node *temp=new Node;
                           temp->digit=digit;
                           temp->next=p3;
                           p3=temp;
                  }
                  else{
                            digit=e1->digit-e2->digit;
                            Node* temp=new Node;
                            temp->digit=digit;
                            temp->next=p3;
                            p3=temp;
                   }
                   e2=e2->previous;
                   e1=e1->previous;
            }
            while(e1){
                    Node *temp=new Node;
                    if(e1->digit<0){
                           e1->digit+=10;
                           e1->previous->digit--;
                    }
                    temp->digit=e1->digit;
                    temp->next=p3;
                    p3=temp;
                    e1=e1->previous;
            }
            return p3;
     }
     else{
          Node* p3=NULL;
          while(e1){
                  if(e1->digit>e2->digit){
                           digit=10+e2->digit-e1->digit;
                           e2->previous->digit--;
                           Node *temp=new Node;
                           temp->digit=digit;
                           temp->next=p3;
                           p3=temp;
                  }
                  else{
                            digit=e2->digit-e1->digit;
                            Node* temp=new Node;
                            temp->digit=digit;
                            temp->next=p3;
                            p3=temp;
                   }
                   e2=e2->previous;
                   e1=e1->previous;
            }
            while(e2){
                    Node *temp=new Node;
                    if(e2->digit<0){
                           e2->digit+=10;
                           e2->previous->digit--;
                    }
                    temp->digit=e2->digit;
                    temp->next=p3;
                    p3=temp;
                    e2=e2->previous;
            }
            return p3;
     }

}


void output(Node* h)
{
    Node*p=h;
    while(p&&p->digit==0){
         p=p->next;
    }
    if(!p){
         cout<<"0";
         return;
    }
    while(p){
        cout<<p->digit;
        p=p->next;
    }
}

void free(Node* h)
{
    Node*p=h;
    Node*q;
    while(p){
       q=p->next;
       delete p;
       p=q;
    }
}

int main()
{
   Node* operand1head;
   Node* operand1end;
   Node* operand2head;
   Node* operand2end;
   Node* result;
   int counter=1;
   ifstream fp;
   string fname;
   cout<<"Input the file name: " <<endl;
   cin>>fname;
   fp.open(fname.c_str());
   if(fp.fail()){
      cout << "can't open filexpected unqualified-id e" <<endl;
      return 0;
    }
   string str;
   int digit;
   while(fp>>str){
         if(counter%3==1){
              operand1head=NULL;
              operand1end=NULL;
              for(int i=0;str[i];i++){
                     digit=str[i]-48;
                     insert(operand1head,operand1end,digit);
               }
         }
         else if(counter%3==2){
              operand2head=NULL;
              operand2end=NULL;
              for(int i=0;str[i];i++){
                     digit=str[i]-48;
                     insert(operand2head,operand2end,digit);
              }
          }
         else{
                      if(str=="+"){
                            result=add(operand1end,operand2end);
                            output(result);
                            cout << endl;
                       }
                      else if(str=="-"){
                                if((cmp_digit(operand1end,operand1head,operand2end,operand2head))==false){
                                                          cout << "-";
                                }
                                result=subtract(operand1head,operand1end,operand2head,operand2end);
                                output(result);
                                cout << endl;
                      }
                      else{
                            result=multiply(operand1head,operand1end,operand2head,operand2end);
                            output(result);
                            cout << endl;
                       }
                       free(operand1head);
                       free(operand2head);
                       free(result);
              }

      counter++;

   }
   return 0;
}
