#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
    int n=cost.size();
    int dp[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=0;
    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i-1]+cost[i-1] , dp[i-2]+cost[i-2]);
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<minCostClimbingStairs(v)<<endl;
}
