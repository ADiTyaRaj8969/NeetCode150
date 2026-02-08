// Topic: Flatten Binary Tree to Linked List
// Description: Flatten tree to linked list in-place following preorder (right pointers as next).
// Approach: Use iterative stack or reverse preorder recursion. We'll use iterative stack (O(n)
// time, O(n) stack).

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

void flatten(TreeNode* root)
{
    if (!root)
        return;
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* prev = nullptr;
    while (!st.empty())
    {
        TreeNode* cur = st.top();
        st.pop();
        if (prev)
        {
            prev->left = nullptr;
            prev->right = cur;
        }
        if (cur->right)
            st.push(cur->right);
        if (cur->left)
            st.push(cur->left);
        prev = cur;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{1, 2, 5, 3, 4, INT_MIN, 6}, {}};

    for (int t = 0; t < (int)tests.size(); ++t)
    {
        auto vals = tests[t];
        TreeNode* root = buildTreeLevel(vals);
        flatten(root);
        cout << "Test " << (t + 1) << ": ";
        TreeNode* cur = root;
        if (!cur)
            cout << "(empty)";
        while (cur)
        {
            cout << cur->val;
            if (cur->right)
                cout << ' ';
            cur = cur->right;
        }
        cout << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) stack
*/
