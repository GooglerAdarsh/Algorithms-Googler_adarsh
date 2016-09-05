//Googler_adarsh_IIITA
//work_when_0th_node_exist_else_u_have_to_do_some_changes
#include<bits/stdc++.h>
#define ll long long 
#define pb(a) push_back(a);
using namespace std;
int arr[888][67];
priority_queue<ll> q;
ll n,dst[99999],s;
void dks(ll src){
	q.push(src);
	while(!q.empty()){
		s=q.front();
		q.pop();
		for(ll i=0;i<=n;i++)
		{
			if(arr[s][i])
			{
				if(dst[i]>(dst[s]+arr[s][i]))
				{
					dst[i]=dst[s]+arr[s][i];
                                          q.push(i);
				} 
			}
		}
    }
 for(ll i=0;i<=n;i++)
cout<<" Min_distance_of "<<i<<" th_node_from_src_is_"<<dst[i]<<endl;
}
int main(){
	ll w,e,src,u,v;
	cout<<"Enter no_node_&_edge"<<endl;
	cin>>n>>e;
	for(ll i=0;i<e;i++)
	{
		cin>>u>>v>>w;
		arr[u][v]=w;
		arr[v][u]=w;

	}
	for(ll i=0;i<=n;i++)
		dst[i]=INT_MAX;
	cout<<"Enter source"<<endl;
	cin>>src;
	dst[src]=0;
	dks(src);
	return 0;
}
