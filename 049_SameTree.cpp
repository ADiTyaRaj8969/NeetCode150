// Topic: Same Tree
// Description: Check if two binary trees are structurally identical with same values.
// Approach: DFS comparing nodes recursively.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
    vector<string> v1 = {"1", "2", "3"};
    vector<string> v2 = {"1", "2", "3"};
    vector<string> v3 = {"1", "2", "null", "null", "3"};
    TreeNode* t1 = buildLevel(v1);
    TreeNode* t2 = buildLevel(v2);
    TreeNode* t3 = buildLevel(v3);
    cout << "Test 1 -> " << (isSameTree(t1, t2) ? "true" : "false") << "\n";
    cout << "Test 2 -> " << (isSameTree(t1, t3) ? "true" : "false") << "\n";
}

/*
Time Complexity: O(min(n,m)) up to nodes compared
Space Complexity: O(h)
*/
