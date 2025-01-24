#include<bits/stdc++.h>
using namespace std;

int ans(int i, vector<int>&v, int t, int tt)
{
    if(i==v.size()){
        if(tt==t) return 1;
        return 0;
    }
    return ans(i+1,v,t,tt-v[i])+ans(i+1,v,t,tt+v[i]);
}
int findTargetSumWays(vector<int>& nums, int target)
{
    return ans(0,nums,target,0);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int t;
    cin>>t;
    cout<<findTargetSumWays(v,t)<<endl;
    return 0;
}
