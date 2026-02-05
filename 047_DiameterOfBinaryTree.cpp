// Topic: Diameter of Binary Tree
// Description: Compute longest path (number of edges) between any two nodes.
// Approach: DFS returning height while tracking max diameter as left_height + right_height.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int bestDiameter;
int height(TreeNode* node)
{
    if (!node)
        return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    bestDiameter = max(bestDiameter, lh + rh);
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
    vector<string> vals1 = {"1", "2", "3", "4", "5"};
    vector<string> vals2 = {"3", "9", "20", "null", "null", "15", "7"};
    TreeNode* r1 = buildLevel(vals1);
    TreeNode* r2 = buildLevel(vals2);
    bestDiameter = 0;
    height(r1);
    cout << "Test 1 -> " << bestDiameter << "\n";
    bestDiameter = 0;
    height(r2);
    cout << "Test 2 -> " << bestDiameter << "\n";
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
