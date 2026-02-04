// Topic: Remove Nth Node From End of List
// Description: Delete node located n positions from list end.
// Approach: Two-pointer with gap n, remove target in one pass.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode dummy(0);
    dummy.next = head;
    ListNode *first = &dummy, *second = &dummy;
    for (int i = 0; i <= n; ++i) first = first->next;
    while (first)
    {
        first = first->next;
        second = second->next;
    }
    ListNode* todel = second->next;
    second->next = second->next->next;
    delete todel;
    return dummy.next;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Test 1
    {
        ListNode* h = new ListNode(1);
        h->next = new ListNode(2);
        h->next->next = new ListNode(3);
        h->next->next->next = new ListNode(4);
        h->next->next->next->next = new ListNode(5);
        h = removeNthFromEnd(h, 2);
        for (ListNode* p = h; p; p = p->next)
        {
            cout << p->val;
            if (p->next)
                cout << " ";
        }
        cout << "\n";
    }
    // Test 2
    {
        ListNode* h = new ListNode(1);
        h = removeNthFromEnd(h, 1);
        if (!h)
            cout << "Empty\n";
        else
        {
            for (ListNode* p = h; p; p = p->next)
            {
                cout << p->val;
                if (p->next)
                    cout << " ";
            }
            cout << "\n";
        }
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
