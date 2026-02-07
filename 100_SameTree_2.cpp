// Topic: Same Tree
// Description: Check whether two binary trees are structurally identical with same node values.
// Approach: Recursive comparison or iterative BFS. We'll use recursion for simplicity.

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<vector<int>, vector<int>>> tests = {
        {{1, 2, 3}, {1, 2, 3}}, {{1, 2}, {1, INT_MIN, 2}}, {{}, {}}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        TreeNode* t1 = buildTreeLevel(tests[i].first);
        TreeNode* t2 = buildTreeLevel(tests[i].second);
        cout << "Test " << (i + 1) << ": " << (isSameTree(t1, t2) ? 1 : 0) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(min(n1,n2)) up to O(n)
Space Complexity: O(h)
*/
