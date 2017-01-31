//ADARSH_TIWARI
//B.Tech (Information Technology ) 3rd year
// Indian Institute Of Information Technology , Allahabad
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
struct node {
int data;
struct node *left;
struct node *right;
};
int cnt=0;
queue<int>st;
map<int,bool>mp;
struct node *temp1=NULL;
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
           cnt++;
        }
}
int  print_hight(struct node *temp){
    if(temp==NULL)
        return 0;
int l=print_hight(temp->left);
int r=print_hight(temp->right);
if(l>r)
    return (l+1);
else
    return (r+1);
}
void printbfs(struct node *temp,int h){
    if(temp==NULL)
    return ;
    if(h==1){
          cout<<temp->data<<" ";
    }
    else{
             printbfs(temp->left,h-1);
             printbfs(temp->right,h-1);
    }
}
void print_BFS(struct node *temp,int h){
    for(int i=1;i<=h;i++)
    {
        printbfs(temp,i);
    }
}
void Left_view(struct node *temp,int h1,int *level){
    //cout<<*level<<"l"<<" "<<h1<<"h"<<" ";
    if(temp==NULL)
        return ;
    if(*level<h1){
       cout<<temp->data<<endl;
          *level=h1;
    }
      Left_view(temp->left,h1+1,level);
      Left_view(temp->right,h1+1,level);
}
void right_view(struct node *temp,int h1,int *level){
    if(temp==NULL)
        return ;
    if(*level<h1){
        cout<<temp->data<<" ";
          *level=h1;
    }
      right_view(temp->right,h1+1,level);
      right_view(temp->left,h1+1,level);
}
void root_to_leaf(struct node *temp,queue<int> st){
    if(temp->left==NULL && temp->right==NULL)
    {
        //cnt++;
         st.push(temp->data);
        while(!st.empty()){
            cout<<st.front()<<" ";
            st.pop();
        }
        cout<<endl;
    }
    else{
             st.push(temp->data);
             if(temp->left!=NULL)
         root_to_leaf(temp->left,st);
                 if(temp->right!=NULL)
         root_to_leaf(temp->right,st);
    }
}
void spiral(struct node *temp,int level,bool it){
    if(temp==NULL)
        return;
    if(level==1)
        cout<<temp->data<<" ";
     else if(level>1){
        if(it){
            spiral(temp->left,level-1,it);
            spiral(temp->right,level-1,it);
        }
        else{
               spiral(temp->right,level-1,it);
               spiral(temp->left,level-1,it);
       }
     }
}
void spiral_trevarsel(struct node *temp){
    bool it=false;
    for(int i=1;i<=print_hight(temp);i++)
    {
        spiral(temp,i,it);
        it=!it;
    }
}
int max1_tree(struct node *temp){
    if(temp==NULL)
        return 0;
    int data1=temp->data;
    int l=max1_tree(temp->left);
    int r=max1_tree(temp->right);
    if(l>data1)
        data1=l;
    if(r>data1)
        data1=r;
    return data1;
}

//NOT FOR Binary Search Tree (because in BST the node->right->data
//will always greater than than the root->data so never (node->data!=(node->left->data + node->right->data))
//Only for Binary tree
/*int Children_sum(struct node *temp){
    int l,r;
    if(temp==NULL ||temp->left==NULL && temp->right==NULL)
        return 1;
    else{
     if(temp->left)
      l=temp->left->data;
     if(temp->right)
      r=temp->right->data;
      if((temp->data)==(l+r)&&Children_sum(temp->left)&&Children_sum(temp->right))
        return 1;
      else
        return 0;
     }
}*/
int main(){
    queue<int> st;
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
    cout<<endl<<"DFS traversal"<<endl;
    print_DFS(root);
    cout<<endl<<"printing Leaf node"<<endl;
    print_leaf(root);
    cout<<endl<<"Number Leaf node"<<endl;
    cout<<cnt<<endl;
    cout<<endl<<"printing Hight of tree"<<endl;
    cout<<print_hight(root)<<endl;
    cout<<endl<<"BFS traversal"<<endl;
    print_BFS(root,print_hight(root));
    cout<<endl<<"Left view"<<endl;
    int m=0;
    Left_view(root,1,&m);
    cout<<endl<<"right view"<<endl;
    m=0;
    right_view(root,1,&m);
    cout<<endl<<"root-to-leaf"<<endl;
    root_to_leaf(root,st);
     cout<<endl<<"Spiral_view"<<endl;
     spiral_trevarsel(root);
     cout<<endl<<"Maximum_in_tree"<<endl;
     cout<<max1_tree(root)<<endl;
  /*   cout<<endl<<"Children_sum"<<endl;
      if(Children_sum(root))
            cout<<"true"<<endl;
      else
        cout<<"false"<<endl; */
return 0;
}
