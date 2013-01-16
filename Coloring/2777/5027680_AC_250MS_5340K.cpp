#include <iostream>
using namespace std;
struct Seg
{
    int left,right,color;
    Seg* lchild,*rchild;
}seg[400000];

Seg* build(Seg* h,int l,int r,int step)
{
    if(l==r){
        h=&seg[step];
        h->left=h->right=l;
        h->color=1;
        h->lchild=h->rchild=NULL;
        return h;
    }
    h=&seg[step];
    h->left=l;
    h->right=r;
    h->color=1;
    h->lchild=build(h,l,(l+r)/2,step*2);
    h->rchild=build(h,(l+r)/2+1,r,(step*2)+1);
    return h;
}

int single(int x)
{
    return (x&(x-1))==0;
}

void insert(Seg* h,int l,int r,int color)
{
    if(h->color==color){
        return;
    }
    if(h->left==l&&h->right==r){
        h->color=color;
        return;
    }
    if(single(h->color)){
        h->lchild->color=h->color;
        h->rchild->color=h->color;
    }
    int mid=(h->left+h->right)>>1;
    if(l>mid){
        insert(h->rchild,l,r,color);
    }
    else if(r<mid+1){
        insert(h->lchild,l,r,color);
    }
    else{
        insert(h->lchild,l,mid,color);
        insert(h->rchild,mid+1,r,color);
    }
    h->color=(h->lchild->color|h->rchild->color);
}

int compute(Seg*h,int l,int r)
{
    if(single(h->color)&&h->left<=l&&h->right>=r){
        return h->color;
    }
    int mid=(h->left+h->right)>>1;
    if(h->left==l&&h->right==r){
        return h->color;
    }
    if(l>mid){
         return compute(h->rchild,l,r);
    }
    else if(r<mid+1){
        return compute(h->lchild,l,r);
    }
    else{
        return compute(h->lchild,l,mid)|compute(h->rchild,mid+1,r);
    }
}
int main()
{
    int range,l,r,color,op_num,ans,cnt;
    char op[2];
    Seg* h;
    scanf("%d%d%d",&range,&color,&op_num);
    h=build(h,1,range,1);
    while(op_num--){
        scanf("%s",op);
        if(op[0]=='C'){
            scanf("%d%d%d",&l,&r,&color);
            color=(1<<(color-1));
            if(l<r){
                insert(h,l,r,color);
            }
            else{
                insert(h,r,l,color);
            }
        }
        else{
            cnt=0;
            scanf("%d%d",&l,&r);
            if(l<r){
                ans=compute(h,l,r);
            }
            else{
                ans=compute(h,r,l);
            }
            while(ans){
                if(ans&1){
                    cnt++;
                }
                ans=ans>>1;
            }
            printf("%d\n",cnt);
        }
    }
}
