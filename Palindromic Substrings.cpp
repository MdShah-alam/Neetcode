#include<bits/stdc++.h>
using namespace std;

int countSubstrings(string s){
   int ans=0;
   int n=s.size();
   for(int i=0;i<n;i++){
       int l=i;
       int r=i;
       while(l>=0 && r<n){
           if(s[l]==s[r]){
               l--;
               r++;
               ans++;
           }
           else
            break;
       }
       l=i;
       r=i+1;
       while(l>=0 && r<n){
           if(s[l]==s[r]){
               l--;
               r++;
               ans++;
           }
           else
            break;
       }
   }
   return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<countSubstrings(s)<<endl;
    return 0;
}