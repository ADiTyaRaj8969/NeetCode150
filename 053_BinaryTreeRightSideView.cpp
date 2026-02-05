// Topic: Binary Tree Right Side View
// Description: Return visible nodes from right side view (one per level).
// Approach: BFS taking last node of each level or DFS prioritizing right child.

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

vector<int> rightSideView(TreeNode* root)
{
    vector<int> res;
    if (!root)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; ++i)
        {
            TreeNode* node = q.front();
            q.pop();
            if (i == sz - 1)
                res.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> vals = {"1", "2", "3", "null", "5", "null", "4"};
    TreeNode* root = buildLevel(vals);
    auto out = rightSideView(root);
    for (size_t i = 0; i < out.size(); ++i)
    {
        if (i)
            cout << " ";
        cout << out[i];
    }
    cout << "\n";
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
