// Topic: Valid Sudoku
// Description: Validate if a 9x9 Sudoku board is correctly filled so far.
// Approach: Check rows, columns and 3x3 boxes using bitmasks or sets.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    bool isValidSudoku(const vector<string>& board)
    {
        // board: vector of 9 strings length 9, '.' for empty
        array<int, 9> rows{}, cols{}, boxes{};
        for (int r = 0; r < 9; ++r)
        {
            for (int c = 0; c < 9; ++c)
            {
                char ch = board[r][c];
                if (ch == '.')
                    continue;
                int d = ch - '1';
                int mask = 1 << d;
                if (rows[r] & mask)
                    return false;
                if (cols[c] & mask)
                    return false;
                int b = (r / 3) * 3 + (c / 3);
                if (boxes[b] & mask)
                    return false;
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[b] |= mask;
            }
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<string>> tests = {
        {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.",
         "...419..5", "....8..79"},
        {"83..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.",
         "...419..5", "....8..79"}};
    for (size_t t = 0; t < tests.size(); ++t)
    {
        cout << "Test " << (t + 1) << " -> "
             << (Solution().isValidSudoku(tests[t]) ? "true" : "false") << "\n";
    }
}

/*
Time Complexity: O(1) (9x9 constant) ~ O(81)
Space Complexity: O(1)
*/
