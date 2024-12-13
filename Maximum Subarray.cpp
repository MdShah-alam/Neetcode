#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>&v){
    int n = v.size();
    int ans = INT_MIN;
    int m=0;
    if(n==1) return v[0];
    for(int i=0;i<n;i++){
        m+=v[i];
        ans=max(ans,m);
        if(m<0) m=0;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<maxSubArray(v)<<endl;
    return 0;
}
/**

8 
2 -3 4 -2 2 1 -1 4

*/