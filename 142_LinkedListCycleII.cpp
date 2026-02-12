// Topic: Linked List Cycle II
// Description: Given a linked list, return the node where the cycle begins. If there is no cycle,
// return -1 index. Approach: Use Floyd's algorithm to find the meeting point, then find cycle
// start.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* buildListWithNodes(const vector<int>& vals, int pos, vector<ListNode*>& nodesOut)
{
    int n = vals.size();
    nodesOut.clear();
    if (n == 0)
        return nullptr;
    nodesOut.resize(n);
    for (int i = 0; i < n; ++i) nodesOut[i] = new ListNode(vals[i]);
    for (int i = 0; i < n - 1; ++i) nodesOut[i]->next = nodesOut[i + 1];
    if (pos >= 0 && pos < n)
        nodesOut[n - 1]->next = nodesOut[pos];
    return nodesOut[0];
}

ListNode* detectCycle(ListNode* head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {  // found
            ListNode* p = head;
            while (p != slow)
            {
                p = p->next;
                slow = slow->next;
            }
            return p;
        }
    }
    return nullptr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<vector<int>, int>> tests = {{{3, 2, 0, -4}, 1}, {{1, 2}, -1}};
    for (size_t t = 0; t < tests.size(); ++t)
    {
        auto vals = tests[t].first;
        int pos = tests[t].second;
        vector<ListNode*> nodes;
        ListNode* head = buildListWithNodes(vals, pos, nodes);
        ListNode* start = detectCycle(head);
        cout << "Test " << (t + 1) << ": ";
        for (size_t i = 0; i < vals.size(); ++i)
        {
            if (i)
                cout << ",";
            cout << vals[i];
        }
        cout << " pos=" << pos << " -> ";
        if (!start)
            cout << -1 << "\n";
        else
        {
            int idx = -1;
            for (int i = 0; i < (int)nodes.size(); ++i)
                if (nodes[i] == start)
                {
                    idx = i;
                    break;
                }
            cout << idx << "\n";
        }
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1) (excluding input storage)
*/
