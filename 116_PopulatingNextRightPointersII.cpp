// Topic: Populating Next Right Pointers II
// Description: Connect each node to its next right node in any binary tree (not necessarily
// perfect). Approach: Use BFS level-order traversal and connect nodes across each level.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

Node* buildTreeLevel(const vector<int>& vals)
{
    if (vals.empty())
        return nullptr;
    int n = vals.size();
    vector<Node*> nodes(n, nullptr);
    for (int i = 0; i < n; ++i)
        if (vals[i] != INT_MIN)
            nodes[i] = new Node(vals[i]);
    for (int i = 0; i < n; ++i)
        if (nodes[i])
        {
            int l = 2 * i + 1, r = 2 * i + 2;
            if (l < n)
                nodes[i]->left = nodes[l];
            if (r < n)
                nodes[i]->right = nodes[r];
        }
    return nodes[0];
}

Node* connect(Node* root)
{
    if (!root)
        return root;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        Node* prev = nullptr;
        for (int i = 0; i < sz; ++i)
        {
            Node* cur = q.front();
            q.pop();
            if (prev)
                prev->next = cur;
            prev = cur;
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        if (prev)
            prev->next = nullptr;
    }
    return root;
}

void printLevels(Node* root)
{
    // print each level using next pointers
    Node* level = root;
    while (level)
    {
        Node* cur = level;
        while (cur)
        {
            cout << cur->val;
            if (cur->next)
                cout << ' ';
            cur = cur->next;
        }
        cout << "\n";
        // find first node of next level
        Node* nextLevel = nullptr;
        for (Node* p = level; p; p = p->next)
        {
            if (p->left)
            {
                nextLevel = p->left;
                break;
            }
            if (p->right)
            {
                nextLevel = p->right;
                break;
            }
        }
        level = nextLevel;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{1, 2, 3, 4, 5, INT_MIN, 7}, {1, 2, INT_MIN, 3, 4}, {}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto vals = tests[i];
        Node* root = buildTreeLevel(vals);
        connect(root);
        cout << "Test " << (i + 1) << ":\n";
        printLevels(root);
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(width of tree) for queue
*/
