// main idea is sum all the elements and if sum==odd print not possible else take sum/2 as a bag
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool SubSetSum(ll *arr,ll sum,ll n){
    bool dp[n+1][sum+1];
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=sum;j++){
            if(j==0)
            dp[i][j]=true;
            else if(i==0){
                if(arr[i]==j)
                dp[i][j]=true;
                else
                dp[i][j]=false;
            }
            else if(arr[i]>j)
            dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j]|dp[i-1][j-arr[i]];
        }
    }
    return dp[n][sum];
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n+1];
        ll sum=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum&1)
        cout<<"NO"<<endl;
        else{
            if(SubSetSum(arr,sum/2,n))
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
