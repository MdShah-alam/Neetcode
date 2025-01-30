#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[100005];
int visit[100005];
int parent[100005];

void bfs(int src)
{
    queue<int>q;
    visit[src]=1;
    parent[src]=0;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int adj_node:adj_list[node]){
            if(visit[adj_node]==0){
                q.push(adj_node);
                visit[adj_node]=1;
                parent[adj_node]=parent[node]+1;
            }
        }
    }

}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src=0;
    bfs(src);
    for(int i=0;i<nodes;i++){
        cout<<"node "<<i<<"->"<<"level "<<parent[i]<<endl;
    }
    return 0;
}/**

6 6

0 1
1 2
1 5
2 3
2 4
4 5

*/
