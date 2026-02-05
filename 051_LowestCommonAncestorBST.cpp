// Topic: Lowest Common Ancestor of a BST
// Description: Find lowest ancestor shared by two nodes in a Binary Search Tree.
// Approach: Use BST property: if both nodes < root go left, if both > root go right, else root is
// LCA.

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    while (root)
    {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }
    return nullptr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> vals = {"6", "2", "8", "0", "4", "7", "9", "null", "null", "3", "5"};
    TreeNode* root = buildLevel(vals);
    TreeNode* p = nullptr;
    TreeNode* q = nullptr;
    // find nodes 2 and 8
    function<TreeNode*(TreeNode*, int)> findNode = [&](TreeNode* node, int v) -> TreeNode*
    {
        while (node)
        {
            if (v == node->val)
                return node;
            if (v < node->val)
                node = node->left;
            else
                node = node->right;
        }
        return nullptr;
    };
    p = findNode(root, 2);
    q = findNode(root, 8);
    TreeNode* anc = lowestCommonAncestor(root, p, q);
    if (anc)
        cout << "Test 1 -> " << anc->val << "\n";
    else
        cout << "Test 1 -> null\n";
    p = findNode(root, 2);
    q = findNode(root, 4);
    anc = lowestCommonAncestor(root, p, q);
    if (anc)
        cout << "Test 2 -> " << anc->val << "\n";
    else
        cout << "Test 2 -> null\n";
}

/*
Time Complexity: O(h) where h is tree height
Space Complexity: O(1)
*/
