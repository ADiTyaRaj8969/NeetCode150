// Topic: Validate Binary Search Tree
// Description: Determine if a binary tree is a valid BST.
// Approach: Iterative inorder traversal to ensure values are strictly increasing.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    long long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeLevel(const vector<long long>& vals)
{
    if (vals.empty())
        return nullptr;
    int n = vals.size();
    if (vals[0] == LLONG_MIN)
        return nullptr;
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
            if (vals[i] != LLONG_MIN)
            {
                node->left = new TreeNode(vals[i]);
                q.push(node->left);
            }
            ++i;
        }
        if (i < n)
        {
            if (vals[i] != LLONG_MIN)
            {
                node->right = new TreeNode(vals[i]);
                q.push(node->right);
            }
            ++i;
        }
    }
    return root;
}

bool isValidBST(TreeNode* root)
{
    stack<TreeNode*> st;
    TreeNode* cur = root;
    long long prev = LLONG_MIN;
    bool first = true;
    while (cur || !st.empty())
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        if (!first && cur->val <= prev)
            return false;
        prev = cur->val;
        first = false;
        cur = cur->right;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<long long>> tests = {{2, 1, 3},                              // valid BST
                                       {5, 1, 4, LLONG_MIN, LLONG_MIN, 3, 6},  // invalid BST
                                       {}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        TreeNode* root = buildTreeLevel(tests[i]);
        cout << "Test " << (i + 1) << ": " << (isValidBST(root) ? 1 : 0) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
