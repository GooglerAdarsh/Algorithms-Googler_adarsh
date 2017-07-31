//In this we assume that the rod cut is start from i to whole length of rod 
//
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ZerOnenapsack(ll *arr,ll u){
    ll dp[u+1][u+1];
    for(ll i=0;i<=u;i++){
        for(ll j=0;j<=u;j++){
            if(i==0||j==0)
            dp[i][j]=0;
            else{
                 if(i>j)
                     dp[i][j]=dp[i-1][j];
                else if(i<=j)
                dp[i][j]=max(dp[i-1][j],arr[i-1]+dp[i][j-i]);
            }

        }
    }
     for(ll i=0;i<=u;i++){
        for(ll j=0;j<=u;j++)
            cout<<dp[i][j]<<" ";
            cout<<endl;
     }
    return dp[u][u];
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n+1];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        cout<<ZerOnenapsack(arr,n)<<endl;
    }
return 0;
}
