#include <iostream>
#include <cstring>
using namespace std;

double factorial(double f)
{
      if(f==0){
            return 1.0;
      }
      return f*factorial(f-1);
}

double find_e(double  n)
{
      if(n==0){
            return 1.0;
      }
      else{
            return find_e(n-1)+1/(factorial(n));
      }
}


double find_e_tail(double n,double cur)
{
      if(n==0){
            return cur;
      }
      cur+1/factorial_tail(n,1.0);
      return find_e_tail(n-1,cur);
}
int main(int argc,char** argv)
{
      double cur=1.0,e=0.0;
      if(argc<2){
            cerr<<"Not correct format of input"<<endl;
            exit(1);
      }
      int times=atoi(argv[1]);
      cout.setf(ios::fixed);
      cout.precision(19);
      cout<<times<<endl;
      cout<<find_e(times)<<endl;
      cout<<find_e_tail(times,1.0)<<endl;
      return 0;
}
