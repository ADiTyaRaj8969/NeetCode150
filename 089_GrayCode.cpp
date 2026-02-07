// Topic: Gray Code
// Description: Generate n-bit Gray code sequence.
// Approach: Use formula i ^ (i >> 1) for 0..(1<<n)-1. O(2^n * n) to output, O(1) extra memory
// besides result.

#include <bits/stdc++.h>
using namespace std;

vector<int> grayCode(int n)
{
    vector<int> res;
    int total = 1 << n;
    res.reserve(total);
    for (int i = 0; i < total; ++i) res.push_back(i ^ (i >> 1));
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> tests = {2, 3, 1};
    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto ans = grayCode(tests[i]);
        cout << "Test " << (i + 1) << " (n=" << tests[i] << "): ";
        for (size_t j = 0; j < ans.size(); ++j)
            cout << ans[j] << (j + 1 == ans.size() ? '\n' : ' ');
    }
    return 0;
}

/*
Time Complexity: O(2^n)
Space Complexity: O(2^n) for result
*/
