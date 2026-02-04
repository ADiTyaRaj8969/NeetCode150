// Topic: Copy List With Random Pointer
// Description: Clone linked list with next and random pointers.
// Approach: Interleave copied nodes, fix random pointers, then separate lists (O(n) time, O(1)
// extra).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head)
{
    if (!head)
        return nullptr;
    // 1. copy nodes next to originals
    for (Node* p = head; p; p = p->next->next)
    {
        Node* copy = new Node(p->val);
        copy->next = p->next;
        p->next = copy;
    }
    // 2. assign randoms
    for (Node* p = head; p; p = p->next->next)
    {
        if (p->random)
            p->next->random = p->random->next;
    }
    // 3. separate
    Node* dummy = new Node(0);
    Node* tail = dummy;
    for (Node* p = head; p;)
    {
        Node* copy = p->next;
        p->next = copy->next;
        tail->next = copy;
        tail = copy;
        p = p->next;
    }
    Node* res = dummy->next;
    delete dummy;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Test 1: small list
    {
        Node* n0 = new Node(7);
        Node* n1 = new Node(13);
        Node* n2 = new Node(11);
        n0->next = n1;
        n1->next = n2;
        n0->random = nullptr;
        n1->random = n0;
        n2->random = n1;
        Node* copy = copyRandomList(n0);
        unordered_map<Node*, int> idx;
        idx.reserve(4);
        int ii = 0;
        for (Node* p = copy; p; p = p->next) idx[p] = ii++;
        for (Node* p = copy; p; p = p->next)
        {
            cout << p->val;
            if (p->random)
                cout << "(" << idx[p->random] << ")";
            if (p->next)
                cout << " ";
        }
        cout << "\n";
    }
    // Test 2: empty
    {
        Node* copy = copyRandomList(nullptr);
        if (!copy)
            cout << "Empty\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1) extra (excluding output and newly created nodes)
*/
