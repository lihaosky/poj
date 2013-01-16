//using vector product to compute the area of polygon
//AUTHOR: LIHAO
//DATE: MAR 5TH 2009
//VENUE: DORMITORY

#include <iostream>
using namespace std;

int main()
{
      __int64 x,y,px,py;
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
                        case '8': y=py+1;
                                    x=px;
                                    break;
                        case '2': y=py-1;
                                    x=px;
                                    break;
                        case '6': x=px+1;
                                    y=py;
                                    break;
                        case '4': x=px-1;
                                    y=py;
                                    break;
                        case '9': x=px+1;
                                    y=py+1;
                                    break;
                        case '7': x=px-1;
                                    y=py+1;
                                    break;
                        case '3': x=px+1;
                                    y=py-1;
                                    break;
                        case '1': x=px-1;
                                    y=py-1;
                                    break;
                  }
                  area+=(px*y-py*x);
                  px=x;
                  py=y;
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
