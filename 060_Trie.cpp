// Topic: Implement Trie (Prefix Tree)
// Description: Design prefix tree supporting insert, search, and startsWith operations.
// Approach: Standard trie using array/map of children.

#include <bits/stdc++.h>
using namespace std;

class Trie
{
    struct Node
    {
        array<Node*, 26> nxt{};
        bool end = false;
        Node() { nxt.fill(nullptr); }
    };
    Node* root;

   public:
    Trie() : root(new Node()) {}
    void insert(const string& word)
    {
        Node* p = root;
        for (char ch : word)
        {
            int i = ch - 'a';
            if (!p->nxt[i])
                p->nxt[i] = new Node();
            p = p->nxt[i];
        }
        p->end = true;
    }
    bool search(const string& word)
    {
        Node* p = root;
        for (char ch : word)
        {
            int i = ch - 'a';
            if (!p->nxt[i])
                return false;
            p = p->nxt[i];
        }
        return p->end;
    }
    bool startsWith(const string& prefix)
    {
        Node* p = root;
        for (char ch : prefix)
        {
            int i = ch - 'a';
            if (!p->nxt[i])
                return false;
            p = p->nxt[i];
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Trie trie;
    trie.insert("apple");
    cout << "search(apple) -> " << (trie.search("apple") ? "true" : "false") << "\n";
    cout << "search(app) -> " << (trie.search("app") ? "true" : "false") << "\n";
    cout << "startsWith(app) -> " << (trie.startsWith("app") ? "true" : "false") << "\n";
    trie.insert("app");
    cout << "search(app) -> " << (trie.search("app") ? "true" : "false") << "\n";
}

/*
Time Complexity: insert/search/startsWith O(L) where L is word length
Space Complexity: O(total characters stored)
*/
