//Complexity 2^(n-2)
#include<bits/stdc++.h>
using namespace std;
bool DictionarySearch(string word){
   string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"};
    int n=sizeof(dictionary)/sizeof(dictionary[0]);
    for(int i=0;i<n;i++)
    if(!dictionary[i].compare(word))
        return true;
        return false;
}
void WordbreakHandler(string s,int n,string result){
    for(int i=1;i<=n;i++){
        string brk=s.substr(0,i);
        if(DictionarySearch(brk)){
            if(i==n){
            result+=brk;
            cout<<result<<endl;
             return ;
            }
          WordbreakHandler(s.substr(i,n-i),n-i,result+brk+" ");
        }
    }
}
void WordBreak(string s){
    WordbreakHandler(s,s.length(),"");
}
int main(){
    string s;
    cin>>s;
    WordBreak(s);
    return 0;
}
