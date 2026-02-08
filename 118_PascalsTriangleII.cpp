// Topic: Pascal's Triangle II
// Description: Return the k-th (0-indexed) row of Pascal's triangle.
// Approach: Build iteratively using O(k) space.

#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> row;
    for (int i = 0; i <= rowIndex; ++i)
    {
        row.insert(row.begin() + i, 1);
        for (int j = i - 1; j > 0; --j) row[j] += row[j - 1];
    }
    return row;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> tests = {0, 1, 4};
    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto row = getRow(tests[i]);
        cout << "Test " << (i + 1) << " (k=" << tests[i] << "): ";
        for (size_t j = 0; j < row.size(); ++j)
            cout << row[j] << (j + 1 == row.size() ? '\n' : ' ');
    }
    return 0;
}

/*
Time Complexity: O(k^2)
Space Complexity: O(k)
*/
