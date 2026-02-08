// Topic: Path Sum II
// Description: Find all root-to-leaf paths where sum equals target.
// Approach: DFS backtracking collect paths.

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
    if (vals[0] == INT_MIN)
        return nullptr;
    vector<TreeNode*> nodes(n, nullptr);
    for (int i = 0; i < n; ++i)
        if (vals[i] != INT_MIN)
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

void dfs(TreeNode* node, int target, vector<int>& cur, vector<vector<int>>& res)
{
    if (!node)
        return;
    cur.push_back(node->val);
    if (!node->left && !node->right && node->val == target)
        res.push_back(cur);
    else
    {
        dfs(node->left, target - node->val, cur, res);
        dfs(node->right, target - node->val, cur, res);
    }
    cur.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int target)
{
    vector<vector<int>> res;
    vector<int> cur;
    dfs(root, target, cur, res);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<vector<int>, int>> tests = {{{5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1}, 22},
                                            {{1, 2, 3}, 5}};

    for (int t = 0; t < (int)tests.size(); ++t)
    {
        auto vals = tests[t].first;
        int target = tests[t].second;
        TreeNode* root = buildTreeLevel(vals);
        auto res = pathSum(root, target);
        cout << "Test " << (t + 1) << ":\n";
        if (res.empty())
            cout << "(no paths)\n";
        for (auto& p : res)
        {
            for (size_t i = 0; i < p.size(); ++i) cout << p[i] << (i + 1 == p.size() ? '\n' : ' ');
        }
    }
    return 0;
}

/*
Time Complexity: O(n) to visit nodes; number of paths may cause extra cost
Space Complexity: O(h) recursion + output
*/
