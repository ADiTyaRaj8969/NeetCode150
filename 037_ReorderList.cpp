// Topic: Reorder List
// Description: Rearrange nodes: first, last, second, second-last pattern.
// Approach: Find middle, reverse second half, and merge alternatingly.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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
        ListNode* pn = p->next;
        ListNode* qn = q->next;
        p->next = q;
        q->next = pn;
        p = pn;
        q = qn;
    }
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
        reorderList(h);
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
        h->next = new ListNode(2);
        h->next->next = new ListNode(3);
        h->next->next->next = new ListNode(4);
        h->next->next->next->next = new ListNode(5);
        reorderList(h);
        for (ListNode* p = h; p; p = p->next)
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
