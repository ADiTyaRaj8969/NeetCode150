// Topic: Pascal's Triangle
// Description: Generate the first numRows of Pascal's triangle.
// Approach: Iteratively build rows from previous row.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    for (int r = 0; r < numRows; ++r)
    {
        vector<int> row(r + 1, 1);
        for (int i = 1; i < r; ++i) row[i] = res[r - 1][i - 1] + res[r - 1][i];
        res.push_back(move(row));
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> tests = {1, 3, 5};
    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto ans = generate(tests[i]);
        cout << "Test " << (i + 1) << " (rows=" << tests[i] << "):\n";
        for (auto& row : ans)
        {
            for (size_t j = 0; j < row.size(); ++j)
                cout << row[j] << (j + 1 == row.size() ? '\n' : ' ');
        }
    }
    return 0;
}

/*
Time Complexity: O(numRows^2)
Space Complexity: O(numRows^2)
*/
