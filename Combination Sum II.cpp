#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>res;
void backtrack(vector<int>&sub , vector<int>v,int i, int target)
{
    if(target==0) res.push_back(sub);
    if(target<=0) return ;
    int prev=-1;

    for(int j=i;j<v.size();j++){
        if(v[j]==prev) continue;
        sub.push_back(v[j]);
        backtrack(sub,v,j+1,target-v[j]);
        sub.pop_back();
        prev=v[j];
    }
}
vector<vector<int>>combinationSum2(vector<int>v , int target)
{
    sort(v.begin(),v.end());
    vector<int>a;
    backtrack(a,v,0,target);
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int target;
    cin>>target;
    vector<vector<int>>ans=combinationSum2(v,target);
    for(vector<int>k : ans){
        for(int i=0;i<k.size();i++)
            cout<<k[i]<<" ";
        cout<<endl;
    }
    return 0;
}
