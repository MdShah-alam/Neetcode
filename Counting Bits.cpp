#include<bits/stdc++.h>
using namespace std;

vector<int>countBits(int n){
    vector<int>k;
    for(int i=0;i<=n;i++){
        vector<int>v;
        int num=i;
        while(num>0){
            v.push_back(num & 1);
            num>>=1;
        }
        int cont=0;
        for(int j=0;j<v.size();j++){
            if(v[j]==1)
                cont++;
        }
        k.push_back(cont);
    }
    return k;
}

int main(){
    int n;
    cin>>n;
    vector<int>v = countBits(n);
    
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

/**

2
1 3
6 9
2 5

*/