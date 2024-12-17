#include<bits/stdc++.h>
using namespace std;

vector<int>spiralOrder(vector<vector<int>>& matrix){
    vector<int>v;
    if(matrix.empty()) return v;
    int m = matrix.size();
    int n = matrix[0].size();
    int top=0,bottom=m-1,left=0,right=n-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++)
            v.push_back(matrix[top][i]);
        top++;
        
        for(int i=top;i<=bottom;i++)
            v.push_back(matrix[i][right]);
        right--;
        
        if(top<=bottom){
            for(int i=right;i>=left;i--)
                v.push_back(matrix[bottom][i]);
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--)
                v.push_back(matrix[i][left]);
            left++;
        }
    }
    return v;
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
    vector<int>v = spiralOrder(vv);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
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