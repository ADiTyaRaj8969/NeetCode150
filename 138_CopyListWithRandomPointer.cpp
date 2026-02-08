// Topic: Copy List with Random Pointer
// Description: Given a linked list where each node has a next and a random pointer, return a deep
// copy of the list. Approach: Build from input, clone using hashmap from original->copy, or
// interleaving method. Here we use hashmap for clarity.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* random;
    Node(int v) : val(v), next(nullptr), random(nullptr) {}
};

Node* buildList(const vector<int>& vals, const vector<int>& rndIdx)
{
    int n = vals.size();
    if (n == 0)
        return nullptr;
    vector<Node*> nodes(n);
    for (int i = 0; i < n; ++i) nodes[i] = new Node(vals[i]);
    for (int i = 0; i < n - 1; ++i) nodes[i]->next = nodes[i + 1];
    for (int i = 0; i < n; ++i)
    {
        if (rndIdx[i] == -1)
            nodes[i]->random = nullptr;
        else
            nodes[i]->random = nodes[rndIdx[i]];
    }
    return nodes[0];
}

Node* copyRandomList(Node* head)
{
    if (!head)
        return nullptr;
    unordered_map<Node*, Node*> mp;
    Node* cur = head;
    while (cur)
    {
        mp[cur] = new Node(cur->val);
        cur = cur->next;
    }
    cur = head;
    while (cur)
    {
        mp[cur]->next = cur->next ? mp[cur->next] : nullptr;
        mp[cur]->random = cur->random ? mp[cur->random] : nullptr;
        cur = cur->next;
    }
    return mp[head];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Embedded tests: pairs of (vals, random indices)
    vector<pair<vector<int>, vector<int>>> tests = {{{7, 13, 11, 10, 1}, {-1, 0, 4, 2, 0}},
                                                    {{1, 2, 3}, {-1, 0, 1}}};
    for (size_t t = 0; t < tests.size(); ++t)
    {
        cout << "Test " << (t + 1) << "\n";
        auto vals = tests[t].first;
        auto rnd = tests[t].second;
        Node* head = buildList(vals, rnd);
        Node* cloned = copyRandomList(head);
        // print cloned list values and random indices
        unordered_map<Node*, int> idx;
        Node* p = cloned;
        int id = 0;
        while (p)
        {
            idx[p] = id++;
            p = p->next;
        }
        cout << "Cloned size=" << id << "\nValues: ";
        p = cloned;
        while (p)
        {
            cout << p->val;
            if (p->next)
                cout << " ";
            p = p->next;
        }
        cout << "\nRandoms: ";
        p = cloned;
        while (p)
        {
            if (p->random)
                cout << idx[p->random];
            else
                cout << -1;
            if (p->next)
                cout << " ";
            p = p->next;
        }
        cout << "\n\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
