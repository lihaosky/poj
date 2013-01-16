//demostrate priority queue
//use priority queue to sort array


#include <iostream>
#include <ctime>
using namespace std;

void swap(int &i,int &j)
{
     int k=i;
     i=j;
     j=k;
}


class pqueue
{private:
         int set[10000],size;
         void siftup()
         //move set[size] upwards
         {
              int p;
              for(int i=size;i>1&&set[i]<set[p=i/2];i/=2){
                      swap(set[i],set[p]);
                      }
         }
                      
              
         void siftdown()
         //move set[1] downwards
         {
              int i=1;
              while(1){
                       int c=2*i;
                       if(c>size){
                                   break;
                                   }
                       if(c+1<=size){
                               if(set[c]>set[c+1]){
                                                 c++;
                               }
                       }
                       if(set[i]<=set[c]){
                              break;
                          }
                       swap(set[i],set[c]);
                       i=c;
           }      
    }  
              
public:
       pqueue();
       void insert(int);
       int extractmin();
};



pqueue::pqueue()
//initialization
{
                size=0;
}

void  pqueue::insert(int i)
//insert an element
{
      size++;
     set[size]=i;
     siftup();
}

int pqueue::extractmin()
//get the set[i] the smallest element
{
    int t=set[1];
    set[1]=set[size--];
    siftdown();
    return t;
}
     
     
int main()
{
   cout<<"how many numbers do you have?"<<endl;
   int n;
   cin>>n;
   pqueue a;
   srand(time(NULL));
   cout<<"input the numbers"<<endl;
   clock_t start=clock();
   for(int i=0;i<n;i++){
           int num;
           num=rand()%100;
           a.insert(num);
           }
   clock_t end=clock();
   double t=(end-start)*1.0/CLOCKS_PER_SEC;
   cout<<"the sorted numbers are:"<<endl;
   for(int i=0;i<n;i++){
            cout<<a.extractmin()<<" ";
            }
    cout<<endl;
    cout<<"take time:"<<t<<endl;
    system("PAUSE");
}
