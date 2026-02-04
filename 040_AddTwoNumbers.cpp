// Topic: Add Two Numbers
// Description: Add two numbers represented by linked lists (digits stored in reverse order).
// Approach: Iterate lists, sum digits with carry, build result list.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode dummy(0), *tail = &dummy;
    int carry = 0;
    while (l1 || l2 || carry)
    {
        int s = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        carry = s / 10;
        tail->next = new ListNode(s % 10);
        tail = tail->next;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return dummy.next;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Test 1
    {
        ListNode* a = new ListNode(2);
        a->next = new ListNode(4);
        a->next->next = new ListNode(3);
        ListNode* b = new ListNode(5);
        b->next = new ListNode(6);
        b->next->next = new ListNode(4);
        ListNode* res = addTwoNumbers(a, b);
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
        ListNode* a = new ListNode(0);
        ListNode* b = new ListNode(0);
        ListNode* res = addTwoNumbers(a, b);
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
Time Complexity: O(max(n,m))
Space Complexity: O(max(n,m)) for result
*/
