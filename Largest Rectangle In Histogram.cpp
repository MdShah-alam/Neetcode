#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    stack<pair<int, int>> st; // Stack to store (index, height)

    for (int i = 0; i < heights.size(); ++i) {
        int start = i;
        while (!st.empty() && st.top().second > heights[i]) {
            auto [index, height] = st.top();
            st.pop();
            maxArea = max(maxArea, height * (i - index));
            start = index;
        }
        st.push({start, heights[i]});
    }
    // Process remaining elements in the stack
    while(!st.empty()){
        auto temp=st.top();
        st.pop();
        int i=temp.first;
        int h=temp.second;
        maxArea = max(maxArea, h * (static_cast<int>(heights.size()) - i));
    }
    return maxArea;
}
/**
6
7 1 7 2 2 4
*/
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<largestRectangleArea(v)<<endl;
}
