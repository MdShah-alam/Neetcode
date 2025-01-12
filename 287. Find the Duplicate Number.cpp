#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>&v)
{
    int slow=v[0];
    int fast=v[0];
    while(1){
        slow=v[slow];
        fast=v[v[fast]];
        if(slow==fast)
            break;
    }
    slow=v[0];
    while(slow!=fast){
        slow=v[slow];
        fast=v[fast];
    }
    return slow;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<findDuplicate(v)<<endl;
    return 0;
}
