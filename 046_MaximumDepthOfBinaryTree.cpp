// Topic: Maximum Depth of Binary Tree
// Description: Find longest path from root to leaf.
// Approach: Simple recursion returning max depth of left/right + 1.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root)
{
    if (!root)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Build tree from level-order input where "null" indicates missing node
TreeNode* buildLevel(const vector<string>& vals)
{
    if (vals.empty())
        return nullptr;
    if (vals[0] == "null")
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> vals1 = {"3", "9", "20", "null", "null", "15", "7"};
    vector<string> vals2 = {};
    TreeNode* r1 = buildLevel(vals1);
    TreeNode* r2 = buildLevel(vals2);
    cout << "Test 1 -> " << maxDepth(r1) << "\n";
    cout << "Test 2 -> " << maxDepth(r2) << "\n";
}

/*
Time Complexity: O(n)
Space Complexity: O(h) recursion stack
*/
