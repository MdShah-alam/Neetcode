#include<bits/stdc++.h>
using namespace std;

void result(vector<vector<int>>&ans,vector<int>&v,vector<int>&k)
{
    if(v.size()==k.size()){
        ans.push_back(v);
        return ;
    }
    for(int i=0;i<k.size();i++){
        if (find(v.begin(), v.end(), k[i]) != v.end())
            continue;
        v.push_back(k[i]);
        result(ans,v,k);
        v.pop_back();
    }
}
vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>>ans;
    vector<int>v;
    result(ans,v,nums);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<vector<int>>vv=permute(v);
    for(vector<int>k:vv){
        for(int x:k)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
