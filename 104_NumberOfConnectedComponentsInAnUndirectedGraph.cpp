// Topic: Number of Connected Components in an Undirected Graph
// Description: Given n nodes and edge list, count connected components. Use Union-Find or DFS.
// Approach: Union-Find (disjoint set) for near-linear performance.

#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    int n;
    vector<int> p, r;
    DSU(int n) : n(n), p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
    }
};

int countComponents(int n, vector<pair<int, int>>& edges)
{
    DSU dsu(n);
    for (auto& e : edges) dsu.unite(e.first, e.second);
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) s.insert(dsu.find(i));
    return (int)s.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, vector<pair<int, int>>>> tests = {
        {4, {{0, 1}, {2, 3}}}, {5, {{0, 1}, {1, 2}, {3, 4}}}, {3, {}}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        int n = tests[i].first;
        auto edges = tests[i].second;
        cout << "Test " << (i + 1) << ": " << countComponents(n, edges) << '\n';
    }
    return 0;
}

/*
Time Complexity: near O(n + m * alpha(n))
Space Complexity: O(n)
*/
