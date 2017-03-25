#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
int n;
int t=1;
cin>>n;
//All the first get the power of 2 which is less than or equal to the number
//then substract the number by 2's power then using n'th term formula get the answer u want
while(pow(2,t)<=n)
        t++;
cout<<(1+(n-pow(2,(t-1)))*2)<<endl;
    }
return 0;
}
