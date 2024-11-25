#include<bits/stdc++.h>
using namespace std;

string encode(vector<string>& strs)
{
    string encoded;
    for (const string& str : strs)
    {
        encoded += to_string(str.size()) + "#" + str;
    }
    return encoded;
}

vector<string>decode(const string& s)
{
    vector<string> decoded;
    size_t i = 0;
    while (i < s.size())
    {
        // Find the delimiter '#'
        size_t pos = s.find('#', i);
        if (pos == string::npos) break;

        // Extract the length of the next string
        size_t len = stoi(s.substr(i, pos - i));

        // Extract the string of the given length
        string str = s.substr(pos + 1, len);
        decoded.push_back(str);

        // Move the index to the next segment
        i = pos + 1 + len;
    }
    return decoded;
}
int main()
{
    vector<string>v={"neet","code","love","you"};
    string s= encode(v);
    cout<<s<<endl;
    vector<string>ans=decode(s);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
