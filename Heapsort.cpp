//Googler_adarsh_IIITA
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
void heapfy(ll *arr,ll n,ll i){
	ll l,r,min=i;
	l=i*2+1;
	r=i*2+2;
	if(arr[l]<arr[min]&& l<n)
		min=l;
	if(arr[min]>arr[r] && r<n)
		min=r;
	if(min!=i){
		swap(arr[min],arr[i]);
		heapfy(arr,min,n);
	}
}
void print(ll *arr,ll n){
	for(ll i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void heapsort(ll *arr,ll n){
	for(ll i=n/2-1;i>=0;i--)
		heapfy(arr,n,i);
	for(ll i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapfy(arr,i,0);

	}
	print(arr,n);
}
int main(){
	ll n,arr[99999];
	cout<<"Enter no node"<<endl;
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	heapsort(arr,n);
	return 0;
}
