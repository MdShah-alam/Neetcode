#include<bits/stdc++.h>
using namespace std;

vector<int>productExceptSelf(vector<int>& nums)
{
    int n=nums.size();
    vector<int>v(n,1);
    int leftproduct=1;

    for(int i=0;i<n;i++){
        v[i]=leftproduct;
        leftproduct*=nums[i];
    }

    int rightproduct=1;
    for(int i=n-1;i>=0 ; i--){
        v[i]*=rightproduct;
        rightproduct*=nums[i];
    }
    return v;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<int>k=productExceptSelf(v);
    for(int i=0;i<k.size();i++)
        cout<<k[i]<<" ";
    cout<<endl;
    return 0;
}
