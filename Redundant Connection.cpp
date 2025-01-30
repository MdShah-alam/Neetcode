#include<bits/stdc++.h>
using namespace std;

int find_(vector<int>&dis,int v)
{
    if(dis[v]==-1)
        return v;
    return dis[v]=find_(dis,dis[v]);
}
vector<int>findRedundantConnection(vector<vector<int>>& edges)
{
    int n=edges.size();
    vector<int>dis(n+1,-1);
    for(auto edge : edges){
        int parent_x=find_(dis,edge[0]);
        int parent_y=find_(dis,edge[1]);
        if(parent_x==parent_y)
            return edge;
        else
            dis[parent_x]=parent_y;
    }
    return {0,0};
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    vector<int>k=findRedundantConnection(v);
    cout<<k[0]<<" "<<k[1]<<endl;
}
/**

4
1 2
1 3
3 4
2 4

*/
