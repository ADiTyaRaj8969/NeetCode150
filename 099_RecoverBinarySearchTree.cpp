// Topic: Recover Binary Search Tree
// Description: Two nodes of a BST are swapped by mistake. Recover the tree without changing its
// structure. Approach: Inorder traversal to find two misplaced nodes, then swap their values.

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
        if (i < n)
        {
            if (vals[i] != INT_MIN)
            {
                node->left = new TreeNode(vals[i]);
                q.push(node->left);
            }
            ++i;
        }
        if (i < n)
        {
            if (vals[i] != INT_MIN)
            {
                node->right = new TreeNode(vals[i]);
                q.push(node->right);
            }
            ++i;
        }
    }
    return root;
}

void recoverTree(TreeNode* root)
{
    TreeNode *x = nullptr, *y = nullptr, *pred = nullptr, *prev = nullptr;
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
        if (prev && cur->val < prev->val)
        {
            if (!x)
                x = prev;
            y = cur;
        }
        prev = cur;
        cur = cur->right;
    }
    if (x && y)
        swap(x->val, y->val);
}

void serializePre(TreeNode* root, string& out)
{
    if (!root)
    {
        out += "# ";
        return;
    }
    out += to_string(root->val) + " ";
    serializePre(root->left, out);
    serializePre(root->right, out);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {
        {3, 1, 4, INT_MIN, INT_MIN, 2},  // swapped nodes example
        {1, 3, INT_MIN, INT_MIN, 2},
    };

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto vals = tests[i];
        TreeNode* root = buildTreeLevel(vals);
        recoverTree(root);
        string out;
        serializePre(root, out);
        cout << "Test " << (i + 1) << ": " << out << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
