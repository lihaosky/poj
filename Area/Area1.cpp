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


int max(int a,int b)
{
    return a>=b?a-b:b-a;
}
void init(vector<char> &point_x,vector<char> &point_y,int& low,int& high)
{
       char dire;
       char pre_x=0;
       char pre_y=0;
       while(1){
                dire=getchar();
                if(dire=='5'){
                              point_x.push_back(0); point_y.push_back(0);return ;}
                if(dire=='8'){
                              pre_y++;
                              point_x.push_back(pre_x);
                              point_y.push_back(pre_y);
                            }
                if(dire=='2'){
                            pre_y--;
                            point_x.push_back(pre_x);
                            point_y.push_back(pre_y);
                            }
                if(dire=='6'){
                            pre_x++;
                            point_x.push_back(pre_x);
                            point_y.push_back(pre_y);
                            }
                if(dire=='4'){
                            pre_x--;
                            point_x.push_back(pre_x);
                            point_y.push_back(pre_y);
                            }
                if(dire=='9'){
                            pre_x++;
                            pre_y++;
                            point_x.push_back(pre_x);
                            point_y.push_back(pre_y);
                            }
                if(dire=='7'){
                            pre_x--;
                            pre_y++;
                            point_x.push_back(pre_x);
                            point_y.push_back(pre_y);
                            }
                if(dire=='3'){
                            pre_x++;
                            pre_y--;
                            point_x.push_back(pre_x);
                            point_y.push_back(pre_y);
                            }
                if(dire=='1'){
                            pre_x--;
                            pre_y--;
                            point_x.push_back(pre_x);
                            point_y.push_back(pre_y);
                            }
                if(pre_y>high){high=pre_y;}
                if(pre_y<low){low=pre_y;}
                }
}

int main()
{
     int t;
     cin>>t;
     double area;
     for(int i=0;i<t;i++){
     vector<char> point_x;
     vector<char> point_y;
     point_x.push_back(0);
     point_y.push_back(0);
     int low=0;
     int high=0;
     area=0;
     init(point_x,point_y,low,high);
     for(int k=low;k<high;k++){
             int lower0=0;
             int upper0=0;
             int lower1=0;
             int upper1=0;
             int counter=0;
             int lower_width=0,upper_width=0;
             for(int j=0;j<point_x.size()-1;j++){
                   if(point_y[j]==k&&point_y[j+1]==k+1){
                               lower0=point_x[j];
                               upper0=point_x[j+1];
                               counter++;
                                 }
                   if(point_y[j+1]==k&&point_y[j]==k+1){
                               lower1=point_x[j+1];
                               upper1=point_x[j];
                               counter++;
                                 }
                   if(!(counter%2)){
                                  lower_width+=max(lower0,lower1);
                                  upper_width+=max(upper0,upper1);
                                  lower0=upper0=0;lower1=upper1=0;
                                  }
                    }
             area+=(lower_width+upper_width)*1.0/2.0;

     }
     cout<<area<<endl;;
     }
     return 0;
}
