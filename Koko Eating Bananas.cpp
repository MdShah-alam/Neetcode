#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int l=1,r=0;
    for(int i=0;i<piles.size();i++){
        r=max(r,piles[i]);
    }
    int res=r;
    while(r>=l){
        int mid=l+(r-l)/2;
        long long hours=0;
        for(int x : piles){
            hours+=(x+mid-1)/mid;
        }
        if(hours<=h){
            res=min(res,mid);
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return res;
}/**
4
25 10 23 4
4
*/
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int target;
    cin>>target;
    cout<<minEatingSpeed(v,target)<<endl;
    return 0;
}
