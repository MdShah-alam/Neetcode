#include<bits/stdc++.h>
using namespace std;

int dp[305];
int n;
unordered_set<string>st;
bool solve(int idx ,string s){
    if(idx>=n)
        return true;
    if(dp[idx]!=-1) return dp[idx];
    if(st.find(s)!=st.end()) return dp[idx]=true;
    for(int i=1;i<=n;i++){
        string temp=s.substr(idx,i);
        if(st.find(temp)!=st.end() && solve(idx+i,s))
            return dp[idx]=true;
    }
    return dp[idx]=false;
}
bool wordBreak(string s, vector<string>&v){
    int n=s.size();
    for(string k : v){
        st.insert(k);
    }
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    return solve(0,s);
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    vector<string>v(k);
    for(int i=0;i<k;i++){
        cin>>v[i];
    }
    cout<<wordBreak(s,v)<<endl;
    return 0;
}