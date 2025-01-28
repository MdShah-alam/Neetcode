#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[1000];
int visited[1000];
bool dfs(int course)
{

}
bool canFinish(int numCourses,vector<vector<int>>v)
{
    for(vector<int>k:v){
        int u=k[0];
        int v=k[1];
        adj_list[u].push_back(v);
    }
    for(int i=0;i<=numCourses;i++){
        visited[i]=0;
    }
    for(int i=0;i<numCourses;i++){
        if(dfs(i)) return false;
    }
    return true;
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
    int courses;
    cin>>courses;
    cout<<canFinish(courses,v)<<endl;
    return 0;
}

