// Topic: Linked List Cycle
// Description: Given a linked list, determine if it has a cycle.
// Approach: Floyd's Tortoise and Hare algorithm.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* buildList(vector<int>& vals, int pos)
{
    int n = vals.size();
    if (n == 0)
        return nullptr;
    vector<ListNode*> nodes(n);
    for (int i = 0; i < n; ++i) nodes[i] = new ListNode(vals[i]);
    for (int i = 0; i < n - 1; ++i) nodes[i]->next = nodes[i + 1];
    if (pos >= 0 && pos < n)
        nodes[n - 1]->next = nodes[pos];
    return nodes[0];
}

bool hasCycle(ListNode* head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<vector<int>, int>> tests = {{{3, 2, 0, -4}, 1},  // cycle to index 1 -> true
                                            {{1, 2}, -1},        // no cycle -> false
                                            {{1}, -1}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": ";
        auto vals = tests[i].first;
        int pos = tests[i].second;
        for (size_t j = 0; j < vals.size(); ++j)
        {
            if (j)
                cout << ",";
            cout << vals[j];
        }
        cout << " pos=" << pos << " -> " << (hasCycle(buildList(vals, pos)) ? "True" : "False")
             << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
