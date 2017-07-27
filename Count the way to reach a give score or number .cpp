#include<bits/stdc++.h>
using namespace std;
int sum(int *arr,int n,int m){
    int dp[m+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=arr[i];j<=m;j++){
            dp[j]+=dp[j-arr[i]];
        }
    }
     //for(int j=0;j<=m;j++)
       // cout<<dp[j]<<" ";
    return dp[m];
}
int main(){
int n,m;
cout<<"enter the score upto which u want to reach "<<endl;
cin>>m;
cout<<"enter the number element"<<endl;
cin>>n;
int arr[n+1];
for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<sum(arr,n,m)<<endl;
return 0;
}
