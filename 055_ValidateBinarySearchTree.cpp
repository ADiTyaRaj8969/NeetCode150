// Topic: Validate Binary Search Tree
// Description: Verify if tree follows BST property (inorder strictly increasing).
// Approach: Inorder traversal comparing previous value, or recursion with bounds.

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

bool isValidBST(TreeNode* root)
{
    long long prev = LLONG_MIN;
    bool first = true;
    function<bool(TreeNode*)> inorder = [&](TreeNode* node) -> bool
    {
        if (!node)
            return true;
        if (!inorder(node->left))
            return false;
        if (!first && node->val <= prev)
            return false;
        first = false;
        prev = node->val;
        return inorder(node->right);
    };
    return inorder(root);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> vals1 = {"2", "1", "3"};
    vector<string> vals2 = {"5", "1", "4", "null", "null", "3", "6"};
    TreeNode* r1 = buildLevel(vals1);
    TreeNode* r2 = buildLevel(vals2);
    cout << "Test 1 -> " << (isValidBST(r1) ? "true" : "false") << "\n";
    cout << "Test 2 -> " << (isValidBST(r2) ? "true" : "false") << "\n";
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
