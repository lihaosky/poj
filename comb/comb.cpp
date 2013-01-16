//【问题】 组合问题 
//问题描述：找出从自然数1、2、……、n中任取r个数的所有组合。
//例如n=5，r=3的所有组合为： （1）5、4、3 （2）5、4、2 （3）5、4、1 
//(4）5、3、2 （5）5、3、1 （6）5、2、1 
//(7）4、3、2 （8）4、3、1 （9）4、2、1 
//(10）3、2、1 


# include <stdio.h> 
# define MAXN 100 

int a[MAXN]; 
void comb(int m,int k) 
{ int i,j; 
for (i=m;i>=k;i--) 
{ a[k]=i; 
if (k>1) 
comb(i-1,k-1); 
else 
{ for (j=a[0];j>0;j--) 
printf(" %4d",a[j]); 
printf(" \n"); 
} 
} 
} 
int main() 
{ a[0]=4; 
comb(6,4);
int b;
scanf("%d",&b); 
} 
