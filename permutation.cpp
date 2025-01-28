#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;
bool visit[1000];
void backtrack(vector<int>v, vector<int>k)
{
    if(k.size()==v.size()){
        ans.push_back(k);
        return ;
    }
    for(int i=0;i<v.size();i++){
        if(visit[i]==true){
            continue;
        }
        k.push_back(v[i]);
        visit[i]=true;
        backtrack(v,k);
        k.pop_back();
        visit[i]=false;
    }
}
vector<vector<int>>permutation(vector<int>v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
        visit[i]=false;
    vector<int>k;
    backtrack(v,k);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<vector<int>>vv=permutation(v);
    for(vector<int>k:vv){
        for(int a:k)
            cout<<a<<" ";
        cout<<endl;
    }
    return 0;
}
