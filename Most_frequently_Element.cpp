#include<bits/stdc++.h>
using namespace std;

int MostFrequently(vector<int>&v)
{
    int cont=0,candidate=0;
    for(int num : v){
        if(cont==0)
            candidate=num;
        if(num==candidate)
            cont++;
        else
            cont--;
    }
    return candidate;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<MostFrequently(v)<<endl;
    return 0;
}
