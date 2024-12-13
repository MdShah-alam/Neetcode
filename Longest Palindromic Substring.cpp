#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s){
    int n = s.size();
    if(n==0 || n==1)
        return s;
    int max_len=0,l,r ,st=0;
    for(int i=0;i<n-1;i++){
        l=i-1;
        r=i+1;
        while(l>=0 && r<n){
            if(s[l]==s[r]){
                l--;
                r++;
            }
            else
                break;
        }
        int len = r-l-1;
        if(max_len<len){
            max_len=len;
            st=l+1;
        }
    }
    for(int i=0;i<n-1;i++){
        l=i;
        r=i+1;
        while(l>=0 && r<n){
            if(s[l]==s[r]){
                l--;
                r++;
            }
            else
                break;
        }
        int len=r-l-1;
        if(max_len<len){
            max_len=len;
            st=l+1;
        }
    }
    return s.substr(st,max_len);
}

int main(){
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}