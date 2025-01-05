#include<bits/stdc++.h>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    // Combine position and speed into a vector of pairs
    vector<pair<int, int>> pr;
    for (size_t i = 0; i < position.size(); ++i) {
        pr.push_back({position[i], speed[i]});
    }
    // Sort pairs by position in descending order
    sort(pr.begin(), pr.end(),[](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first; // Descending order by position
    });
    for(int i=0;i<pr.size();i++){
        cout<<pr[i].first<<" "<<pr[i].second<<endl;
    }
    // Use a stack to track car fleets
    stack<double> st;

    for (const auto& [p, s] : pr) {
        double time = static_cast<double>(target - p) / s; // Time to reach the target
        st.push(time);

        // Merge fleets if the last two cars arrive together or the latter one is slower
        if (st.size() >= 2) {
            double last = st.top();
            st.pop();
            double secondLast = st.top();
            if (last <= secondLast) {
                // Merge the fleets
                st.pop();
                st.push(secondLast);
            } else {
                // Keep the last car as a new fleet
                st.push(last);
            }
        }
    }
    return st.size(); // Number of fleets
}

int main()
{
    int target,n;
    cin>>target>>n;
    vector<int>position(n),speed(n);
    for(int i=0;i<n;i++)
        cin>>position[i];
    for(int i=0;i<n;i++)
        cin>>speed[i];
    cout<<carFleet(target,position,speed)<<endl;
    return 0;
}/**

10 4
4 1 0 7
2 2 1 1

*/
