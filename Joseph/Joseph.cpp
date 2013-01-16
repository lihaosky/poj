//Joseph problem
//Author:LIHAO
//Date: 1st Dec 2008
//Venue: Dormitory


#include<iostream>
#include<stdlib.h>
using namespace std;
struct person
{
       int num;
       person*next;
};

person* init(person*h,int n)
{
      
        person* tail=h;
        for(int i=1;i<n;i++){
                person* temp=(person*)malloc(sizeof(person));
                temp->num=i+1;
                tail=tail->next=temp;
                }
        tail->next=h;
        return h;
}

int main()
{
    person* h=(person*)malloc(sizeof(person));
    h->num=1;
    int n;
    cout<<"�����˵ĸ���:";
    cin>>n;
    cout<<"������Ծ����:";
    int jump;
    cin>>jump; 
    clock_t start=clock();
    h=init(h,n);
    person* pre=h;
    while(pre->next!=h){
                      pre=pre->next;
                      }
    person* cur=h;
    for(int i=1;i<n;i++){
            for(int j=1;j<jump;j++){
                    pre=pre->next;
                    cur=cur->next;
                    }
            pre->next=cur->next;
            free(cur);
            cur=pre->next;
    }
    cout<<"���ʣ�µ�����:"<<cur->num<<endl;
    clock_t end=clock();
    double time=(end-start)*1.0/CLOCKS_PER_SEC;
    cout<<"��ʱ: "<<time<<" ��"<<endl;
    system("PAUSE");
    return 0;
}
