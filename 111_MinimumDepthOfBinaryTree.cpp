// Topic: Minimum Depth of Binary Tree
// Description: Find the minimum depth from root to the nearest leaf.
// Approach: BFS level-order; first time we see a leaf, return depth.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeLevel(const vector<int>& vals)
{
    if (vals.empty())
        return nullptr;
    int n = vals.size();
    if (vals[0] == -1)
        return nullptr;
    vector<TreeNode*> nodes(n, nullptr);
    for (int i = 0; i < n; ++i)
        if (vals[i] != -1)
            nodes[i] = new TreeNode(vals[i]);
    for (int i = 0; i < n; ++i)
        if (nodes[i])
        {
            int l = 2 * i + 1, r = 2 * i + 2;
            if (l < n)
                nodes[i]->left = nodes[l];
            if (r < n)
                nodes[i]->right = nodes[r];
        }
    return nodes[0];
}

int minDepth(TreeNode* root)
{
    if (!root)
        return 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});
    while (!q.empty())
    {
        auto [node, d] = q.front();
        q.pop();
        if (!node->left && !node->right)
            return d;
        if (node->left)
            q.push({node->left, d + 1});
        if (node->right)
            q.push({node->right, d + 1});
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{3, 9, 20, -1, -1, 15, 7}, {1, 2}, {}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto vals = tests[i];
        TreeNode* root = buildTreeLevel(vals);
        cout << "Test " << (i + 1) << ": " << minDepth(root) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
