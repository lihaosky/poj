///////////////////////////////////////////requirement/////////////////////////////////////////////////////////////////
//You are going to compute the area of a special kind of polygon. /////////////////////////////////////////////////////
//One vertex of the polygon is the origin of the orthogonal coordinate system. ////////////////////////////////////////
//From this vertex, you may go step by step to the following vertexes of the polygon until back to the initial vertex. /
//For each step you may go North, West, South or East with step length of 1 unit, //////////////////////////////////////
//or go Northwest, Northeast, Southwest or Southeast with step length of square root of 2. /////////////////////////////
//The first line of input is an integer t (1 <= t <= 20), the number of the test polygons. //////////////////////////////
//Each of the following lines contains a string composed of digits 1-9 describing ///////////////////////////////////////
//how the polygon is formed by walking from the origin. Here 8, 2, 6 and 4 represent North, South, East and West, ///////
//while 9, 7, 3 and 1 denote Northeast, Northwest, Southeast and Southwest respectively. ////////////////////////////////
//Number 5 only appears at the end of the sequence indicating the stop of walking. //////////////////////////////////////
//You may assume that the input polygon is valid which means that the endpoint is always the start point ////////////////
//and the sides of the polygon are not cross to each other.Each line may contain up to 1000000 digits.///////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Author:LIHAO
//Date: 1st Dec 2008
//Venue: Dormitory

#include<iostream>
#include<vector>
using namespace std;

struct point
{  char x;
   char y;
  point* next;
};

int max(int a,int b)
{
    return a>=b?a-b:b-a;
}
point* init(point* h,int& low,int& high)
{
       char dire;
       point* cur=h;
       while(1){
                dire=getchar();
                if(dire=='5'){
                              cur->next=h; return h;}
                if(dire=='8'){
                            point* temp=new point;
                            temp->x=cur->x;
                            temp->y=cur->y+1;
                            cur=cur->next=temp;
                            }
                if(dire=='2'){
                            point*temp=new point;
                            temp->x=cur->x;
                            temp->y=cur->y-1;
                            cur=cur->next=temp;
                            }
                if(dire=='6'){
                            point*temp=new point;
                            temp->x=cur->x+1;
                            temp->y=cur->y;
                            cur=cur->next=temp;
                            }
                if(dire=='4'){
                            point* temp=new point;
                            temp->x=cur->x-1;
                            temp->y=cur->y;
                            cur=cur->next=temp;
                            }
                if(dire=='9'){
                            point* temp=new point;
                            temp->x=cur->x+1;
                            temp->y=cur->y+1;
                            cur=cur->next=temp;
                            }
                if(dire=='7'){
                            point* temp=new point;
                            temp->x=cur->x-1;
                            temp->y=cur->y+1;
                            cur=cur->next=temp;
                            }
                if(dire=='3'){
                            point* temp=new point;
                            temp->x=cur->x+1;
                            temp->y=cur->y-1;
                            cur=cur->next=temp;
                            }
                if(dire=='1'){
                            point* temp=new point;
                            temp->x=cur->x-1;
                            temp->y=cur->y-1;
                            cur=cur->next=temp;
                            }
                if(cur->y>high){high=cur->y;}
                if(cur->y<low){low=cur->y;}
                }
}

void clr(point*h)
{
     point* p=h->next;
     point* q=p->next;
     while(p->next!=h){
                       delete p;
                       p=q;
                       q=q->next;
     }
     delete p;
     delete q;
     return;
}         
int main()
{
     int t;
     cin>>t;
     vector<float>area(t);
     for(int i=0;i<t;i++){
     point *head=new point;
     head->x=0;
     head->y=0;
     int low=0;
     int high=0;
     head=init(head,low,high);
     point*q=head;
     for(int k=low;k<high;k++){
             point *p=head;
             int lower0=0;
             int upper0=0;
             int lower1=0;
             int upper1=0;
             int counter=0;
             int lower_width=0,upper_width=0;
             do{
                   if(p->y==k&&p->next->y==k+1){
                               lower0=p->x;
                               upper0=p->next->x; 
                               counter++;      
                                 }
                   if(p->next->y==k&&p->y==k+1){
                               lower1=p->next->x;
                               upper1=p->x;
                               counter++;           
                                 }
                   if(!(counter%2)){
                                  lower_width+=max(lower0,lower1);
                                  upper_width+=max(upper0,upper1);
                                  lower0=upper0=0;lower1=upper1=0;
                                  }
                    p=p->next;
                    }while(p!=head);
             area[i]+=(lower_width+upper_width)*1.0/2.0;
            
     } 
      clr(head); 
     }
     for(int i=0;i<t;i++){
             cout<<area[i]<<endl;
     }        
     system("PAUSE");
     return 0;
}
