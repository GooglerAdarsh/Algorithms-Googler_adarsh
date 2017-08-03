#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll GetMinimal(ll egg,ll floor){
    ll dp[egg+1][floor+1];
    for(ll e=0;e<=egg;e++)
        dp[e][0]=0;
    for(ll f=0;f<=floor;f++)
    {
        dp[0][f]=0;
        dp[1][f]=f;
    }
    for(ll e=2;e<=egg;e++)
    {
        for(ll f=1;f<=floor;f++)
        {
            dp[e][f]=INT_MAX;
            for(ll k=1;k<=f;k++)
            {
                dp[e][f]=min(dp[e][f],1+max(dp[e-1][k-1],dp[e][f-k]));
            }
        }
    }
    return dp[egg][floor];
}
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll egg,floor;
        cin>>egg>>floor;
        cout<<GetMinimal(egg,floor)<<endl;
    }
return 0;
}
