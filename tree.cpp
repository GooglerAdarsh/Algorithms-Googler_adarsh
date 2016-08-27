#include<bits/stdc++.h>
using namespace std;
struct node {
	struct node *l,*r;
	int data;
},root;
void create(){
	int a;
	if(root==NULL)
	{
		cin>>a;
		root->l=NULL;
		root->data=a;
		root->r=NULL;
	}
}
int main(){
	create();
	return 0;
}
