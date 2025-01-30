#include<bits/stdc++.h>
using namespace std;

int visit[205][205];
int n,m;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
void dfs(int i,int j,vector<vector<char>>&v)
{
    visit[i][j]=1;
    for(int a=0;a<4;a++){
        int x=i+dx[a];
        int y=j+dy[a];
        if((x>=0 && x<n)&&(y>=0 && y<m) && (v[x][y]=='O' && visit[x][y]==0))
            dfs(x,y,v);
    }
}
void solve(vector<vector<char>>&v)
{
    n=v.size();
    m=v[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            visit[i][j]=0;
    }
    for(int i=0;i<n;i++){
        if(v[i][0]=='O')
            dfs(i,0,v);
        if(v[i][m-1]=='O')
            dfs(i,m-1,v);
    }
    for(int j=0;j<m;j++){
        if(v[0][j]=='O')
            dfs(0,j,v);
        if(v[n-1][j]=='O')
            dfs(n-1,j,v);
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(v[i][j]=='O' && visit[i][j]==0){
                v[i][j]='X';
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }
    solve(v);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
/**

5 5
X X X X X
X O O X O
X X O X O
X O X O X
O O X X X

4 4
X X X X
X X X X
X X X X
X X X O

*/
