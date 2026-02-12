// Topic: Binary Tree Preorder Traversal
// Description: Given a binary tree (level-order with -1 as null), return preorder traversal.
// Approach: Build tree from level-order then iterative stack-based preorder.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
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

vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> res;
    if (!root)
        return res;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node->val);
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> tests = {{1, 2, 3, -1, -1, 4, 5}, {1, -1, 2, 3}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": ";
        auto arr = tests[i];
        for (size_t j = 0; j < arr.size(); ++j)
        {
            if (j)
                cout << ",";
            cout << arr[j];
        }
        cout << " -> ";
        TreeNode* root = buildTree(arr);
        auto ans = preorderTraversal(root);
        for (size_t k = 0; k < ans.size(); ++k)
        {
            if (k)
                cout << ",";
            cout << ans[k];
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
