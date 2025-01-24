#include<bits/stdc++.h>
using namespace std;

int f(int ind, int buy, vector<int>v, vector<vector<int>>&dp)
{
    if(ind>=v.size()) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy==1)
        return dp[ind][buy]=max(-v[ind]+f(ind+1,0,v,dp),0+f(ind+1,1,v,dp));
    else
        return dp[ind][buy]=max(v[ind]+f(ind+2,1,v,dp),0+f(ind+1,0,v,dp));
}
int maxProfit(vector<int>&v)
{
    int n=v.size();
    vector<vector<int>>dp;
    for(int i=0;i<=n;i++){
        vector<int>k;
        for(int j=0;j<2;j++)
            k.push_back(-1);
        dp.push_back(k);
    }
    return f(0,1,v,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<maxProfit(v)<<endl;
    return 0;
}
/**

5
4 9 0 4 10

*/
