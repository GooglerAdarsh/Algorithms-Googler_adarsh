#include<bits/stdc++.h>
using namespace std;
 int GetNumberOfWays(int n,int m){
     int arr[n][m];
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||j==0)
                arr[i][j]=1;
            else
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
     }
     return arr[n-1][m-1];
 }
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<GetNumberOfWays(n,m)<<endl;
    }
return 0;
}
