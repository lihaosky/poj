#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define N 30
void initial(int maze[][N],int temp[][N],int m,int n)
{
int i,j;
printf("input 0 for ways and 1 for blocks!\n");
for(i=0;i<m;i++){
for(j=0;j<n;j++){
if(i==0||i==m-1||j==0||j==n-1){
maze[i][j]=1 ;
temp[i][j]=1;
}
else{
printf("maze[%d][%d]= ",i,j);
scanf("%d",&maze[i][j]);
temp[i][j]=maze[i][j];
}
}
}
}
void output(int maze[][N],int m,int n)
{
int i,j;
for(i=0;i<m;i++){
for(j=0;j<n;j++){
printf("%3d",maze[i][j]);
}
printf("\n");
}
}
int travel(int maze[][N],int m,int n)
{
int i=1,j=1;
maze[i][j]=2;
while(i!=m-2||j!=n-2){
if(maze[i][j+1]==0){
j++;
maze[i][j]=2;
continue;
}
if(maze[i+1][j]==0){
i++;
maze[i][j]=2;
continue;
}
if(maze[i][j-1]==0){
j--;
maze[i][j]=2;
continue;
}
if(maze[i-1][j]==0){
i--;
maze[i][j]=2;
continue;
}
if(maze[i][j-1]==2){
maze[i][j]=1;
j--;
continue;
}
if(maze[i-1][j]==2){
maze[i][j]=1;
i--;
continue;
}
if(maze[i][j+1]==2){
maze[i][j]=1;
j++;
continue;
}
if(maze[i+1][j]==2){
maze[i][j]=1;
i++;
continue;
}
if(maze[0][1]==1&&maze[1][0]==1&&maze[1][2]==1&&maze[2][1]==1){
return 0;
}
}
maze[m-2][n-2]=2;
return 1;
}
void autoinitial(int maze[][N],int temp[][N],int m,int n)
{
int i,j;
do{
for(i=0;i<m;i++){
for(j=0;j<n;j++){
if(i==0||i==m-1||j==0||j==n-1){
maze[i][j]=1 ;
temp[i][j]=1;
}
else{

maze[i][j]=rand()%2;
temp[i][j]=maze[i][j];
maze[1][1]=temp[1][1]=0;
}
}
}
}while(travel(temp,m,n)==0);
}
int main()
{int maze[N][N];
int temp[N][N];
int m,n;
int k;
char ans;
srand(time(NULL));
printf("This is a maze!\n");
printf("Element of an array will be paths and blocks!\n");
printf("Input the length and the width of the maze! ");
scanf("%d%d",&m,&n);
printf("Do you want the maze to be generated?<y/n>\n");
ans=getch();
if(ans=='n'||ans=='N'){
initial(maze,temp,m,n);
}
else{
autoinitial(maze,temp,m,n);
}
printf("The original maze is:\n\n");
output(maze,m,n);
k=travel(maze,m,n);
if(k==0){
printf("your input is a dilemma! No way out!\n");
return 0;
}
printf("\n\nThe way is: (2 stand for the paths)\n\n");
output(maze,m,n);
int a;
scanf("%d",&a);
}
