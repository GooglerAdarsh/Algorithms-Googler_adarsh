#include<bits/stdc++.h>
using namespace std;
int _01_knapshack(int *val,int *wt,int n,int W){
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
       for(int j=0;j<=W;j++){
         if(i==0|j==0)
            dp[i][j]=0;
         else if((j-wt[i-1])>=0){
            dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
         }
         else
            dp[i][j]=dp[i-1][j];
       }
    }
    vector<pair<int,int> > vec;
    int j=W;
    for(int i=n;i>0;){
        if(dp[i][j]==dp[i-1][j]){
            vec.push_back( make_pair(wt[n-i-1],val[n-i-1]));
            i-=2;
        }
        else{
            vec.push_back( make_pair(wt[n-i],val[n-i]));
             j=j-wt[n-i];
             i-=1;
        }
       }
       for(int i=0;i<vec.size();i++){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
       }
    return dp[n][W];
}
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int val[n+1],wt[n+1];
    for(int i=0;i<n;i++)
    cin>>val[i];
    for(int i=0;i<n;i++)
    cin>>wt[i];
    int W;
    cin>>W;
    cout<<_01_knapshack(val,wt,n,W)<<endl;
}
return 0;
}
