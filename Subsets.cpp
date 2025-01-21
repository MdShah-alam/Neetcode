#include<bits/stdc++.h>
using namespace std;

//vector<vector<int>>ans;
//void creat(vector<int>&subset,vector<int>nums, int i)
//{
//    if(i==nums.size()){
//        ans.push_back(subset);
//        return ;
//    }
//    subset.push_back(nums[i]);
//    creat(subset,nums,i+1);
//    subset.pop_back();
//}
//vector<vector<int>> subsets(vector<int>& nums)
//{
//    vector<int>v2;
//    creat(v2,nums,0);
//    return ans;
//}
vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>>ans;
    ans.push_back({});
    for(int i=0;i<nums.size();i++){
        int n=ans.size();
        for(int j=0;j<n;j++){
            vector<int>curr=ans[j];
            curr.push_back(nums[i]);
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
    vector<vector<int>>v=subsets(vv);
    for(vector<int>k : v){
        for(int i=0;i<k.size();i++)
            cout<<k[i]<<" ";
        cout<<endl;
    }
}
