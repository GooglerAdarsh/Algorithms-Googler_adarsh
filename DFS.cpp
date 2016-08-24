//Googler_adarsh_IIITA
#include<bits/stdc++.h>
#define ll long long
#define b(a) push_back(a);
using namespace std;
bool visited[99999];
vector<int> arr[99999];
ll n;
void dfs(int src){
	visited[src]=true;
	cout<<src<<" ";
	for(ll i=0;i<arr[src].size();i++)
	{
		if(visited[arr[src][i]]==false)
		{
			dfs(arr[src][i]);
		}
	}

}
int main(){
	ll e,u,v,src;
	cout<<"Enter no_of_node &_edge"<<endl;
	cin>>n>>e;
	for(ll i=0;i<e;i++){
		cin>>v>>u;
		arr[v].b(u);
		arr[u].b(v);
	}
	for(ll i=0;i<=n;i++)
		visited[i]=false;
  cout<<"Enter the source"<<endl;
	cin>>src;
	dfs(src);
	return 0;
}
