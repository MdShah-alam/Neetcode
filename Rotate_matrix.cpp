#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>&vv){
    vector<vector<int>>result;
    int n=vv.size();
    for(int i=0;i<n;i++){
        vector<int>v;
        for(int j=0;j<n;j++){
            v.push_back(vv[j][i]);
        }
        reverse(v.begin(),v.end());
        result.push_back(v);
    }
    vv = result;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>vv;
    for(int i=0;i<n;i++){
        vector<int>v(n);
        for(int j=0;j<n;j++)
            cin>>v[j];
        vv.push_back(v);
    }
    cout<<endl;
    rotate(vv);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<vv[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/**

2
1 3
6 9
2 5

*/