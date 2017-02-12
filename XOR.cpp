#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f(ll a) {
     ll res[] = {a,1,a+1,0};
  //   cout<<res[a%4]<<endl;
     return res[a%4];
}

ll getXor(ll a,ll b) {
    //while()
     return f(b)^f(a-1);
}
int main(){
int a,b,n;
cin>>a>>b;
cout<<getXor(a,b)<<endl;
return 0;
}
