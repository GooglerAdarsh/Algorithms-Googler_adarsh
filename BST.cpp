#include<bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node *left;
struct node *right;
};
queue<int>st;
struct node *new_node(int da){
    struct node *node1;
    node1=(struct node *)malloc(sizeof(struct node));
    node1->data=da;
    node1->left=NULL;
    node1->right=NULL;
return (node1);
};
void print_INORDER(struct node *temp){
    if(temp==NULL)
        return ;
     print_INORDER(temp->left);
     cout<< temp->data <<" ";
     print_INORDER(temp->right);
}
void print_PREORDER(struct node *temp){
     if(temp==NULL)
        return ;
     cout<<temp->data<<" ";
     print_PREORDER(temp->left);
     print_PREORDER(temp->right);

}
void print_POSTORDER(struct node *temp){
     if(temp==NULL)
        return ;
     print_POSTORDER(temp->left);
     print_POSTORDER(temp->right);
     cout<<temp->data<<" ";
}
int sizeoftree(struct node *temp){
    if(temp==NULL)
        return 0;
    else
      return  (sizeoftree(temp->left)+1+sizeoftree(temp->right));
}
void print_DFS(struct node *temp){
    if(temp==NULL)
        return ;
        if(temp->left==NULL&&temp->right==NULL)
        st.push(temp->data);
    cout<<temp->data<<" ";
    print_DFS(temp->left);
    print_DFS(temp->right);
}
void print_leaf(struct node *temp){
    while(!st.empty()){
           cout<<st.front()<<endl;
           st.pop();
        }
}
int main(){
struct node *root=NULL;
    while(1)
    {
        int a;
        cout<<"If want to terminate the insertion enter :- 0"<<endl;
        cin>>a;
        if(a==0)
            break;
        if(root==NULL)
        {
            root=new_node(a);
        }
        else
        {
           struct node *temp=root;
               while(1)
               {
                    if(temp->data > a){

                        if(temp->left==NULL){
                        temp->left=new_node(a);
                        break;
                        }
                        else
                             temp=temp->left;
                        }
                        else if(temp->data < a){
                        if(temp->right==NULL){
                        temp->right =new_node(a);
                        break;
                        }
                        else
                            temp=temp->right;
                        }
                }
        }
    }
    cout<<"INORDER TRAVERSAL"<<endl;
    print_INORDER(root);
    cout<<endl<<"PREORDER TRAVERSAL "<<endl;
    print_PREORDER(root);
     cout<<endl<<"POSTORDER TRAVERSAL "<<endl;
    print_POSTORDER(root);
     cout<<endl<<"Size of tree"<<endl;
    cout<<(sizeoftree(root->left)+1+sizeoftree(root->right))<<endl;
      cout<<endl<<"DFS trevesal"<<endl;
      print_DFS(root);
      cout<<endl<<"printing Leaf node"<<endl;
        print_leaf(root);
return 0;
}
