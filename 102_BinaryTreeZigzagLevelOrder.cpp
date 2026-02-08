// Topic: Binary Tree Zigzag Level Order Traversal
// Description: Return level order traversal where the traversal direction alternates each level.
// Approach: BFS level-order and reverse every other level (or use deque to push accordingly).

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
    if (vals[0] == -1)
        return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1, n = vals.size();
    while (!q.empty() && i < n)
    {
        TreeNode* node = q.front();
        q.pop();
        if (i < n)
        {
            if (vals[i] != -1)
            {
                node->left = new TreeNode(vals[i]);
                q.push(node->left);
            }
            ++i;
        }
        if (i < n)
        {
            if (vals[i] != -1)
            {
                node->right = new TreeNode(vals[i]);
                q.push(node->right);
            }
            ++i;
        }
    }
    return root;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    if (!root)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> level(sz);
        for (int i = 0; i < sz; ++i)
        {
            TreeNode* node = q.front();
            q.pop();
            int idx = leftToRight ? i : (sz - 1 - i);
            level[idx] = node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        res.push_back(level);
        leftToRight = !leftToRight;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{3, 9, 20, -1, -1, 15, 7}, {1, 2, 3, 4, 5, 6, 7}, {}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        TreeNode* root = buildTreeLevel(tests[i]);
        auto ans = zigzagLevelOrder(root);
        cout << "Test " << (i + 1) << ":\n";
        for (auto& lvl : ans)
        {
            for (size_t j = 0; j < lvl.size(); ++j)
                cout << lvl[j] << (j + 1 == lvl.size() ? '\n' : ' ');
        }
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
