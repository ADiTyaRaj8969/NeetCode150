// Topic: Word Search II
// Description: Find all words present on board using Trie and backtracking.
// Approach: Build Trie of words, DFS from each cell, mark visited and collect words when Trie node
// is end.

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    array<TrieNode*, 26> nxt{};
    string word;  // non-empty when node completes a word
    TrieNode() { nxt.fill(nullptr); }
};

class Solution
{
   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        TrieNode* root = buildTrie(words);
        int m = board.size(), n = board[0].size();
        vector<string> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) dfs(board, i, j, root, res);
        // deallocate trie omitted for brevity
        return res;
    }

   private:
    TrieNode* buildTrie(vector<string>& words)
    {
        TrieNode* root = new TrieNode();
        for (auto& w : words)
        {
            TrieNode* p = root;
            for (char c : w)
            {
                int idx = c - 'a';
                if (!p->nxt[idx])
                    p->nxt[idx] = new TrieNode();
                p = p->nxt[idx];
            }
            p->word = w;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& res)
    {
        int m = board.size(), n = board[0].size();
        char c = board[i][j];
        if (c == '#')
            return;
        TrieNode* nxt = node->nxt[c - 'a'];
        if (!nxt)
            return;
        if (!nxt->word.empty())
        {
            res.push_back(nxt->word);
            nxt->word.clear();
        }
        board[i][j] = '#';
        if (i > 0)
            dfs(board, i - 1, j, nxt, res);
        if (j > 0)
            dfs(board, i, j - 1, nxt, res);
        if (i + 1 < m)
            dfs(board, i + 1, j, nxt, res);
        if (j + 1 < n)
            dfs(board, i, j + 1, nxt, res);
        board[i][j] = c;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    auto out = Solution().findWords(board, words);
    for (auto& w : out) cout << w << "\n";
}

/*
Time Complexity: O(m*n*4^L) in worst case, L = max word length, but trie + pruning reduces work;
typical much faster Space Complexity: O(sum length of words + recursion depth)
*/
