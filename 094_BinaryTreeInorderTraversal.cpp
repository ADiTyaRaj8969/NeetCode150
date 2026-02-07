// Topic: Binary Tree Inorder Traversal
// Description: Return inorder traversal of a binary tree.
// Approach: Build tree from level-order with -1 as null, then iterative inorder using stack (or
// recursive). O(n) time.

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
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n)
    {
        TreeNode* node = q.front();
        q.pop();
        if (i < n && vals[i] != -1)
        {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        ++i;
        if (i < n && vals[i] != -1)
        {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        ++i;
    }
    return root;
}

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> res;
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
        res.push_back(cur->val);
        cur = cur->right;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {
        {1, 2, 3},      // root=1,left=2,right=3 (no nulls used here)
        {1, -1, 2, 3},  // -1 denotes null (example tree)
        {}              // empty
    };

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto vals = tests[i];
        TreeNode* root = buildTreeLevel(vals);
        auto ans = inorderTraversal(root);
        cout << "Test " << (i + 1) << ": ";
        for (size_t j = 0; j < ans.size(); ++j)
            cout << ans[j] << (j + 1 == ans.size() ? '\n' : ' ');
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h) where h is tree height (stack)
*/
