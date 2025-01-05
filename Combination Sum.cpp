#include<bits/stdc++.h>
using namespace std;
/**
vector<vector<int>>anss;
void help(int i, vector<int>&v, int target, vector<int>&sol){
    if(i==v.size()){
        if(target==0){
            anss.push_back(sol);
            return ;
        }
        return ;
    }
    if(v[i]<=target){
        sol.push_back(v[i]);
        help(i,v,target-v[i],sol);
        sol.pop_back();
    }
    help(i+1,v,target,sol);
}*/
void help2(int id,vector<int>&v,int target ,vector<vector<int>>&ans,vector<int>&sol){
    if(target==0){
        ans.push_back(sol);
        return ;
    }
    for(int i=id;i<v.size();i++){
        if(i>id && v[i]==v[i-1]) continue;
        if(v[i] > target) break;
        sol.push_back(v[i]);
        help2(i+1 ,v ,target-v[i] ,ans, sol);
        sol.pop_back();
    }
}
vector<vector<int>>combinationSum(vector<int>&v, int target){
    vector<vector<int>>ans;
    vector<int>sol;
    sort(v.begin(),v.end());
    help2(0,v,target,ans,sol);
    return ans;
}
/*

4 
2 5 6 9
9

7
10 1 2 7 6 1 5
8

*/
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int target;
    cin>>target;
    vector<vector<int>>ans=combinationSum(v,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}