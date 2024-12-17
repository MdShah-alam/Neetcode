#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>merge(vector<vector<int>>&v){
    int n = v.size();
    vector<vector<int>>ans;
    sort(v.begin(),v.end());
    
    for(int i=0;i<n;i++){
        if(ans.empty()){
            ans.push_back(v[i]);
        }
        int oend=ans.back()[1];
        int ostart=ans.back()[0];
        int end = v[i][1];
        int start = v[i][0];
        if(oend>=start){
            if(oend<end)
                ans.back()[1]=end;
        }
        else{
            ans.push_back({start,end});
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    vector<vector<int>>ans=merge(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}
/**

2
1 3
6 9
2 5

*/