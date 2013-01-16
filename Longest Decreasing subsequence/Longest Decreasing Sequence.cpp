//find the longest decreasing subsequence in the array of numbers
//using dynamic programming: storing each number's longest sequence in tempmax[]
//AUTHOR:LIHAO
//DATE: Feb 1 2009
//VENUE: DORMITORY

#include <iostream>
using namespace std;

bool is_finish(bool mark[],int n)
{//check if all the numbers in the array have been used
      //return true if yes
      for(int i=0;i<n;i++){
            if(!mark[i]){
                  return false;
            }
      }
      return true;
}

void main()
{
      int a[20]; //store numbers
      int tempmax[20]; //store everynumebr's longest sequence number
      int max=0,tmax;
      bool mark[20];   //store if the number has been used
      int gun_num=0; //store how many sequence there are

      //initialize status of numbers
      for(int i=0;i<20;i++){
            mark[i]=false;
      }
      int n;
      cout<<"how many numbers?"<<endl;
      cin>>n;
      cout<<"input the numbers:"<<endl;
      for(int i=0;i<n;i++){
            cin>>a[i];
            }


      while(!is_finish(mark,n)){
            gun_num++;
            for(int i=0;i<n;i++){
                  if(mark[i]){
                        continue;
                  }
                  tempmax[i]=1; //initialize the longest sequence number
                  tmax=0;
                  for(int j=i-1;j>=0;j--){
                        if(mark[j]){
                              continue;
                        }
                        if(a[j]>a[i]&&tempmax[j]>tmax){   //if numbers before this one is bigger and have longer sequence this number should be appended in that sequence
                              tmax=tempmax[j];
                        }
                  }
                  tempmax[i]+=tmax;
                  if(tempmax[i]>max){
                        max=tempmax[i];
                  }
            }
            cout<<max<<endl;

            //find the sequence
            int pivot=max;
            int p=0;
            for(int i=n-1;i>=0;i--){
                  if(mark[i]){
                        continue;
                  }
               if(tempmax[i]==pivot&&a[i]>p){
                  mark[i]=true;
                  pivot--;
                  p=a[i];
                  cout<<a[i]<<" ";
            }
      }
      max=0;
              cout<<endl;
      }
}
