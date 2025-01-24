#include<bits/stdc++.h>
using namespace std;

bool ans(int i, int j, int k, string s1 ,string s2, string s3, vector<vector<int>>&dp)
{
    if(k==s3.size()) return i==s1.size() && j==s2.size();
    if(dp[i][j]!=-1) dp[i][j];
    bool result=false;
    if(i<s1.size() && s1[i]==s3[k])
        result=result || ans(i+1,j,k+1,s1,s2,s3,dp);
    if(j<s2.size() && s2[j]==s3[k])
        result=result || ans(i,j+1,k+1,s1,s2,s3,dp);
    return dp[i][j]=result;
}
bool isInterleave(string s1, string s2, string s3)
{
    int n=s1.size(), m=s2.size(), t=s3.size();
    if(t!=(n+m)) return false;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return ans(0,0,0,s1,s2,s3,dp);
}

int main()
{
    string s,t , ss;
    cin>>s>>t>>ss;
    cout<<isInterleave(s,t,ss)<<endl;
    return 0;
}
