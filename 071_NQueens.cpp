// Topic: N-Queens
// Description: Place n queens on an n x n board so that no two queens attack each other.
// Approach: Backtracking with bitsets for columns and diagonals for O(n!) worst-case with pruning.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<int> cols(n, -1);
        vector<bool> colUsed(n, false), diag1(2 * n, false), diag2(2 * n, false);
        string row(n, '.');
        function<void(int)> dfs = [&](int r)
        {
            if (r == n)
            {
                vector<string> board(n, string(n, '.'));
                for (int i = 0; i < n; ++i) board[i][cols[i]] = 'Q';
                res.push_back(board);
                return;
            }
            for (int c = 0; c < n; ++c)
            {
                if (colUsed[c] || diag1[r - c + n] || diag2[r + c])
                    continue;
                cols[r] = c;
                colUsed[c] = diag1[r - c + n] = diag2[r + c] = true;
                dfs(r + 1);
                colUsed[c] = diag1[r - c + n] = diag2[r + c] = false;
            }
        };
        dfs(0);
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 4;
    auto ans = Solution().solveNQueens(n);
    cout << "Solutions for n=" << n << " -> " << ans.size() << "\n";
    for (auto& board : ans)
    {
        for (auto& row : board) cout << row << "\n";
        cout << "\n";
    }
}

/*
Time Complexity: O(n!) worst-case (backtracking), heavy pruning reduces actual runtime
Space Complexity: O(n^2) for storing solutions (plus O(n) recursion)
*/
