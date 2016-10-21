#include<bits/stdc++.h>
#define ll long long 
using namespace std;
bool mark[1000000];
vector<ll> vec;
void sieve(ll limit){
	memset(mark,true,(limit+1));
	for(ll i=2;i*i<=limit;i++)
	{
		if(mark[i]){
			for(ll j=2*i;j<=limit;j+=i)
				mark[j]=false;
		}
	}
	for(ll i=2;i<=limit;i++)
	{
		if(mark[i]==true)
			vec.push_back(i);
	}
}
void Segmented_seive(ll n){
	ll limit;
	limit=floor(sqrt(n))+1;
	sieve(limit);
	ll low,lowlimt,high;
	low = limit;
	high = 2*limit;
       if(high>=n)
        high=n;
	while(low<n){
		memset(mark,false,(limit));
		for(ll i=0;i<vec.size();i++)
		{
			lowlimt=floor(low/vec[i])*vec[i];
			while(lowlimt<low)
				lowlimt+=vec[i];
			for(ll j=lowlimt;j<=high;j+=vec[i])
				mark[j-low]=true;
		}
		for(ll i=low;i<=high;i++)
		{ 
                 if(!mark[i-low])
                   vec.push_back(i);
		}
		low+=limit;
		high+=limit;
		if(high>=n)
			high=n;
	}
}
int main(){
	ll n,x=1;
	cin>>n;
       // ll lll=floor(n)+1;
	Segmented_seive(n);
	for(ll i=0;i*i<=n;i++)
        {
         ll  jj=n,y=0;
         while(jj%vec[i]==0)
         {
          y++;
         jj=jj/vec[i];
         }
         x*=(y+1);
        }
cout<<x<<endl;
	return 0;
}
