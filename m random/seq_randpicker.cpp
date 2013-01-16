//this program pick a random number from sequential numbers without knowing n beforehand
//we select the first line we select the second line with probability one half, the third line 
//with probability one third, and so on. At the end of the process, each line has the same probability 
//of being chosen(1/n, where n is the total number of lines the file)


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL));
    int x;
    int i=0;
    int choice;
    printf("input numbers with alphabet to end\n");
    while(scanf("%d",&x)){
            i++;
            if(i==1){choice=x;}
            if(rand()%i<1){
                           choice=x;
            }              
    }
    if(!i){printf("no number inputed!\n");}
    else{
    printf("the random number is %d\n",choice);
    }
    fflush(stdin);
    int a;
    scanf("%d",&a);
}
