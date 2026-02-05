// Topic: Subtree of Another Tree
// Description: Determine if one tree is a subtree of another.
// Approach: Use tree hashing or string serialization (preorder with null markers) and substring
// check. We'll use preorder+null markers and KMP for robust matching.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorderSerialize(TreeNode* root, string& out)
{
    if (!root)
    {
        out += "#,";
        return;
    }
    out += to_string(root->val) + ",";
    preorderSerialize(root->left, out);
    preorderSerialize(root->right, out);
}

vector<int> buildKMP(const string& pat)
{
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0;
    for (int i = 1; i < m;)
    {
        if (pat[i] == pat[len])
            lps[i++] = ++len;
        else if (len)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
    return lps;
}

bool kmpSearch(const string& text, const string& pat)
{
    if (pat.empty())
        return true;
    auto lps = buildKMP(pat);
    int i = 0, j = 0;
    int n = text.size(), m = pat.size();
    while (i < n)
    {
        if (text[i] == pat[j])
        {
            ++i;
            ++j;
            if (j == m)
                return true;
        }
        else if (j)
            j = lps[j - 1];
        else
            ++i;
    }
    return false;
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
    vector<string> s1 = {"3", "4", "5", "1", "2"};
    vector<string> t1 = {"4", "1", "2"};
    vector<string> s2 = {"3", "4", "5", "1", "2"};
    vector<string> t2 = {"4", "3"};
    TreeNode* S1 = buildLevel(s1);
    TreeNode* T1 = buildLevel(t1);
    TreeNode* S2 = buildLevel(s2);
    TreeNode* T2 = buildLevel(t2);
    string SS1, TT1, SS2, TT2;
    preorderSerialize(S1, SS1);
    preorderSerialize(T1, TT1);
    preorderSerialize(S2, SS2);
    preorderSerialize(T2, TT2);
    cout << "Test 1 -> " << (kmpSearch(SS1, TT1) ? "true" : "false") << "\n";
    cout << "Test 2 -> " << (kmpSearch(SS2, TT2) ? "true" : "false") << "\n";
}

/*
Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/
