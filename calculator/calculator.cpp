#include<stdio.h>
#include<stdlib.h>

struct number   //����ջ
{int n[100];
int top;
int bottom;
};

struct option  //����ջ
{char o[100];
int top;
int bottom;
};



void pushn(number *a,int num)   //������ѹ��ջ
{
	a->n[a->top]=num;
	a->top++;
}

void pusho(option *o,char op)  //�ѷ���ѹ��ջ
{
	o->o[o->top]=op;
	o->top++;
}

void popn(number *n)         //������ջ
{
	n->top--;
}

void popo(option *o)    //������ջ
{
	o->top--;
}

int mani(int a,char b,int c)    //ʶ����ţ���������
{
	switch(b){
	case '+' :return (a+c);
	case '-' :return (a-c);
	case '*' :return (a*c);
	case '/' :return (a/c);
	default :return 0;
	}
}

void areth(number *n,option *o)  // ���������
{
	int num,cur;
	char op;
	int flag;
	printf("��������ʽ:\n");
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
		printf("�����%d\n",n->n[--n->top]);
	}
	else{
		while(o->top!=0){
			cur=mani(n->n[--n->top],o->o[--o->top],n->n[--n->top]);
			pushn(n,cur);
		}
		printf("�����%d\n",n->n[--n->top]);
	}
}



int main()          //������
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

