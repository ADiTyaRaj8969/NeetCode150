// Topic: Course Schedule
// Description: Given numCourses and prerequisites pairs, determine if you can finish all courses
// (i.e., no cycle in graph). Approach: Detect cycle using DFS (colors) or Kahn's BFS topological
// sort. We'll use DFS coloring.

#include <bits/stdc++.h>
using namespace std;

bool hasCycleDFS(int u, vector<vector<int>>& adj, vector<int>& color)
{
    color[u] = 1;  // visiting
    for (int v : adj[u])
    {
        if (color[v] == 1)
            return true;
        if (color[v] == 0 && hasCycleDFS(v, adj, color))
            return true;
    }
    color[u] = 2;  // visited
    return false;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prereq)
{
    vector<vector<int>> adj(numCourses);
    for (auto& p : prereq) adj[p.second].push_back(p.first);  // edge: second -> first
    vector<int> color(numCourses, 0);
    for (int i = 0; i < numCourses; ++i)
        if (color[i] == 0)
            if (hasCycleDFS(i, adj, color))
                return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, vector<pair<int, int>>>> tests = {
        {2, {{1, 0}}}, {2, {{1, 0}, {0, 1}}}, {3, {{1, 0}, {2, 1}}}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        int numCourses = tests[i].first;
        auto prereq = tests[i].second;
        cout << "Test " << (i + 1) << ": " << (canFinish(numCourses, prereq) ? 1 : 0) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/
