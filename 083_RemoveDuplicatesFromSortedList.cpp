// Topic: Remove Duplicates from Sorted List
// Description: Given the head of a sorted linked list, delete all duplicates such that each element
// appears only once. Approach: Iterate once and skip nodes with same value. O(n) time, O(1) space.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* buildList(int n)
{
    if (n == 0)
        return nullptr;
    int x;
    cin >> x;
    ListNode *head = new ListNode(x), *cur = head;
    for (int i = 1; i < n; ++i)
    {
        cin >> x;
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    return head;
}

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* cur = head;
    while (cur && cur->next)
    {
        if (cur->val == cur->next->val)
        {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        }
        else
            cur = cur->next;
    }
    return head;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{1, 1, 2}, {1, 1, 2, 3, 3}, {}};

    for (int t = 0; t < (int)tests.size(); ++t)
    {
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        for (int x : tests[t])
        {
            if (!head)
            {
                head = new ListNode(x);
                cur = head;
            }
            else
            {
                cur->next = new ListNode(x);
                cur = cur->next;
            }
        }
        head = deleteDuplicates(head);
        cout << "Test " << (t + 1) << ": ";
        for (ListNode* p = head; p; p = p->next)
        {
            cout << p->val;
            if (p->next)
                cout << ' ';
        }
        cout << '\n';
        // free list
        while (head)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
