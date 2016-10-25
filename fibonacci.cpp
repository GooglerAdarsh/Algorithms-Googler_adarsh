#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll fib(ll n){
	ll base[2][2]={{1,0},{0,1}};
	ll ar[2][2]={{1,1},{1,0}};
	ll temp[2][2];
	while(n){
		if(n&1)
		{
			memset(temp,0,sizeof(temp));
			for(ll i=0;i<2;i++) 
				for(ll j=0;j<2;j++) 
					for(ll k=0;k<2;k++)
						temp[i][j]+=ar[i][k]*base[k][j];

			for(ll i=0;i<2;i++){
				for(ll j=0;j<2;j++){
					base[i][j]=temp[i][j];
                               }
  }
		}

		memset(temp,0,sizeof(temp));
		for(ll i=0;i<2;i++)
			for(ll j=0;j<2;j++)
				for(ll k=0;k<2;k++)
					temp[i][j]+=ar[i][k]*ar[k][j];

		for(ll i=0;i<2;i++)
			for(ll j=0;j<2;j++)
				ar[i][j]=temp[i][j];
		n/=2;
	}
	return (base[0][1]);
}
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll  n;
		cin>>n;
		cout<<fib(n)<<endl;
	}
	return 0;
}
