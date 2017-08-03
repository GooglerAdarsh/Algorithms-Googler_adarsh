#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll Minimum_Jump(ll *arr,ll n){
    ll jump[n+1],from[n+1];
    jump[0]=0;
    from[0]=-1;
       for(int i=1; i < n ; i++)
            jump[i] =INT_MAX;
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<i;j++)
        {
            if(i<=(j+arr[j])&&(jump[i]>jump[j]+1))
            {
                jump[i]=jump[j]+1;
                from[i]=j;
            }
        }
    }
    return jump[n-1];
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
    cout<<Minimum_Jump(arr,n)<<endl;
}
return 0;
}
