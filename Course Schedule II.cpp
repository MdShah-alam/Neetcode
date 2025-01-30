#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj_list[numCourses];
    vector<int> in_degree(numCourses, 0);
    for (auto& pre : prerequisites) {
        adj_list[pre[1]].push_back(pre[0]);
        in_degree[pre[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        order.push_back(course);
        for (int next : adj_list[course]) {
            if (--in_degree[next] == 0) {
                q.push(next);
            }
        }
    }
    if (order.size() != numCourses) {
        return {};
    }
    return order;
}

int main() {
    int numCourses, numPrerequisites;
    cin >> numCourses >> numPrerequisites;
    vector<vector<int>> prerequisites(numPrerequisites, vector<int>(2));
    for (int i = 0; i < numPrerequisites; ++i) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }
    vector<int> order = findOrder(numCourses, prerequisites);
    if (order.empty()) {
        cout << "It's impossible to finish all courses." << endl;
    } else {
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }
    return 0;
}

/**

4 4
1 0
2 0
3 1
3 2

 */
