#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll arr[99666],n;
ll BST(ll a,ll low ,ll high){
	ll mid;
	mid=(low + high)/2
	if(low<=high){
	if(a<arr[0])
		return -1;
	else if(a>arr[n-1])
		return -1;
	else if(a==arr[mid])
		return mid;
	else if(a>arr[mid])
		BST(a,mid+1,high);
	else if(a<arr[mid])
		BST(a,low,mid-1);
}
}
int main(){
	ll a,j;
	cout<<"Enter no of Elements :"<<endl;
	cin>>n;
	cout<<"Enter elements:"<<endl;
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	for(ll i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	cout<<"Enter the element to be search :"<<endl;
	cin>>a;
	j=BST(a,0,n);
	if(j>=0)
		cout<<"exist"<<endl;
	else
		cout<<"Not exist"<<endl;
	return 0;
}
