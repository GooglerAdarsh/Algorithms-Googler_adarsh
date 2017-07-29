#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool visited[100000];
stack<int >st;
void topologicalsort(int s,vector<int> vec[],int n){
    if(!visited[s]){
        visited[s]=true;
        for(int i=0;i<vec[s].size();i++){
            if(!visited[vec[s][i]]){
                topologicalsort(vec[s][i],vec,n);
            }
        }
        st.push(s);
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,e,u,v;
        cin>>n>>e;
        vector<int> vec[10];
        for(int i=0;i<e;i++){
            cin>>u>>v;
            vec[u].push_back(v);
        }
         for(int i=1;i<=n;i++)
        topologicalsort(i,vec,n);
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    }
 return 0;
}
