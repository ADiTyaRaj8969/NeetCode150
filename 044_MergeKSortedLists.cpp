// Topic: Merge K Sorted Lists
// Description: Merge multiple sorted linked lists into one sorted list efficiently.
// Approach: Use a min-heap (priority_queue) of current nodes, O(N log k) where N total nodes.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Cmp
{
    bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; }
};

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
    for (auto l : lists)
        if (l)
            pq.push(l);
    ListNode dummy(0), *tail = &dummy;
    while (!pq.empty())
    {
        ListNode* node = pq.top();
        pq.pop();
        tail->next = node;
        tail = tail->next;
        if (node->next)
            pq.push(node->next);
    }
    return dummy.next;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Test 1
    {
        vector<ListNode*> lists;
        ListNode* a = new ListNode(1);
        a->next = new ListNode(4);
        a->next->next = new ListNode(5);
        ListNode* b = new ListNode(1);
        b->next = new ListNode(3);
        b->next->next = new ListNode(4);
        ListNode* c = new ListNode(2);
        c->next = new ListNode(6);
        lists.push_back(a);
        lists.push_back(b);
        lists.push_back(c);
        ListNode* res = mergeKLists(lists);
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
Time Complexity: O(N log k)
Space Complexity: O(k)
*/
