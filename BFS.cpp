//Googler_adarsh_IIITA
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n;
vector <int> arr[1211];
void BFS(int src){
	queue<int> q;
	bool visited[2323];
	ll s;
	q.push(src);
	for(ll i=0;i<=n;i++)
		visited[i]=false;
	visited[src]=true;
	while(!q.empty())
	{
		s=q.front();
		cout<<s<<" ";
		q.pop();
		for(ll i=0;i<arr[s].size();i++)
		{
			if(visited[arr[s][i]]==false){
				q.push(arr[s][i]);
				visited[arr[s][i]]=true;
			}
		}
	}  
}
int main(){
	ll e,u,v,src=0;
	cout<<"Enter node and edge"<<endl;
	cin>>n>>e;
	for(ll i=0;i<e;i++)
	{
		cin>>u>>v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	cout<<"Enter the sorce"<<endl;
	cin>>src;
	BFS(src);
	return 0;
}
