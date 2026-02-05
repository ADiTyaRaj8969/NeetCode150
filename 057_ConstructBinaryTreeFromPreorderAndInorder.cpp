// Topic: Construct Binary Tree from Preorder and Inorder Traversal
// Description: Rebuild binary tree given preorder and inorder traversals.
// Approach: Recursively partition arrays using a value->index map for inorder positions.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(vector<int>& preorder, int pi, int pj, vector<int>& inorder, int ii, int ij,
                unordered_map<int, int>& idx)
{
    if (pi > pj || ii > ij)
        return nullptr;
    int rootVal = preorder[pi];
    TreeNode* root = new TreeNode(rootVal);
    int rpos = idx[rootVal];
    int leftSize = rpos - ii;
    root->left = build(preorder, pi + 1, pi + leftSize, inorder, ii, rpos - 1, idx);
    root->right = build(preorder, pi + leftSize + 1, pj, inorder, rpos + 1, ij, idx);
    return root;
}

// Print level-order without 'null' placeholders (only existing nodes in BFS order)
void printLevel(TreeNode* root)
{
    if (!root)
    {
        cout << "\n";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    bool first = true;
    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if (!first)
            cout << " ";
        first = false;
        cout << node->val;
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        vector<int> preorder = {3, 9, 20, 15, 7};
        vector<int> inorder = {9, 3, 15, 20, 7};
        unordered_map<int, int> idx;
        for (int i = 0; i < (int)inorder.size(); ++i) idx[inorder[i]] = i;
        TreeNode* root =
            build(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1, idx);
        printLevel(root);
    }
    {
        vector<int> preorder = {1, 2, 3};
        vector<int> inorder = {2, 1, 3};
        unordered_map<int, int> idx;
        for (int i = 0; i < (int)inorder.size(); ++i) idx[inorder[i]] = i;
        TreeNode* root =
            build(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1, idx);
        printLevel(root);
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(n) for recursion and index map
*/
