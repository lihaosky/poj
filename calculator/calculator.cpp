#include<stdio.h>
#include<stdlib.h>

struct number   //数字栈
{int n[100];
int top;
int bottom;
};

struct option  //符号栈
{char o[100];
int top;
int bottom;
};



void pushn(number *a,int num)   //把数字压入栈
{
	a->n[a->top]=num;
	a->top++;
}

void pusho(option *o,char op)  //把符号压入栈
{
	o->o[o->top]=op;
	o->top++;
}

void popn(number *n)         //数字退栈
{
	n->top--;
}

void popo(option *o)    //符号退栈
{
	o->top--;
}

int mani(int a,char b,int c)    //识别符号，处理运算
{
	switch(b){
	case '+' :return (a+c);
	case '-' :return (a-c);
	case '*' :return (a*c);
	case '/' :return (a/c);
	default :return 0;
	}
}

void areth(number *n,option *o)  // 输入与操作
{
	int num,cur;
	char op;
	int flag;
	printf("请输入算式:\n");
	scanf("%d",&num);
	pushn(n,num);
	scanf("%c",&op);
	flag=1;
	while(op!='\n'){
		if(flag==1){
			scanf("%d",&num);
			if(op=='*'||op=='/'){
				cur=mani(n->n[--n->top],op,num);
				pushn(n,cur);
			}
			else{
				pushn(n,num);
				pusho(o,op);
			}
				flag=0;
		}
		else{
			scanf("%c",&op);
			flag=1;
		}
	}
	if(o->top==0){
		printf("结果是%d\n",n->n[--n->top]);
	}
	else{
		while(o->top!=0){
			cur=mani(n->n[--n->top],o->o[--o->top],n->n[--n->top]);
			pushn(n,cur);
		}
		printf("结果是%d\n",n->n[--n->top]);
	}
}



int main()          //主函数
{number *n=NULL;
option *o=NULL;
n=(number*)malloc(sizeof(number));
o=(option*)malloc(sizeof(option));
n->top=0;
n->bottom=0;
o->bottom=0;
o->top=0;
areth(n,o);
int a;
scanf("%d",&a);
return 0;
}

