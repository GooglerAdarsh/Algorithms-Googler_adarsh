#include<bits/stdc++.h>
using namespace std;
void permute(string s,int l,int n){
    if(l==n)
        cout<<s<<endl;
    else{
          for(int i=l;i<=n;i++)
          {
             swap(s[l],s[i]);
             permute(s,l+1,n);
             swap(s[l],s[i]);
          }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>s;
        n=s.length();
        int l=0;
         permute(s,l,n-1);
    }
    return 0;
}
