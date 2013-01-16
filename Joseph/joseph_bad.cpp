//k bad guys and k good guys. alway kill bad guys first. find m
//not effecient program
//AUTOR: LIHAO
//DATE: Jan 22th 2009


#include <iostream>
using namespace std;

bool is_ok(int k,int m)
// judge if the number m is valid
{
      bool x[29];    // store the status of the person: true for killed
      int num=2*k;
      int go=m;
      for(int i=1;i<=2*k;i++){
            x[i]=false;
      }
      short pos=1;                      //get the current position of the circle
      for(int i=1;i<=k;i++){        //perform killing k times
            int j=0;
            if(go!=num){
                  go%=num;
            }
        while(1){                         // loop jump over m person
                  if(x[pos]){
                        pos++;
                        if(pos>2*k){
                              pos=1;
                        }
                  }
                  else{
                        j++;
                        if(j==m){
                              break;
                        }
                        pos++;
                        if(pos>2*k){
                              pos=1;
                        }
                  }
            }
            if(pos<=k){               //if position falls into the first k persons return false;
                  return false;
            }
            x[pos]=true;   //kill the person
            num--;
      }
      return true;
}



int main()
//input the k, 0 to terminate the loop
{
      int k;
      int size=0;
      while(cin>>k&&k){
      unsigned int i;
      for( i=k+1;;i++){
          if(is_ok(k,i)){
                  break;
            }
      }
      cout<<i<<endl;
      }

}










