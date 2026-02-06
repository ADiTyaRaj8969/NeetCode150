// Topic: Number of Islands
// Description: Given a 2D grid of '1's (land) and '0's (water), count islands (connected components
// of 1s). Approach: DFS/BFS flood-fill to mark visited land. Time O(m*n), space O(m*n)
// recursion/queue.

#include <bits/stdc++.h>
using namespace std;

int numIslands(vector<string>& grid)
{
    int m = grid.size();
    if (m == 0)
        return 0;
    int n = grid[0].size();
    int count = 0;
    vector<int> dirs = {0, 1, 0, -1, 0};
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == '1')
            {
                ++count;
                // BFS
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = '0';
                while (!q.empty())
                {
                    auto [r, c] = q.front();
                    q.pop();
                    for (int d = 0; d < 4; ++d)
                    {
                        int nr = r + dirs[d], nc = c + dirs[d + 1];
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1')
                        {
                            grid[nr][nc] = '0';
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<string>> tests = {
        {"11110", "11010", "11000", "00000"},  // output: 1
        {"11000", "11000", "00100", "00011"},  // output: 3
        {"1"}                                  // output: 1
    };

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto grid = tests[i];
        cout << "Test " << (i + 1) << ": ";
        cout << numIslands(grid) << "\n";
    }

    return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(min(m,n)) for BFS queue in worst-case (or O(m*n) if counting recursion stack for
DFS)
*/
