// Topic: Symmetric Tree
// Description: Check whether a binary tree is symmetric (mirror of itself).
// Approach: Recursively compare left and right subtrees (or iterative with queue). We'll build tree
// from level-order using -1 as null.

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
    if (vals[0] == -1)
        return nullptr;
    int n = vals.size();
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n)
    {
        TreeNode* node = q.front();
        q.pop();
        if (i < n)
        {
            if (vals[i] != -1)
            {
                node->left = new TreeNode(vals[i]);
                q.push(node->left);
            }
            ++i;
        }
        if (i < n)
        {
            if (vals[i] != -1)
            {
                node->right = new TreeNode(vals[i]);
                q.push(node->right);
            }
            ++i;
        }
    }
    return root;
}

bool isMirror(TreeNode* a, TreeNode* b)
{
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;
    return a->val == b->val && isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

bool isSymmetric(TreeNode* root)
{
    if (!root)
        return true;
    return isMirror(root->left, root->right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{1, 2, 2, 3, 4, 4, 3}, {1, 2, 2, -1, 3, -1, 3}, {}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        TreeNode* root = buildTreeLevel(tests[i]);
        cout << "Test " << (i + 1) << ": " << (isSymmetric(root) ? 1 : 0) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h) recursion stack
*/
