#include<bits/stdc++.h>
using namespace std;

int minDistance(string s, string t)
{
    int n=s.size() , m=t.size();
    if(m==0) return n;
    if(s==t) return 0;
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            dp[i][j]=0;

    }
    int k=n;
    for(int i=0;i<=n;i++){
        dp[i][m]=k;
        k--;
    }
    k=m;
    for(int i=0;i<=m;i++){
        dp[n][i]=k;
        k--;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s[i]==t[j])
                dp[i][j]=dp[i+1][j+1];
            else
                dp[i][j]=min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]))+1;
        }
    }
    return dp[0][0];
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<minDistance(s,t)<<endl;
    return 0;
}
