// Topic: Linked List Cycle
// Description: Detect if a singly linked list has a cycle.
// Approach: Floyd's Tortoise and Hare (fast & slow pointers) O(n) time, O(1) space.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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
    // Test 1: cycle
    {
        ListNode* n0 = new ListNode(3);
        ListNode* n1 = new ListNode(2);
        ListNode* n2 = new ListNode(0);
        ListNode* n3 = new ListNode(-4);
        n0->next = n1;
        n1->next = n2;
        n2->next = n3;
        n3->next = n1;  // pos=1
        cout << "Test 1 -> " << (hasCycle(n0) ? "true" : "false") << "\n";
    }
    // Test 2: no cycle
    {
        ListNode* n0 = new ListNode(1);
        ListNode* n1 = new ListNode(2);
        n0->next = n1;  // pos = -1
        cout << "Test 2 -> " << (hasCycle(n0) ? "true" : "false") << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
