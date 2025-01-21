#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    ans.push_back({});
    for(int i=0;i<nums.size();i++){
        int n=ans.size();
        for(int j=0;j<n;j++){
            vector<int>curr=ans[j];
            curr.push_back(nums[i]);
            if (find(ans.begin(), ans.end(), curr) == ans.end())
                ans.push_back(curr);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>vv(n);
    for(int i=0;i<n;i++)
        cin>>vv[i];
    cout<<"start"<<endl;
    vector<vector<int>>v=subsetsWithDup(vv);
    for(vector<int>k : v){
        for(int i=0;i<k.size();i++)
            cout<<k[i]<<" ";
        cout<<endl;
    }
}

