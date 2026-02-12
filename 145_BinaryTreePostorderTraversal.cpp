// Topic: Binary Tree Postorder Traversal
// Description: Given a binary tree (level-order with -1 as null), return postorder traversal.
// Approach: Build tree from level-order then iterative two-stack or modified single-stack method.
// We'll use single-stack with visited flag.

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

vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> res;
    if (!root)
        return res;
    stack<pair<TreeNode*, bool>> st;
    st.push({root, false});
    while (!st.empty())
    {
        auto [node, visited] = st.top();
        st.pop();
        if (!node)
            continue;
        if (visited)
        {
            res.push_back(node->val);
        }
        else
        {
            st.push({node, true});
            if (node->right)
                st.push({node->right, false});
            if (node->left)
                st.push({node->left, false});
        }
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
        auto ans = postorderTraversal(root);
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
