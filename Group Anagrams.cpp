#include<bits/stdc++.h>
using namespace std;

vector<vector<string>>groupAnagrams(vector<string>v)
{
    unordered_map<string,vector<string>>mp;
    for(string s:v){
        string sk=s;
        sort(s.begin(),s.end());
        if(mp.find(s)!=mp.end()) mp[s].push_back(sk);
        else
            mp[s].push_back(sk);
    }
    vector<vector<string>>vv;
    for(auto it : mp)
        vv.push_back(it.second);
    return vv;
}

int main()
{
    int n;
    cin>>n;
    vector<string>v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    vector<vector<string>>vv=groupAnagrams(v);
    for(vector<string>ss:vv){
        for(string s : ss)
            cout<<s<<" ";
        cout<<endl;
    }
    return 0;
}

/**

6
eat tea tan ate nat bat

*/
