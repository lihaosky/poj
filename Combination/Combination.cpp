//use recursion to get the combination of i numbers from k numbers
//input k and i, output i combinations of the possible numbers from k
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: Jan 28 2009

#include <iostream>

using namespace std;

void output(char x[],int m)
{
     for(int i=0;i<m;i++){
             cout<<x[i]<<" ";
             }
     cout<<endl;
}

int a[100];
int counter=0;
int s=0;
void c(int k,int i)
{
     if(i==0){
              for(int j=0;j<counter;j++){
                      cout<<a[j]<<" ";
                      }
                      cout<<endl;
                      counter--;
                      s++;
                      return ;
              }
     if(k==0){
              counter=0;
              return ;
              }
     int p=counter;
     a[counter++]=k;
     c(k-1,i-1);
     counter=p;
     c(k-1,i);


}


int main()
{
    int k,i;
    cout << "input total number and number you want to get combination" << endl;
    cin>>k>>i;
    c(k,i);
    cout<<endl<<s<<endl;
    return 0;
}
