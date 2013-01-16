//Description
//有两堆石子，数量任意，可以不同。游戏开始由两个人轮流取石子。
//游戏规定，每次有两种不同的取法，一是可以在任意的一堆中取走任意多的石子；
//二是可以在两堆中同时取走相同数量的石子。最后把石子全部取完者为胜者。
//现在给出初始的两堆石子的数目，如果轮到你先取，假设双方都采取最好的策略，问最后你是胜者还是败者。

//Input
//输入包含若干行，表示若干种石子的初始情况，其中每一行包含两个非负整数a和b，
//表示两堆石子的数目，a和b都不大于1,000,000,000。



#include<stdio.h>
#include<math.h>

int main ()
{
    int a, b;
    int k, c;   
    int num=0;
    short int ans[1000]; 
while ( scanf ( "%d%d", &a, &b ) != EOF )
    {
   if (a == 0 && b == 0)
   {
   printf("1 ");
   continue;
    }
        if ( a > b )
        {
            c = a;
            a = b;
            b = c;
        }        
        k = b - a;        
        c = (int)(( double) k )*((  1.0 + sqrt ( 5.0 ) ) / 2.0 ) ;         
if ( c == a )
        {
            ans[num++]=0;
        }
        else
        {
           ans[num++]=1;
        }
    }
    for(int i=0;i<num;i++){
            printf("%d\n",ans[i]);
    }
    int x;
    scanf("%d",&x);
    return 0;
}
