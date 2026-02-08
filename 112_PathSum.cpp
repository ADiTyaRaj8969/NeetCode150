// Topic: Path Sum
// Description: Determine if the tree has a root-to-leaf path summing to target.
// Approach: DFS recursion carrying remaining sum.

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

bool hasPathSum(TreeNode* root, int target)
{
    if (!root)
        return false;
    if (!root->left && !root->right)
        return root->val == target;
    return hasPathSum(root->left, target - root->val) ||
           hasPathSum(root->right, target - root->val);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<vector<int>, int>> tests = {
        {{5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1}, 22},  // expect 1
        {{1, 2, 3}, 5},                                       // expect 0
        {{}, 0}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto vals = tests[i].first;
        int target = tests[i].second;
        TreeNode* root = buildTreeLevel(vals);
        cout << "Test " << (i + 1) << ": " << (hasPathSum(root, target) ? 1 : 0) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
