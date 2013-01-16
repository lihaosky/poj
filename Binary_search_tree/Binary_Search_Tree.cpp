//demostrate usage of binary tree
//especially mind the recursively insertion
//AUTHOR:LIHAO
//VENUE:DORMITORY
//DATE: Jan 13 2009


#include <iostream>
using namespace std;

class IntSetBST
{private:
         int n,*v,vn;
         struct node{
                int val;
                node* left,* right;
                node(int i){val=i;left=right=0;}
                };
         node *root;
         //insert
         node* rinsert(node* p,int t)
         {
               if(!p){
                      p=new node(t);
                      n++;
                      }
               else if(p->val>t){
                    p->left=rinsert(p->left,t);
                    }
               else if(p->val<t){
                    p->right=rinsert(p->right,t);
                    }
               return p;
               }
               //search
               int rsearch(node*p,int t)
               {
                   if(p==0){
                            cout<<"not found"<<endl;
                            return -1;
                            }
                   if(p->val==t){
                                 cout<<"found"<<endl;
                                 return t;
                                 }
                   else if(t>p->val){
                            return rsearch(p->right,t);
                   }
                   else{
                           return rsearch(p->left,t);
                        }
               }
               //traverse
               void rtraverse(node *p)
               {
                    if(!p){
                           return;
                           }
                    rtraverse(p->left);
                    cout<<p->val<<" ";
                    rtraverse(p->right);
               }
public:
       IntSetBST(){
                     root=0;n=0;
                     }
       void insert(int t)
       {
            if(!root){
                      root=new node(t);
                      }
            else{
                 rinsert(root,t);
                 }
            }
       
       int search(int t)
       {
           if(!root){
                     cout<<"empty tree!"<<endl;
                     return -1;
                     }
          return rsearch(root,t);
          }
           
       void traverse()
       {
            rtraverse(root);
            }
};

int main()
{
    IntSetBST a;
    cout<<"how many numbers do you want to input?"<<endl;
    int n;
    cin>>n;
    cout<<"input the numbers:"<<endl;
    for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.insert(x);
            }
    cout<<"input the number you want to search:"<<endl;
    int num_sear;
    cin>>num_sear;
    a.search(num_sear);
    cout<<"inorder traverse of the tree is;"<<endl;
    a.traverse();
    cout<<endl;
    system("PAUSE");
    return 0;
}
    
