#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *new_node(int a){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a;
     temp->left=NULL;
         temp->right=NULL;
    return temp;
};
int hight(struct node *temp)
{
    int lh=0,rh=0;
    if(temp==NULL)
        return 0;
        else
        {
            lh=hight(temp->left);
            rh=hight(temp->right);
            if(lh>rh)
                return (lh+1);
            else
                return (rh+1);
        }
}
bool  isbalanced(struct node *temp){
      int lh=0,rh=0;
      if(temp==NULL)
        return 1;
     lh=hight(temp->left);
     rh=hight(temp->right);
     if(abs(lh-rh)<=1 && isbalanced(temp->left) && isbalanced(temp->right))
        return 1;
     else
        return 0;
}
int main(){
    struct node *root=NULL;
    while(1)
    {
        int a;
        cin>>a;
        if(a==0)
        break;
        if(root==NULL)
        root=new_node(a);
        else{
            struct node *temp=root;
            while(1){
                if(temp->data > a)
                {
                    if(temp->left==NULL){
                        temp->left=new_node(a);
                        break;
                    }
                    else
                        temp=temp->left;
                }
                else if(temp->data < a)
                {
                    if(temp->right==NULL){
                        temp->right=new_node(a);
                        break;
                    }
                    else
                        temp=temp->right;
                }
            }
        }
    }
    if(isbalanced(root))
        cout<<"Balanced"<<endl;
     else
     {
         cout<<"Not Balanced"<<endl;
     }
    return 0;
}
