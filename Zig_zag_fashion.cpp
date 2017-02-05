#include<bits/stdc++.h>
using namespace std;
void zig_zag(int *arr,int n){
    bool flage=false;
      for(int i=0;i<n-1;i++){
        if(flage)
        {
            if(arr[i]>arr[i+1])
                swap(arr[i],arr[i+1]);
        }
        else
        {
            if(arr[i]<arr[i+1])
                swap(arr[i],arr[i+1]);
        }
        flage=!flage;
      }
}
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        zig_zag(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
cout<<endl;
}
return 0;
}
