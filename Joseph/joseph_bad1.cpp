//a much optimized program
//computing 14 would be fast enough

#include <iostream>
using namespace std;

bool is_ok(int k,int m)
{
      int num=2*k;
      int go;
      int pos=0;
      for(int i=0;i<k;i++){
            go=m+pos;
            if(go%(num)){
                  go%=num;
            }
            else{
                  go=num;
            }
            pos=go;
            if(go<=k){
                  return false;
            }
            else{
                  pos--;
                  num--;
            }
      }
      return true;
}

void main()
{
      int k;
      while(cin>>k&&k){
            int i=k+1;
            while(!is_ok(k,i)){
                  i++;
            }
            cout<<i<<endl;
      }
}
