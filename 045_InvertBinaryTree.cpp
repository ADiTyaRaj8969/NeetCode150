// Topic: Invert Binary Tree
// Description: Swap left and right subtrees recursively (mirror a binary tree).
// Approach: Simple recursion (or iterative stack) visiting each node once.

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
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n)
    {
        TreeNode* node = q.front();
        q.pop();
        if (i < n && vals[i] != INT_MIN)
        {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        ++i;
        if (i < n && vals[i] != INT_MIN)
        {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        ++i;
    }
    return root;
}

TreeNode* invertTree(TreeNode* root)
{
    if (!root)
        return nullptr;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

void printLevel(TreeNode* root)
{
    if (!root)
    {
        cout << "\n";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if (node)
        {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Test 1
    {
        vector<int> vals = {4, 2, 7, 1, 3, 6, 9};
        TreeNode* root = buildTreeLevel(vals);
        root = invertTree(root);
        printLevel(root);
    }
    // Test 2
    {
        vector<int> vals = {2, 1, 3};
        TreeNode* root = buildTreeLevel(vals);
        root = invertTree(root);
        printLevel(root);
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(h) recursion stack where h is tree height
*/
