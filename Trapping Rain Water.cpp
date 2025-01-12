#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>&v)
{
    int n=v.size();
    vector<int>premax(n),sufmax(n);
    premax[0]=v[0];
    for(int i=1;i<n;i++){
        premax[i]=max(premax[i-1],v[i]);
    }
    sufmax[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--){
        sufmax[i]=max(v[i],sufmax[i+1]);
    }
    int res=0;
    for(int i=0;i<n;i++){
        res+=(min(premax[i],sufmax[i])-v[i]);
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<endl<<trap(v)<<endl;
    return 0;
}
/**

10
0 2 0 3 1 0 1 3 2 1

*/
