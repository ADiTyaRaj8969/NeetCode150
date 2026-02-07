// Topic: Partition List
// Description: Partition a linked list around value x such that nodes < x come before nodes >= x,
// preserving original relative order. Approach: Build two lists (less and greater) and concatenate.
// O(n) time, O(1) extra space (aside from new pointers).

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

ListNode* partition(ListNode* head, int x)
{
    ListNode lessDummy(0), greaterDummy(0);
    ListNode *less = &lessDummy, *greater = &greaterDummy;
    while (head)
    {
        if (head->val < x)
        {
            less->next = head;
            less = less->next;
        }
        else
        {
            greater->next = head;
            greater = greater->next;
        }
        head = head->next;
    }
    greater->next = nullptr;
    less->next = greaterDummy.next;
    return lessDummy.next;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<vector<int>, int>> tests = {{{1, 4, 3, 2, 5, 2}, 3}, {{2, 1}, 2}, {{}, 0}};

    for (int t = 0; t < (int)tests.size(); ++t)
    {
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        for (int x : tests[t].first)
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
        head = partition(head, tests[t].second);
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
