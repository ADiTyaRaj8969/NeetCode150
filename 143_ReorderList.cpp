// Topic: Reorder List
// Description: Given a singly linked list L: L0→L1→…→Ln-1→Ln, reorder it to:
// L0→Ln→L1→Ln-1→L2→Ln-2→… Approach: Find middle, reverse second half, merge lists.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* buildList(const vector<int>& vals)
{
    int n = vals.size();
    if (n == 0)
        return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for (int i = 1; i < n; ++i)
    {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

void reorderList(ListNode* head)
{
    if (!head || !head->next)
        return;
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* second = slow->next;
    slow->next = nullptr;
    // reverse second
    ListNode* prev = nullptr;
    while (second)
    {
        ListNode* nxt = second->next;
        second->next = prev;
        prev = second;
        second = nxt;
    }
    // merge
    ListNode* p = head;
    ListNode* q = prev;
    while (q)
    {
        ListNode* n1 = p->next;
        ListNode* n2 = q->next;
        p->next = q;
        q->next = n1;
        p = n1;
        q = n2;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> tests = {{1, 2, 3, 4}, {1, 2, 3, 4, 5}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": ";
        auto vals = tests[i];
        for (size_t j = 0; j < vals.size(); ++j)
        {
            if (j)
                cout << ",";
            cout << vals[j];
        }
        cout << " -> ";
        ListNode* head = buildList(vals);
        reorderList(head);
        for (ListNode* t = head; t; t = t->next)
        {
            cout << t->val;
            if (t->next)
                cout << ",";
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
