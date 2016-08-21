#include<iostream>
#include<string>
#include<math.h>
#define ll long long 
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,m;
		string s1,s2;
		cin>>n>>m;
		ll mtr[n+5][m+5];
		cin>>s1>>s2;
		for(ll i=0;i<=n;i++){
			for(ll j=0;j<=m;j++){
				if(i==0||j==0){
					mtr[i][j]=0;
				}
				else if(s1.at(i-1)==s2.at(j-1))
				{
					mtr[i][j]=mtr[i-1][j-1]+1;
				}
				else{
					mtr[i][j]=max(mtr[i][j-1],mtr[i-1][j]);
				}

			}
		}
		cout<<mtr[n][m]<<endl;

	}
	return 0;
}
