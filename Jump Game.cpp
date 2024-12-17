#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>&v) {
    int n=v.size();
    if(n==0) return true;
    if(n==1 && v[0]!=0) return true;
    if(v[0]==0) return false;
    int idx=0;
    int i=0;
    while(i<n){
        idx=max(idx,i+v[i]);
        i++;
        // cout<<i<<" "<<idx<<endl;
        if(i>idx && i<n)
            return false;
    }
    return true;
}

int jump(vector<int>&v){
    int faster=0;
    int same=0;
    int jump=0;
    int n=v.size();
    if(n==1) return 0;
    for(int i=0;i<n;i++){
        faster=max(faster,v[i]+i);
        if(i==same){
            same=faster;
            jump++;
            if(same>=n-1) return jump;
        }
    }
    return jump;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    // cout<<canJump(v)<<endl;
    cout<<jump(v)<<endl;
    return 0;
}
/**
 
5
1 2 0 1 0

*/