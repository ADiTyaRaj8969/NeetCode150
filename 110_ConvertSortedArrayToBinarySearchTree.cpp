// Topic: Convert Sorted Array to Binary Search Tree
// Description: Given a sorted (increasing) array, convert it to a height-balanced BST.
// Approach: Recursively choose middle element as root to get balanced BST.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(vector<int>& nums, int l, int r)
{
    if (l > r)
        return nullptr;
    int m = l + (r - l) / 2;
    TreeNode* root = new TreeNode(nums[m]);
    root->left = build(nums, l, m - 1);
    root->right = build(nums, m + 1, r);
    return root;
}

void preorder(TreeNode* root)
{
    if (!root)
        return;
    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{-10, -3, 0, 5, 9}, {1}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto a = tests[i];
        TreeNode* root = build(a, 0, (int)a.size() - 1);
        cout << "Test " << (i + 1) << ": ";
        preorder(root);
        cout << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(log n) recursion stack
*/
