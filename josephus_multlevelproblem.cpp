#include<bits/stdc++.h>
#define ll long long
using namespace std;
int josephus_prob(ll n,ll k){
if(n==1)
    return 1;
else
    return (josephus_prob(n-1,k)+(k-1))%n+1;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    cout<<josephus_prob(n,k)<<endl;
 return 0;
}
