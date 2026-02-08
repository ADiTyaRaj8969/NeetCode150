// Topic: Clone Graph
// Description: Given a reference to a node in an undirected graph, return a deep copy of the graph.
// Approach: BFS/DFS with hashmap to clone nodes. Input as adjacency lists: n (nodes numbered
// 0..n-1), then for each node k followed by k neighbors.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    vector<Node*> neighbors;
    Node(int _val) : val(_val) {}
};

Node* cloneGraph(Node* node)
{
    if (!node)
        return nullptr;
    unordered_map<Node*, Node*> m;
    queue<Node*> q;
    q.push(node);
    m[node] = new Node(node->val);
    while (!q.empty())
    {
        Node* cur = q.front();
        q.pop();
        for (Node* nei : cur->neighbors)
        {
            if (!m.count(nei))
            {
                m[nei] = new Node(nei->val);
                q.push(nei);
            }
            m[cur]->neighbors.push_back(m[nei]);
        }
    }
    return m[node];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<vector<int>>> tests = {
        {{1, 2}, {2}, {0}},  // triangle 0->1,0->2 etc.
        {{1}, {}, {}},       // 0->1
        {{}}                 // single node with no neighbors
    };

    for (int t = 0; t < (int)tests.size(); ++t)
    {
        auto adj = tests[t];
        int n = (int)adj.size();
        vector<Node*> nodes(n, nullptr);
        for (int i = 0; i < n; ++i) nodes[i] = new Node(i);
        for (int i = 0; i < n; ++i)
            for (int v : adj[i]) nodes[i]->neighbors.push_back(nodes[v]);
        Node* cloned = cloneGraph(nodes[0]);
        unordered_map<int, vector<int>> out;
        unordered_set<Node*> seen;
        queue<Node*> q;
        q.push(cloned);
        seen.insert(cloned);
        while (!q.empty())
        {
            Node* cur = q.front();
            q.pop();
            for (Node* nei : cur->neighbors)
            {
                out[cur->val].push_back(nei->val);
                if (!seen.count(nei))
                {
                    seen.insert(nei);
                    q.push(nei);
                }
            }
        }
        cout << "Test " << (t + 1) << ":\n";
        vector<int> keys;
        for (auto& p : out) keys.push_back(p.first);
        sort(keys.begin(), keys.end());
        for (int k : keys)
        {
            cout << k << ":";
            for (size_t i = 0; i < out[k].size(); ++i) cout << (i ? ' ' : ' ') << out[k][i];
            cout << "\n";
        }
    }
    return 0;
}

/*
Time Complexity: O(N + E)
Space Complexity: O(N)
*/
