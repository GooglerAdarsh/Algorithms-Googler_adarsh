#include<bits/stdc++.h>
using namespace std;
struct TriNode{
    TriNode *child[26];
    bool    leafcheck;
};
bool DeleteHepler(TriNode *root,string s,int level,int high);
struct TriNode *New_Node(){
    struct TriNode *temp=NULL;
    temp=(TriNode*)malloc(sizeof(TriNode));
    for(int i=0;i<26;i++)
        temp->child[i]=NULL;
    temp->leafcheck=false;
 return temp;
};

void InsertNewNode(TriNode *Root,string s){
    TriNode *temp=Root;
    for(int i=0;i<s.length();i++)
    {
        int a=(int)s[i]-97;
        if(temp->child[a]==NULL)
        temp->child[a]=New_Node();

        temp=temp->child[a];
    }
 temp->leafcheck=true;
}
bool Search_String(TriNode *Root,string s){
    TriNode *temp=Root;
    for(int i=0;i<s.length();i++)
    {
        int a=(int)s[i]-97;
        if(temp->child[a]==NULL)
        return false;
        temp=temp->child[a];
    }
   return (temp&&temp->leafcheck);
}
bool IsItFreeNode(TriNode *root){
    for(int i=0;i<26;i++)
        if(!root->child[i])
        return false;
    return true;
}
bool nodecheck(TriNode *root){
    return(root->leafcheck);
}
bool DeleteHepler(TriNode *root,string s,int level,int high){
   if(root)
    {
        if(level==high){
            if(root->leafcheck){
                root->leafcheck=false;
                if(IsItFreeNode(root)){
                    return true;
                }
                 else
                    return false;
            }
        }
        else {
              int index=(int)s[level]-97;
              if(DeleteHepler(root->child[index],s,level+1,high)){
                    free(root->child[index]);
                    return (!nodecheck(root)&&IsItFreeNode(root));
              }
        }
   }
   return false;
}
void Delete_node(TriNode *root,string s){
    if(s.length())
    {
         DeleteHepler(root,s,0,s.length());
    }
}
int main(){
    int n;
    TriNode *Root=NULL;
    cout<<"Enter the number of string"<<endl;
    cin>>n;
    Root=New_Node();
    while(n--){
        string s;
        cin>>s;
        InsertNewNode(Root,s);
    }
    {
        string s;
     cout<<"Enter the string to delete"<<endl;
        cin>>s;
         Delete_node(Root,s);
    }
    int q;
     cout<<"Enter the number of string to search"<<endl;
     cin>>q;
     while(q--){
       string s;
        cin>>s;
       if(Search_String(Root,s))
        cout<<"Found"<<endl;
       else
        cout<<"Not Found"<<endl;
     }

     return 0;
}
