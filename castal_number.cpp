#include<bits/stdc++.h>
using namespace std;
int fact(int n){
	if(n==1)
	return n;
	else
	{
		return (n*fact(n-1));
	}
}
int castal_number(int n){
	int m=fact(n);
	int u=fact(2*n);
	int l=fact((n+1));
	l=(int)(u/l);
	return((int)(l/m));
}
int main(){
	int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	cout<<castal_number(n)<<endl;
    }
	return 0;
}
