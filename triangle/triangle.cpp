//Complete the following program to compute the largest triangle among a group of points.
//User will enter n (3 ¡Ü n ¡Ü 15) followed by n points each having a position x,y. Assuming all
//points are valid, a number of possible triangles will be formed. Compute and output the
//largest triangle. In the case when there are more than 1 triangle having the same maximum
//area, output the first available triangle
#include<iostream>
using namespace std;
struct Point
{
int x;
int y;
};
double areaT (Point p1, Point p2, Point p3)
// returns the area of a triangle formed by points p1 p2 p3.
{
double area = ((p3.y-p1.y)*(p2.x-p1.x)-(p2.y-p1.y)*(p3.x-p1.x))/ 2.0;
if (area < 0)
area = -area;
return area;
}
int main()
{
Point p[15];
Point p1,p2,p3;
int n;
double area=0;
char dummy;
cin >> n;
for (int i=0; i<n; i++){
cin >> p[i].x >> dummy >> p[i].y;
}
   for(int i=0;i<n-2;i++){
           for(int j=i+1;j<n-1;j++){
                   for(int k=j+1;k<n;k++){
                           if(areaT(p[i],p[j],p[k])>area){
                                                         area=areaT(p[i],p[j],p[k]);
                                                         p1=p[i];p2=p[j];p3=p[k];
                                                         }
                           }
                   }
           }
   cout<<p1.x<<","<<p1.y<<" "<<p2.x<<","<<p2.y<<" "<<p3.x<<","<<p3.y<<" is the largest,"<<endl<<"area: "<<area<<endl;
   system("PAUSE");
}
                                                         
                                                         
