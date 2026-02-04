// Topic: Reverse Linked List
// Description: Reverse order of nodes in singly linked list.
// Approach: Iterative in-place reversal using three pointers.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head)
{
    ListNode* prev = nullptr;
    while (head)
    {
        ListNode* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Test 1
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        head = reverseList(head);
        for (ListNode* p = head; p; p = p->next)
        {
            cout << p->val;
            if (p->next)
                cout << " ";
        }
        cout << "\n";
    }
    // Test 2
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head = reverseList(head);
        for (ListNode* p = head; p; p = p->next)
        {
            cout << p->val;
            if (p->next)
                cout << " ";
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
