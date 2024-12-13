#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>&v){
    int n=v.size();
    vector<int>lis;
    for(int x : v){
        auto it=lower_bound(lis.begin(),lis.end() , x);
        if(it==lis.end())
            lis.push_back(x);
        else
            *it=x;
    }
    return lis.size();
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
        
    cout<<lengthOfLIS(v)<<endl;
    return 0;
}/**

7
9 1 4 2 3 3 7

*/