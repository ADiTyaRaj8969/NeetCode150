// Topic: Balanced Binary Tree
// Description: Check if every subtree's height difference ≤ 1.
// Approach: DFS returning height or -1 if unbalanced to short-circuit.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int checkHeight(TreeNode* node)
{
    if (!node)
        return 0;
    int lh = checkHeight(node->left);
    if (lh == -1)
        return -1;
    int rh = checkHeight(node->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> vals1 = {"3", "9", "20", "null", "null", "15", "7"};
    vector<string> vals2 = {"1", "2", "2", "3", "3", "null", "null", "4", "4"};
    TreeNode* r1 = buildLevel(vals1);
    TreeNode* r2 = buildLevel(vals2);
    cout << "Test 1 -> " << (checkHeight(r1) != -1 ? "true" : "false") << "\n";
    cout << "Test 2 -> " << (checkHeight(r2) != -1 ? "true" : "false") << "\n";
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
