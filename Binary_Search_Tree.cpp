//Googler_adarsh_IIITA
#include<bits/stdc++.h>
using namespace std;
struct node {
        node *l,*r;
        int data;
}*root=NULL,*p=NULL,*temp=NULL;
int a;
bool flage=false,u=true;
void search(node *p){
      //cout<<p->data<<endl;
        if(p!=NULL){
                if(p->data == a){
                        cout<<"exist"<<endl;
                                flage=true;
                }
                else if(a > p->data)
                        search(p->r);
                else if(a < p->data)
                        search(p->l);
        }
        if(!flage&&u)
                {cout<<"Not exist"<<endl;u=false;}
}
void inprint(node *p){
        if(p!=NULL)
        {
                inprint(p->l);
                cout<< p->data <<" ";
                inprint(p->r);
        }
}
void preprint(node *p){
        if(p!=NULL)
        {
                cout<< p->data <<" ";
                preprint(p->l);
                preprint(p->r);
        }
}
void postprint(node *p){
        if(p!=NULL)
        {
                postprint(p->l);
                postprint(p->r);
                cout<< p->data <<" ";
        }
}




void create(int y){
        while(y--){
                int a;
                cin>>a;
                if(root==NULL){
                        root = new node;
                        root->data=a;
                        root->l=NULL;
                        root->r=NULL;
                }
                else
                {
                  p = root;
                        while(true){
                                if(p->data > a){
                                        if(p->l == NULL)
                                        {
                                                p->l=new node;
                                                p=p->l;
                                                p->data=a;
                                                p->l=NULL;
                                                p->r=NULL;
                                                break;
                                        }
                                        else{
                                                p=p->l;

                                        }
                                }
                                else if(p->data < a){
                                        if(p->r == NULL)
                                        {
                                                p->r=new node;
                                                p=p->r;
                                                p->l=NULL;
                                                p->r=NULL;
                                                p->data=a;
                                                break;
                                        }
                                        else
                                        {
                                                p=p->r;
                                        }

                                }
                        }
                }
        }
        cout<<"preorder"<<endl;
        preprint(root);
        cout<<endl<<"postorder"<<endl;
        postprint(root);
        cout<<endl<<"Iorder"<<endl;
        inprint(root);
        cout<<endl<<"Enter element to be search :"<<endl;
        cin>>a;
        search(root);
}
int main(){
  int y;
  cout<<"Enter no of elements to be insert:"<<endl;
cin>>y;
        create(y);
        return 0;
}
