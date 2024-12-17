#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>insert(vector<vector<int>>& intervals, vector<int>& v){
    int n=intervals.size(), i=0;
    sort(intervals.begin(),intervals.end());
    sort(v.begin(),v.end());
    vector<vector<int>>result;
    
    while(i<n && intervals[i][1]<v[0]){
        result.push_back(intervals[i]);
        i++;
    }
    while(i<n && intervals[i][0]<=v[1]){
        v[0]=min(intervals[i][0],v[0]);
        v[1]=max(intervals[i][1],v[1]);
        i++;
    }
    result.push_back(v);
    while(i<n){
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>interval;
    for(int i=0;i<n;i++){
        vector<int>v(2);
        cin>>v[0];
        cin>>v[1];
        interval.push_back(v);
    }
    vector<int>v1(2);
    cin>>v1[0];
    cin>>v1[1];
    vector<vector<int>>ans=insert(interval,v1);
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