#include <iostream>
using namespace std;
int main()
{
      __int64 px,py;
      int n;
      char d;
      __int64 area;
      cin>>n;
      for(int i=0;i<n;i++){
            area=px=py=0;
            while(1){
                  d=getchar();
                  if(d=='5'){
                        break;
                  }
                  switch(d){
                        case '8': area+=(px*(py+1)-py*px);
                                      py++;
                                      break;
                        case '2': area+=(px*(py-1)-py*px);
                                    py--;
                                    break;
                        case '6': area+=(px*py-py*(px+1));
                                    px++;
                                    break;
                        case '4': area+=(px*py-py*(px-1));
                                    px--;
                                    break;
                        case '9': area+=(px*(py+1)-py*(px+1));
                                    px++;
                                    py++;
                                    break;
                        case '7': area+=(px*(py+1)-py*(px-1));
                                    px--;
                                    py++;
                                    break;
                        case '3': area+=(px*(py-1)-py*(px+1));
                                    px++;
                                    py--;
                                    break;
                        case '1': area+=(px*(py-1)-py*(px-1));
                                    px--;
                                    py--;
                                    break;
                  }
            }
            if(area<0){
                  area*=-1;
            }
            if(area%2){
                  cout<<area/2<<".5"<<endl;
            }
            else{
                  cout<<area/2<<endl;
            }
      }
            return 0;
}
