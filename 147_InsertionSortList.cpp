// Topic: Insertion Sort List
// Description: Sort a singly linked list using insertion sort.
// Approach: Maintain a sorted dummy list and insert nodes one by one.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* insertionSortList(ListNode* head)
{
    ListNode dummy(INT_MIN);
    ListNode* cur = head;
    while (cur)
    {
        ListNode* next = cur->next;
        ListNode* p = &dummy;
        while (p->next && p->next->val < cur->val) p = p->next;
        cur->next = p->next;
        p->next = cur;
        cur = next;
    }
    return dummy.next;
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
        ListNode* sorted = insertionSortList(head);
        bool first = true;
        for (ListNode* p = sorted; p; p = p->next)
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
Time Complexity: O(n^2) worst-case
Space Complexity: O(1)
*/
