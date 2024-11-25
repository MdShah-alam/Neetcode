#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int>adj_list[N];
int visited[N],level[N];
int parent[N];

void bfs(int src)
{
    visited[src]=1;
    level[src]=1;
    queue<int>q;
    q.push(src);
    parent[src]=-1;

    while(!q.empty()){
        int head = q.front();
        q.pop();
        for(int adj_node:adj_list[head]){
            if(visited[adj_node] == 0){
                parent[adj_node]=head;
                visited[adj_node]=1;
                level[adj_node]=1+level[head];
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src=1;
    bfs(src);
    int dst = n;
    if(visited[dst]==0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<level[dst]<<endl;
    vector<int>v;
    int selected_node = dst;
    while(true){
        v.push_back(selected_node);
        if(selected_node==src)
            break;
        selected_node=parent[selected_node];
    }
    reverse(v.begin(),v.end());
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
/**

5 5
1 2
1 3
1 4
2 3
5 4

*/
