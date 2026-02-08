// Topic: Clone Graph
// Description: Given a reference of a node in a connected undirected graph, return a deep copy
// (clone) of the graph. Approach: Read an adjacency list, build nodes, then BFS clone using hashmap
// from original->copy.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    vector<Node*> neighbors;
    Node(int v) : val(v) {}
};

Node* buildGraph(int n, const vector<vector<int>>& adj)
{
    if (n == 0)
        return nullptr;
    vector<Node*> nodes(n + 1, nullptr);
    for (int i = 1; i <= n; ++i) nodes[i] = new Node(i);
    for (int i = 1; i <= n; ++i)
    {
        for (int v : adj[i]) nodes[i]->neighbors.push_back(nodes[v]);
    }
    return nodes[1];  // return node 1 as entry
}

Node* cloneGraph(Node* node)
{
    if (!node)
        return nullptr;
    unordered_map<Node*, Node*> mp;
    queue<Node*> q;
    q.push(node);
    mp[node] = new Node(node->val);
    while (!q.empty())
    {
        Node* cur = q.front();
        q.pop();
        for (Node* nei : cur->neighbors)
        {
            if (!mp.count(nei))
            {
                mp[nei] = new Node(nei->val);
                q.push(nei);
            }
            mp[cur]->neighbors.push_back(mp[nei]);
        }
    }
    return mp[node];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        adj[i].reserve(k);
        for (int j = 0; j < k; ++j)
        {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }
    Node* start = buildGraph(n, adj);
    Node* cloned = cloneGraph(start);
    // Output cloned adjacency in same format (BFS to ensure we list each node once)
    unordered_map<int, vector<int>> out;
    unordered_set<int> seen;
    queue<Node*> q;
    q.push(cloned);
    seen.insert(cloned->val);
    while (!q.empty())
    {
        Node* cur = q.front();
        q.pop();
        for (Node* nei : cur->neighbors)
        {
            out[cur->val].push_back(nei->val);
            if (!seen.count(nei->val))
            {
                seen.insert(nei->val);
                q.push(nei);
            }
        }
    }
    // print n lines; if isolated nodes exist their adjacency will be empty
    for (int i = 1; i <= n; ++i)
    {
        auto& vec = out[i];
        cout << vec.size();
        for (int v : vec) cout << " " << v;
        cout << "\n";
    }
}

/*
Time Complexity: O(N + E)
Space Complexity: O(N)
*/
