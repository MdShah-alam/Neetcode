#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int>adj_list[N];
int visit[N];

void bfs(int src)
{
    queue<int>q;
    visit[src]=1;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int adj_node:adj_list[node]){
            if(visit[adj_node]==0){
                q.push(adj_node);
                visit[adj_node]=1;
            }
        }
    }

}
void dfs(int src)
{
    visit[src]=1;
    cout<<src<<" ";
    for(int adj_node : adj_list[src]){
        if(visit[adj_node]==0)
            dfs(adj_node);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int start=1;
    bfs(start);
    cout<<endl;

    for(int i=1;i<=n+5;i++)
        visit[i]=0;
    dfs(start);
    cout<<endl;

    return 0;
}
