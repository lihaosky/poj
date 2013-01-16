////////////////////////////////////////////////////////
////////lihao April/13/2008 all rights reserved/////////
/////binary tree and its correlative function///////////
////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct tree         //define a structure
{int node;
tree *lchild;
tree *rchild;
}BinaryTree;

BinaryTree *initial()              //initialize a tree or make a tree 
{
	BinaryTree *p,*q,*pre,*root=NULL;
	int n;
	printf("Input the number! Press quit to end inputing\n");
	while(scanf("%d",&n)==1){
		q=root;
		p=(BinaryTree*)malloc(sizeof(BinaryTree));
		p->lchild=p->rchild=NULL;
		p->node=n;
		if(root==NULL){
			root=p;
		}
		else{
			while(q){
				if(q->node>p->node){
					pre=q;
					q=q->lchild;
				}
				else if(q->node<p->node){
					pre=q;
					q=q->rchild;
				}
				else{
					pre=q;
					break;
				}
			}
			if(pre->node>p->node){
				pre->lchild=p;
			}
			else if(pre->node<p->node){
				pre->rchild=p;
			}
			
		}
	}
	return root;
}

BinaryTree *insert(BinaryTree *root)   //insert a number which hasn't appeared before
{
	BinaryTree *p,*q,*r;
	int n;
	printf("Input the number you want to insert!\n\n");
	fflush(stdin);
	scanf("%d",&n);
	if(root==NULL){
                   root=(BinaryTree*)malloc(sizeof(BinaryTree));
                   root->node=n;
                   root->lchild=root->rchild=NULL;
                   }
    else{
	p=root;
	r=(BinaryTree*)malloc(sizeof(BinaryTree));
	r->lchild=r->rchild=NULL;
	r->node=n;
	while(p){
		if(p->node<n){
			q=p;
			p=p->rchild;
		}
		else if(p->node>n){
			q=p;
			p=p->lchild;
		}
		else{
			q=p;
			break;
		}
	}
	if(q->node>n){
		q->lchild=r;
		printf("The number has been inserted!\n");
	}
	else if(q->node<n){
		q->rchild=r;
		printf("The number has been inserted!\n");
	}
	else{
		printf("\n%d has appeared already!\n",n);
	}
    }
	return root;
}


void inOrder(BinaryTree* root)       //output the tree by inOrder
{
	if(root!=NULL){
	inOrder(root->lchild);
	printf("%d\t",root->node);
	inOrder(root->rchild);
	}
}

int main()
{BinaryTree *root=NULL;
char *menu[]={"1.make a tree;","2.insert a number;","3.travel the tree;"};
int i;
char ans;          
while(1){
	printf("\nPress the corresponding number to choose! Press ESC to quit!\n\n");
	for(i=0;i<3;i++){
		printf("%s\n",menu[i]);
	}                      //a menu
printf("\n\n");
ans=getch();               //choose the service you want
if(ans=='1'){
	root=initial();          //make a tree
}
else if(ans=='2'){             //insert a number
	root=insert(root);
}
else if(ans=='3'){      
    if(root==NULL){printf("The tree is empty!\n\n");}
    else{         //output the tree
	printf("The order is:\n\n"); 
	inOrder(root);
	printf("\n\n");
}
}
else{
	break;                     //quit the manipulate
}
}
}







