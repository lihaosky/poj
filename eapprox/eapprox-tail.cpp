#include <iostream>
#include <cstring>
using namespace std;

double factorial_tail(double f,double cur)
{
      if(f==0){
            return cur;
      }
      else{
            return factorial_tail(f-1,f*cur);
      }
}

double find_e_tail(double n,double cur)
{
      if(n==0){
            return cur;
      }
      cur+=1/factorial_tail(n,1.0);
      return find_e_tail(n-1,cur);
}

int main(int argc,char** argv)
{
      if(argc<2){
            cerr<<"Not correct format of input"<<endl;
            exit(1);
      }
      double times=atoi(argv[1]);
      cout.setf(ios::fixed);
      cout.precision(19);
      cout<<find_e_tail(times,1.0)<<endl;
      return 0;
}
