// Topic: Binary Tree Level Order Traversal
// Description: Traverse tree by level using BFS and return nodes grouped by level.
// Approach: Standard BFS using queue.

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

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    if (!root)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> level;
        level.reserve(sz);
        while (sz--)
        {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        res.push_back(move(level));
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> vals = {"3", "9", "20", "null", "null", "15", "7"};
    TreeNode* root = buildLevel(vals);
    auto out = levelOrder(root);
    for (auto& lvl : out)
    {
        for (size_t i = 0; i < lvl.size(); ++i)
        {
            if (i)
                cout << " ";
            cout << lvl[i];
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
