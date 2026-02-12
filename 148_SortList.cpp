// Topic: Sort List
// Description: Sort a linked list in O(n log n) time and O(log n) space (merge sort on list).
// Approach: Use fast/slow to split and merge lists recursively.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* merge(ListNode* a, ListNode* b)
{
    ListNode dummy(0), *t = &dummy;
    while (a && b)
    {
        if (a->val < b->val)
        {
            t->next = a;
            a = a->next;
        }
        else
        {
            t->next = b;
            b = b->next;
        }
        t = t->next;
    }
    t->next = a ? a : b;
    return dummy.next;
}

ListNode* sortList(ListNode* head)
{
    if (!head || !head->next)
        return head;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return merge(left, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> tests = {{4, 2, 1, 3}, {-1, 5, 3, 4, 0}};
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
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        for (size_t k = 0; k < vals.size(); ++k)
        {
            ListNode* t = new ListNode(vals[k]);
            if (!head)
                head = tail = t;
            else
            {
                tail->next = t;
                tail = t;
            }
        }
        ListNode* out = sortList(head);
        bool first = true;
        for (ListNode* p = out; p; p = p->next)
        {
            if (!first)
                cout << ",";
            cout << p->val;
            first = false;
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(n log n)
Space Complexity: O(log n) recursion
*/
