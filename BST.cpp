#include<bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node *left;
struct node *right;
};
void search1(struct node* root,int a,int n){
    struct node* temp;
    temp=root;
    int cnt=0;
    while(1){
      if(a==temp->data||(temp->left==NULL||temp->right==NULL)&& cnt==n){
      if(a==temp->data){
      cout<<" found "<<endl;
            break;
            }
            else {
                cout<<" NOT found "<<endl;
                break;
            }
            }
            else{
                if(temp->data > a)
                {
                 temp=temp->left;
                }
                else
                 temp=temp->right;
            }
            cnt++;
    }
}
struct node *new_node(int data)
{
    struct node* node=(struct node *)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return (node);
};
int main(){
struct node *root=NULL;
int n,a;
cin>>n;
int n1=0;
n1=n;
while(n1--){
    cin>>a;
    if(root==NULL)
    {
     root=new_node(a);
    }
    else{
    struct node *node2=new_node(a);
    struct node *temp=NULL;
    temp=root;
    while(1){
        if(temp->data > a)
        {
          if(temp->left==NULL)
          {
             temp->left=node2;
             break;
          }
          else{
            temp=temp->left;
          }
        }
         else if(temp->data < a)
        {
          if(temp->right==NULL)
          {
             temp->right=node2;
             break;
          }
          else{
            temp=temp->right;
          }
        }
    }
   }
}
cout<<"Enter the element to be search"<<endl;
cin>>a;
search1(root,a,n);
return 0;
}
