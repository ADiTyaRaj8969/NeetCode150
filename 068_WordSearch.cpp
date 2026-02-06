// Topic: Word Search
// Description: Determine if a word exists in grid sequentially (adjacent cells, no reuse).
// Approach: Backtracking DFS with visited marking.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    bool exist(vector<vector<char>>& board, const string& word)
    {
        int m = board.size();
        if (m == 0)
            return false;
        int n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] == word[0])
                {
                    if (dfs(board, i, j, word, 0))
                        return true;
                }
        return false;
    }

   private:
    bool dfs(vector<vector<char>>& b, int i, int j, const string& w, int idx)
    {
        if (idx == (int)w.size())
            return true;
        int m = b.size(), n = b[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || b[i][j] != w[idx])
            return false;
        char tmp = b[i][j];
        b[i][j] = '#';
        bool found = dfs(b, i - 1, j, w, idx + 1) || dfs(b, i + 1, j, w, idx + 1) ||
                     dfs(b, i, j - 1, w, idx + 1) || dfs(b, i, j + 1, w, idx + 1);
        b[i][j] = tmp;
        return found;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    cout << "Test 1 (ABCCED) -> " << (Solution().exist(board, string("ABCCED")) ? "true" : "false")
         << "\n";
    cout << "Test 2 (SEE) -> " << (Solution().exist(board, string("SEE")) ? "true" : "false")
         << "\n";
    cout << "Test 3 (ABCB) -> " << (Solution().exist(board, string("ABCB")) ? "true" : "false")
         << "\n";
}

/*
Time Complexity: O(m*n * 4^L) worst-case where L is word length
Space Complexity: O(L) recursion depth
*/
