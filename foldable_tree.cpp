#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *new_node(int a){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->left=NULL;
    temp->right=NULL;
    return (temp);
};
void  inorder(struct node *temp){
    if(temp==NULL)
        return ;
    inorder(temp->left);
    cout<<temp->data<<endl;
    inorder(temp->right);
}
 void mirrorIMG(struct node *temp){
     if(temp==NULL)
        return ;
     mirrorIMG(temp->left);
     mirrorIMG(temp->right);
     swap((temp->left),(temp->right));

 }
 bool IsStructureSame(struct node *temp,struct node *temp1){
     if(temp==NULL && temp1==NULL)
        return 1;
     else{
        if(temp!=NULL && temp1!=NULL && IsStructureSame(temp->left,temp1->left)&&IsStructureSame(temp->right,temp1->right))
            return 1;
        else
            return 0;
     }
 }
bool isfoldable(struct node *temp){
    if(temp==NULL)
        return 1;
    mirrorIMG(temp->left);
    bool result=IsStructureSame(temp->left,temp->right);
      mirrorIMG(temp->left);
    return result;
}

int main(){
    struct node *root=NULL;
    while(1){
        int a;
        cin>>a;
        if(!a)
        break;
        else{
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
    }
   // inorder(root);
    if(isfoldable(root))
        cout<<"YES."<<endl;
    else
        cout<<"NO."<<endl;
         //  inorder(root);
    return 0;
}
