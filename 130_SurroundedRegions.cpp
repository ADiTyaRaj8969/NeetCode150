// Topic: Surrounded Regions
// Description: Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
// Replace surrounded 'O's with 'X'. Approach: Flood-fill from border 'O's to mark safe cells, then
// flip remaining 'O's to 'X', restore marked.

#include <bits/stdc++.h>
using namespace std;

void solve(vector<string>& board)
{
    if (board.empty())
        return;
    int m = board.size(), n = board[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i)
    {
        if (board[i][0] == 'O')
        {
            q.push({i, 0});
            board[i][0] = 'T';
        }
        if (board[i][n - 1] == 'O')
        {
            q.push({i, n - 1});
            board[i][n - 1] = 'T';
        }
    }
    for (int j = 0; j < n; ++j)
    {
        if (board[0][j] == 'O')
        {
            q.push({0, j});
            board[0][j] = 'T';
        }
        if (board[m - 1][j] == 'O')
        {
            q.push({m - 1, j});
            board[m - 1][j] = 'T';
        }
    }
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (auto& d : dirs)
        {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O')
            {
                board[nr][nc] = 'T';
                q.push({nr, nc});
            }
        }
    }
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'T')
                board[i][j] = 'O';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<string>> tests = {{"XOX", "OXO", "XOX"}, {"XXXX", "XOOX", "XXOX", "XOXX"}};

    for (int t = 0; t < (int)tests.size(); ++t)
    {
        auto board = tests[t];
        solve(board);
        cout << "Test " << (t + 1) << ":\n";
        for (auto& row : board) cout << row << '\n';
    }
    return 0;
}

/*
Time Complexity: O(m*n)
Space Complexity: O(m*n) worst-case for queue
*/
