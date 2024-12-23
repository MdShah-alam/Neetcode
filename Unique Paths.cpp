#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            dp[i][j]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i==1 && j==1)
                dp[i][j]=1;
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m][n];
}

int main(){
    int m,n;
    cin>>m>>n;
    cout<<uniquePaths(m,n)<<endl;
    return 0;
}
/**



*/