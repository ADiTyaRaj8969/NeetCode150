// Topic: Count Good Nodes in Binary Tree
// Description: Count nodes not smaller than any ancestor on path from root.
// Approach: DFS passing current maximum along path; increment when node->val >= current max.

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

int goodNodes(TreeNode* root)
{
    int ans = 0;
    function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int maxSoFar)
    {
        if (!node)
            return;
        if (node->val >= maxSoFar)
        {
            ++ans;
            maxSoFar = node->val;
        }
        dfs(node->left, maxSoFar);
        dfs(node->right, maxSoFar);
    };
    dfs(root, INT_MIN);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> vals1 = {"3", "1", "4", "3", "null", "1", "5"};
    vector<string> vals2 = {"3", "3", "null", "4", "2"};
    TreeNode* r1 = buildLevel(vals1);
    TreeNode* r2 = buildLevel(vals2);
    cout << "Test 1 -> " << goodNodes(r1) << "\n";
    cout << "Test 2 -> " << goodNodes(r2) << "\n";
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
