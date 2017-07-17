#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll SeachPivote(ll *arr,ll low,ll high){
    if(low>high)
        return -1;
    else if(low==high)
        return high;
    else{
        ll mid=(low+high)/2;
        if(mid>low && arr[mid]<arr[mid-1])
            return mid-1;
        else if(mid<high && arr[mid]>arr[mid+1])
            return mid;
        else if(arr[mid]<=arr[low])
         return SeachPivote(arr,low,mid-1);
        return SeachPivote(arr,mid+1,high);
    }
}
ll BST(ll *arr,ll low,ll high,ll key){
if(low>high)
    return -1;
 else{
    ll mid=(low+high)/2;
    if(key==arr[mid])
    return mid;
        if(key<arr[mid])
            return BST(arr,low,mid-1,key);
        else if(key>arr[mid])
            return BST(arr,mid+1,high,key);
    }
}
ll  PivoteBS(ll *arr,ll n,ll k){
    ll t=-1;
    t=SeachPivote(arr,0,n);
    if(t==-1)
       return BST(arr,0,n-1,k);
    if(arr[t]==k)
        return t;
    if(arr[0]<=k)
        return BST(arr,0,t-1,k);
    return BST(arr,t+1,n-1,k);
}
int main(){
ll t;
cin>>t;
while(t--){
    ll n,k;
    cin>>n;
    ll arr[n+1];
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    cin>>k;
    cout<<PivoteBS(arr,n,k)+1<<endl;
}
return 0;
}
