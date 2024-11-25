#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<pair<int,int>>adj_list[N];
int visited[N],dist[N];

void dijkstra(int src, int n) {
    // Initialize the source node distance
    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        int selected_node = -1;

        // Select the unvisited node with the smallest distance
        for (int j = 1; j <= n; j++) {
            if (visited[j] == 1) continue;
            if (selected_node == -1 || dist[selected_node] > dist[j])
                selected_node = j;
        }

        // If no valid node is found, break (disconnected graph case)
        if (selected_node == -1) break;

        visited[selected_node] = 1;

        // Relax edges of the selected node
        for (auto adj_node : adj_list[selected_node]) {
            int node = adj_node.first;
            int w = adj_node.second;

            if (dist[selected_node] + w < dist[node]) {
                dist[node] = dist[selected_node] + w;
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});
    }

    int src=1;
    int k=INT_MAX;
    for(int i=1;i<=n;i++){
        dist[i]=k;
        visited[i]=0;
    }

    dijkstra(src,n);

    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
    return 0;
}
