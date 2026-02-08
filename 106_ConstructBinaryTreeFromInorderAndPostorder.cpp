// Topic: Construct Binary Tree from Inorder and Postorder
// Description: Given inorder and postorder traversal of a tree, construct the binary tree.
// Approach: Use the last element of postorder as root; split inorder into left/right using index
// map; recurse.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(vector<int>& inorder, int iL, int iR, vector<int>& postorder, int pL, int pR,
                unordered_map<int, int>& idx)
{
    if (iL > iR || pL > pR)
        return nullptr;
    int rootVal = postorder[pR];
    TreeNode* root = new TreeNode(rootVal);
    int inRootIdx = idx[rootVal];
    int leftSize = inRootIdx - iL;
    root->left = build(inorder, iL, inRootIdx - 1, postorder, pL, pL + leftSize - 1, idx);
    root->right = build(inorder, inRootIdx + 1, iR, postorder, pL + leftSize, pR - 1, idx);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    int n = inorder.size();
    unordered_map<int, int> idx;
    for (int i = 0; i < n; ++i) idx[inorder[i]] = i;
    return build(inorder, 0, n - 1, postorder, 0, n - 1, idx);
}

void preorderPrint(TreeNode* root)
{
    if (!root)
        return;
    cout << root->val << ' ';
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<vector<int>, vector<int>>> tests = {{{9, 3, 15, 20, 7}, {9, 15, 7, 20, 3}},
                                                    {{2, 1, 3}, {2, 3, 1}}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto inorder = tests[i].first;
        auto post = tests[i].second;
        TreeNode* root = buildTree(inorder, post);
        cout << "Test " << (i + 1) << ": ";
        preorderPrint(root);
        cout << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) for index map and recursion stack
*/
