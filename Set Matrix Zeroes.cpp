#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>&v){
    int m = v.size();
    int n = v[0].size();
    bool firstRowZero=false,firstColZero=false;
    for(int i=0;i<m;i++){
        if(v[i][0]==0) firstRowZero=true;
    }
    for(int i=0;i<n;i++){
        if(v[0][i]==0) firstColZero=true;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(v[i][j]==0){
                v[i][0]=0;
                v[0][j]=0;
            }
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(v[i][0]==0 || v[0][j]==0)
                v[i][j]=0;
        }
    }
    if(firstRowZero){
        for(int i=0;i<m;i++)
            v[i][0]=0;
    }
    if(firstColZero){
        for(int j=0;j<n;j++)
            v[0][j]=0;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vv;
    for(int i=0;i<n;i++){
        vector<int>v(m);
        for(int j=0;j<m;j++)
            cin>>v[j];
        vv.push_back(v);
    }
    cout<<endl;
    setZeroes(vv);
    for(int i=0;i<vv.size();i++){
        for(int j=0;j<vv[0].size();j++)
            cout<<vv[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

/**

2
1 3
6 9
2 5

*/