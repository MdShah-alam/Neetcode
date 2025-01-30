#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int freshOranges=0;

    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2)
                q.push({i,j});
        }
    }

    int minutes=0;
    while(!q.empty()){
        int len = q.size();
        bool rotted = false;
        for(int i=0;i<len;i++){
            auto it = q.front();
            q.pop();
            int x=it.first;
            int y=it.second;
            for(int j=0;j<4;j++){
                int nx=x+dx[j];
                int ny=y+dy[j];
                if((nx>=0 && nx<n) && (ny>=0 && ny<m) && grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    freshOranges--;
                    q.push({nx,ny});
                    rotted=true;
                }
            }
        }
        if(rotted)
            minutes++;
    }
    if(freshOranges>0) return -1;
    return minutes;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }
    cout<<orangesRotting(v)<<endl;
    return 0;
}/**

3 3
1 1 0
0 1 1
0 1 2

*/
