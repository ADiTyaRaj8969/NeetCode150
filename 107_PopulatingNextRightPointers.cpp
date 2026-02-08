// Topic: Populating Next Right Pointers in Each Node
// Description: Given a perfect binary tree, connect each node's next pointer to its next right
// node. Approach: Use level traversal or next pointers to iterate O(1) space (excluding recursion
// stack). We'll use iterative level-by-level without extra containers.

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

Node* buildPerfectTreeLevel(const vector<int>& vals)
{
    if (vals.empty())
        return nullptr;
    int n = vals.size();
    vector<Node*> nodes(n);
    for (int i = 0; i < n; ++i) nodes[i] = (vals[i] == -1 ? nullptr : new Node(vals[i]));
    int idx = 0;
    for (int i = 0; i < n && nodes[i]; ++i)
    {
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < n)
            nodes[i]->left = nodes[left];
        if (right < n)
            nodes[i]->right = nodes[right];
    }
    return nodes[0];
}

Node* connect(Node* root)
{
    if (!root)
        return root;
    Node* leftmost = root;
    while (leftmost->left)
    {
        Node* head = leftmost;
        while (head)
        {
            head->left->next = head->right;
            if (head->next)
                head->right->next = head->next->left;
            head = head->next;
        }
        leftmost = leftmost->left;
    }
    return root;
}

void printLevels(Node* root)
{
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
        level = level->left;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{1, 2, 3, 4, 5, 6, 7}, {1}, {}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        Node* root = buildPerfectTreeLevel(tests[i]);
        connect(root);
        cout << "Test " << (i + 1) << ":\n";
        printLevels(root);
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1) extra (excluding tree)
*/
