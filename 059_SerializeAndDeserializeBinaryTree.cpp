// Topic: Serialize and Deserialize Binary Tree
// Description: Encode and decode binary tree structure.
// Approach: Preorder traversal with null markers for serialization; deserialize by reading tokens.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string serialize(TreeNode* root)
{
    string out;
    function<void(TreeNode*)> dfs = [&](TreeNode* node)
    {
        if (!node)
        {
            out += "# ";
            return;
        }
        out += to_string(node->val) + " ";
        dfs(node->left);
        dfs(node->right);
    };
    dfs(root);
    return out;
}

TreeNode* deserializeHelper(istringstream& in)
{
    string token;
    if (!(in >> token))
        return nullptr;
    if (token == "#")
        return nullptr;
    TreeNode* node = new TreeNode(stoi(token));
    node->left = deserializeHelper(in);
    node->right = deserializeHelper(in);
    return node;
}

TreeNode* deserialize(const string& data)
{
    istringstream in(data);
    return deserializeHelper(in);
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

void printLevel(TreeNode* root)
{
    if (!root)
    {
        cout << "\n";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    bool first = true;
    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if (!first)
            cout << " ";
        first = false;
        cout << node->val;
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> vals = {"1", "2", "3", "null", "null", "4", "5"};
    TreeNode* root = buildLevel(vals);
    string s = serialize(root);
    cout << "Serialized: " << s << "\n";
    TreeNode* copy = deserialize(s);
    cout << "Deserialized level order: ";
    printLevel(copy);
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
