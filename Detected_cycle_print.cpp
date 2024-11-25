#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int>adj_list[N];
int visited[N],parent[N],level[N];
int n,m,sv,ev;

bool dfs(int node , int p)
{
    visited[node] = 1;
    parent[node] = p;
    for(int adj_node : adj_list[node]){
        if(adj_node==p) continue;
        if(visited[adj_node]){
            sv=adj_node;
            ev=node;
            return true;
        }
        else{
            if(dfs(adj_node,node))
                return true;
        }
    }
    return false;
}

bool visit_all()
{
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            if(dfs(i,-1))
                return true;
        }
    }
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bool cycle = visit_all();
    if(!cycle){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    int tv=ev;
    vector<int>v;
    v.push_back(ev);
    while(tv!=sv){
        v.push_back(parent[tv]);
        tv=parent[tv];
    }
    v.push_back(ev);
    cout<<v.size()<<endl;
    reverse(v.begin() , v.end());
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
