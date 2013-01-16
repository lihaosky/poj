///scholarship distribution 
#include<iostream>
using namespace std;

struct student
{
       int num;
       int chinese;
       int english;
       int math;
       int total;
       };
       
struct scholar
{
       int num;
       int mark;
       };

void sort(student a[],int i)
{
     for(int m=i-1;m>0;m--){
             for(int n=0;n<m;n++){
                     if(a[n].total<a[n+1].total){
                                                 student temp;
                                                 temp=a[n];
                                                 a[n]=a[n+1];
                                                 a[n+1]=temp;
                                                 }
                     if(a[n].total==a[n+1].total){
                                                   if(a[n].num>a[n+1].num){
                                                 student temp;
                                                 temp=a[n];
                                                 a[n]=a[n+1];
                                                 a[n+1]=temp;
                                                 }
                     }
             }
                                                                           
             }
}
int main()
{
    int num;
    student my[100];
    scholar you[4];
    cin>>num;
    for(int i=0;i<num;i++){
            my[i].num=i+1;
            cin>>my[i].chinese>>my[i].english>>my[i].math;
            my[i].total=my[i].chinese+my[i].english+my[i].math;
            }
    sort(my,num);
    for(int i=0;i<5;i++){
            cout<<my[i].num<<" "<<my[i].total<<endl;
            }
            system("PAUSE");
}
            
            
    
    
