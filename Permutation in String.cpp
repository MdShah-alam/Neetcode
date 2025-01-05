#include<bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    vector<int>s1mp(26,0);
    vector<int>s2mp(26,0);
    int n=s1.size();
    int m=s2.size();
    if(n>m) return false;
    int l=0,r=0;
    while(r<n){
        s1mp[s1[r]-'a']++;
        s2mp[s2[r]-'a']++;
        r++;
    }
    r--;
    while(r<m){
        if(s1mp==s2mp) return true;
        r++;
        if(r!=m)
            s2mp[s2[r]-'a']++;
        s2mp[s2[l]-'a']--;
        l++;
    }
    return false;
}

int main()
{
    string s1="adc";
    string s2="dcda";
    cout<<checkInclusion(s1,s2)<<endl;
    return 0;
}
