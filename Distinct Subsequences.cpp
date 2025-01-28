#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
int ans(string s,string t,int n, int m, int i, int j)
{
    if(j==m) return 1;
    if(i==n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j])
        return dp[i][j] = ans(s,t,n,m,i+1,j+1)+ans(s,t,n,m,i+1,j);
    else
        return dp[i][j] = ans(s,t,n,m,i+1,j);
}
int numDistinct(string s, string t)
{
    int n=s.size(), m=t.size();
    dp.resize(n + 1, vector<int>(m + 1, -1));

    int i=0, j=0;
    return ans(s,t,n,m,i,j);
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<numDistinct(s,t)<<endl;
    return 0;
}
