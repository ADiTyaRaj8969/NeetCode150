// Topic: Merge Two Sorted Lists
// Description: Merge two sorted linked lists into one sorted list.
// Approach: Iterative dummy-head merging in O(n) time and O(1) extra space.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode dummy(0), *tail = &dummy;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Test 1
    {
        ListNode* a = new ListNode(1);
        a->next = new ListNode(2);
        a->next->next = new ListNode(4);
        ListNode* b = new ListNode(1);
        b->next = new ListNode(3);
        b->next->next = new ListNode(4);
        ListNode* res = mergeTwoLists(a, b);
        for (ListNode* p = res; p; p = p->next)
        {
            cout << p->val;
            if (p->next)
                cout << " ";
        }
        cout << "\n";
    }
    // Test 2
    {
        ListNode* a = nullptr;
        ListNode* b = new ListNode(0);
        ListNode* res = mergeTwoLists(a, b);
        for (ListNode* p = res; p; p = p->next)
        {
            cout << p->val;
            if (p->next)
                cout << " ";
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(n+m)
Space Complexity: O(1)
*/
