// Topic: Kth Smallest Element in a BST
// Description: Find the kth smallest element in a binary search tree.
// Approach: Inorder traversal yields sorted order; perform iterative inorder and stop at k.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildLevel(const vector<string>& vals)
{
    if (vals.empty() || vals[0] == "null")
        return nullptr;
    TreeNode* root = new TreeNode(stoi(vals[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)vals.size())
    {
        TreeNode* node = q.front();
        q.pop();
        if (i < (int)vals.size() && vals[i] != "null")
        {
            node->left = new TreeNode(stoi(vals[i]));
            q.push(node->left);
        }
        ++i;
        if (i < (int)vals.size() && vals[i] != "null")
        {
            node->right = new TreeNode(stoi(vals[i]));
            q.push(node->right);
        }
        ++i;
    }
    return root;
}

int kthSmallest(TreeNode* root, int k)
{
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty())
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        if (--k == 0)
            return cur->val;
        cur = cur->right;
    }
    return -1;  // not found
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> vals = {"3", "1", "4", "null", "2"};
    TreeNode* root = buildLevel(vals);
    cout << "Test 1 -> " << kthSmallest(root, 1) << "\n";
    cout << "Test 2 -> " << kthSmallest(root, 2) << "\n";
}

/*
Time Complexity: O(h + k) where h is tree height
Space Complexity: O(h)
*/
