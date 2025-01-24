#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp(105,vector<int>(105));
int dfs(int r,int c,int preval,vector<vector<int>>v)
{
    if(r<0 || r>=v.size() || c<0 || c>=v[0].size() || v[r][c]<=preval)
        return 0;
    if(dp[r][c]!=-1) return dp[r][c];
    int res=1;
    res=max(res,1+dfs(r+1,c,v[r][c],v));
    res=max(res,1+dfs(r-1,c,v[r][c],v));
    res=max(res,1+dfs(r,c+1,v[r][c],v));
    res=max(res,1+dfs(r,c-1,v[r][c],v));
    dp[r][c]=res;
    return res;
}
int longestIncreasingPath(vector<vector<int>>&v)
{
    int n=v.size(),m=v[0].size();
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++)
//            dp[i][j]=-1;
//    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            ans=max(ans,dfs(i,j,-1,v));
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }
    cout<<longestIncreasingPath(v)<<endl;
    return 0;
}
