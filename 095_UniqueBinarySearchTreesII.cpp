// Topic: Unique Binary Search Trees II
// Description: Generate all structurally unique BSTs that store values 1..n.
// Approach: Recursively generate trees by choosing each root and combining left/right subtrees.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> generateTreesRange(int lo, int hi)
{
    vector<TreeNode*> res;
    if (lo > hi)
    {
        res.push_back(nullptr);
        return res;
    }
    for (int root = lo; root <= hi; ++root)
    {
        auto lefts = generateTreesRange(lo, root - 1);
        auto rights = generateTreesRange(root + 1, hi);
        for (auto L : lefts)
            for (auto R : rights)
            {
                TreeNode* node = new TreeNode(root);
                node->left = L;
                node->right = R;
                res.push_back(node);
            }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n)
{
    if (n == 0)
        return {};
    return generateTreesRange(1, n);
}

// helper: preorder serialize with null markers
void serializePreorder(TreeNode* root, string& out)
{
    if (!root)
    {
        out += "# ";
        return;
    }
    out += to_string(root->val) + " ";
    serializePreorder(root->left, out);
    serializePreorder(root->right, out);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> tests = {2, 3};
    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto trees = generateTrees(tests[i]);
        cout << "Test " << (i + 1) << " (n=" << tests[i] << "): count=" << trees.size() << '\n';
        for (auto t : trees)
        {
            string s;
            serializePreorder(t, s);
            cout << s << "\n";
        }
    }
    return 0;
}

/*
Time Complexity: Catalan number growth — superexponential in n (O(C_n) trees), each tree
construction costs O(n) Space Complexity: O(C_n * n) for result
*/
