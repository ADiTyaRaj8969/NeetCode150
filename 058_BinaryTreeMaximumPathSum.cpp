// Topic: Binary Tree Maximum Path Sum
// Description: Find highest path sum among all node paths (path may start/end anywhere).
// Approach: DFS returning max gain from node downward and tracking global maximum sum.

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

int best;
int maxGain(TreeNode* node)
{
    if (!node)
        return 0;
    int leftGain = max(0, maxGain(node->left));
    int rightGain = max(0, maxGain(node->right));
    best = max(best, node->val + leftGain + rightGain);
    return node->val + max(leftGain, rightGain);
}

int maxPathSum(TreeNode* root)
{
    best = INT_MIN;
    maxGain(root);
    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> vals1 = {"1", "2", "3"};
    vector<string> vals2 = {"-10", "9", "20", "null", "null", "15", "7"};
    TreeNode* r1 = buildLevel(vals1);
    TreeNode* r2 = buildLevel(vals2);
    cout << "Test 1 -> " << maxPathSum(r1) << "\n";
    cout << "Test 2 -> " << maxPathSum(r2) << "\n";
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
