#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
ll t;
cin>>t;
while(t--){
    string s1,s2;
    cin>>s1>>s2;
    ll l1,l2,index=0;
    l1=s1.length();
    l2=s2.length();
    map<ll,ll>mp;
    mp[0]=0;
    for(ll i=1;i<l1;){
        if(s1[i]==s1[index])
        {
            mp[i]=index+1;
            i++,index++;
        }
        else{
            if(index!=0){
                index=mp[index-1];
            }
            else{
                mp[i]=0;
                i++;
            }
        }
    }
    ll ii=0,jj=0;
    while(ii<l1 && jj<l2){
        if(s1[ii]==s2[jj]){
            ii++,jj++;
        }
        else{
            if(ii!=0)
            ii=mp[ii-1];
            else
             jj++;
        }
    }
    if(ii==l1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
return 0;
}
