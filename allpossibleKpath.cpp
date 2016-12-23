#include<bits/stdc++.h>
using namespace std;
void countk(int arr[99][99],int u,int v,int k,int n)
{
 int a[n][n][n];
 for(int e=0;e<=k;e++) //for number of edge 
 {
  for(int i=0;i<n;i++)// from source 
   {
     for(int j=0;j<n;j++)// to destination 
     {
        a[i][j][e]=0;
        if(e==0 && i==j)
        a[i][j][e]=1;
        if(e==1 && arr[i][j])
        a[i][j][e]=1;
        if(e>1){
            for(int aa=0;aa<n;aa++)
            {
                if(arr[i][aa])
                {
                    a[i][j][e]+= a[aa][j][e-1];
                }
            }
        }
    }
}
 }
cout<<a[u][v][k]<<endl;
//return a[u][v][k];
}
int main(){
int t;
cin>>t;
while(t--){
        int arr[999][99];
        int n,u,v,k;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
              cin>>arr[i][j];
            }
        }
        cin>>u>>v>>k;

        countk(arr,u,v,k,n);
  //cout<<countk(u,v,k,n)<<endl;
}
return 0;
}
