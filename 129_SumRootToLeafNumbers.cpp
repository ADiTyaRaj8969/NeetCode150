// Topic: Sum Root to Leaf Numbers
// Description: Given a binary tree where each node contains a single digit, each root-to-leaf path
// forms a number. Return the total sum of all root-to-leaf numbers. Approach: Build tree from
// level-order input using -1 as null, then DFS to accumulate path values.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<int>& arr)
{
    if (arr.empty() || arr[0] == -1)
        return nullptr;
    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (i < arr.size() && !q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if (i < arr.size() && arr[i] != -1)
        {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1)
        {
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

int dfsSum(TreeNode* node, int cur)
{
    if (!node)
        return 0;
    cur = cur * 10 + node->val;
    if (!node->left && !node->right)
        return cur;
    return dfsSum(node->left, cur) + dfsSum(node->right, cur);
}

int sumNumbers(TreeNode* root)
{
    return dfsSum(root, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {
        {1, 2, 3},       // numbers: 12 + 13 = 25
        {4, 9, 0, 5, 1}  // example tree
    };

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        TreeNode* root = buildTree(tests[i]);
        cout << "Test " << (i + 1) << ": " << sumNumbers(root) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(N)
Space Complexity: O(H) recursion stack
*/
