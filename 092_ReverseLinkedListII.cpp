// Topic: Reverse Linked List II
// Description: Reverse a linked list from position m to n in one-pass.
// Approach: Use pointers to find the m-1 node, reverse the sublist, reconnect. O(n) time, O(1)
// space.

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

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if (!head || m == n)
        return head;
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    for (int i = 1; i < m; ++i) prev = prev->next;
    ListNode* curr = prev->next;
    for (int i = 0; i < n - m; ++i)
    {
        ListNode* temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }
    return dummy.next;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<tuple<vector<int>, int, int>> tests = {
        {{1, 2, 3, 4}, 2, 3}, {{5, 4, 3, 2, 1}, 1, 5}, {{}, 0, 0}};

    for (int t = 0; t < (int)tests.size(); ++t)
    {
        auto vals = get<0>(tests[t]);
        int m = get<1>(tests[t]);
        int r = get<2>(tests[t]);
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        for (int x : vals)
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
        head = reverseBetween(head, m, r);
        cout << "Test " << (t + 1) << ": ";
        for (ListNode* p = head; p; p = p->next)
        {
            cout << p->val;
            if (p->next)
                cout << ' ';
        }
        cout << '\n';
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
