// Topic: Design Add and Search Words Data Structure
// Description: Trie that supports inserting words and searching with '.' wildcard which can match
// any letter. Approach: Standard Trie with recursive search supporting wildcard; insert in O(L),
// search worst-case O(26^L) for wildcards but typical much faster.

#include <bits/stdc++.h>
using namespace std;

class WordDictionary
{
    struct Node
    {
        array<Node*, 26> nxt{};
        bool end = false;
        Node() { nxt.fill(nullptr); }
    };
    Node* root;

   public:
    WordDictionary() : root(new Node()) {}
    void addWord(const string& word)
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
        function<bool(Node*, int)> dfs = [&](Node* node, int idx) -> bool
        {
            if (!node)
                return false;
            if (idx == (int)word.size())
                return node->end;
            char c = word[idx];
            if (c == '.')
            {
                for (int k = 0; k < 26; ++k)
                    if (node->nxt[k] && dfs(node->nxt[k], idx + 1))
                        return true;
                return false;
            }
            else
            {
                int i = c - 'a';
                return dfs(node->nxt[i], idx + 1);
            }
        };
        return dfs(root, 0);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    cout << "search(bad) -> " << (wd.search("bad") ? "true" : "false") << "\n";
    cout << "search(.ad) -> " << (wd.search(".ad") ? "true" : "false") << "\n";
    cout << "search(b..) -> " << (wd.search("b..") ? "true" : "false") << "\n";
}

/*
Time Complexity: add O(L), search O(L * branching) worst-case with wildcards
Space Complexity: O(total characters stored)
*/
