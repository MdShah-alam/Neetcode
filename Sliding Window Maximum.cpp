#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& v, int k)
{
    int n=v.size();
    int l=0,r=k-1;
    vector<int>ans;
    while(r<v.size()){
        vector<int>m;
        for(int i=l;i<=r;i++)
            m.push_back(v[i]);
        sort(m.begin(),m.end());
        ans.push_back(m[m.size()-1]);
        l++;
        r++;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int k;
    cin>>k;
    vector<int>ans=maxSlidingWindow(v,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}/**

7
1 2 1 0 4 2 6
3

*/
