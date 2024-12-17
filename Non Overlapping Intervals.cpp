#include<bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>&v){
    int n=v.size();
    sort(v.begin(),v.end());
    vector<vector<int>>result;
    for(int i=0;i<n;i++){
        if(i==0){
            result.push_back(v[0]);
        }
        else{
            int oend=result.back()[1];
            int start=v[i][0];
            int end=v[i][1];
            if(oend>start) continue;
            else
                result.push_back(v[i]);
        }
    }
    return n-result.size();
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
    cout<<eraseOverlapIntervals(v)<<endl;
    return 0;
}
/**

2
1 3
6 9
2 5

*/