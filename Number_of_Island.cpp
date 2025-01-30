#include<bits/stdc++.h>
using namespace std;

const int N=1005;
int maze[N][N],visit[N][N];
int n,m,ans=0,ans1=0;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void dfs(int i,int j)
{
    ans++;
    ans1=max(ans,ans1);
    visit[i][j]=1;
    for(int a=0;a<4;a++){
        int x=i+dx[a];
        int y=j+dy[a];
        if((x>=0 && x<n) && (y>=0 && y<m) && (maze[x][y]==1 && visit[x][y]==0))
            dfs(x,y);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>maze[i][j];
    }
    int cont=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visit[i][j]==0 && maze[i][j]==1){
                ans=0;
                dfs(i,j);
                cont++;
            }
        }
    }
    cout<<cont<<" "<<ans1<<endl;
    return 0;
}/**

4 5
0 1 1 0 1
1 0 1 0 1
0 1 1 0 1
0 1 0 0 1

*/

