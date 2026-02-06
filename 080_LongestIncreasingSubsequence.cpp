// Topic: Longest Increasing Subsequence
// Description: Find length of LIS in O(n log n) using patience sorting (tails + binary search).
// Approach: Maintain tails where tails[len] = smallest ending value of an increasing subsequence of
// length len+1.

#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    vector<int> tails;
    for (int x : nums)
    {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end())
            tails.push_back(x);
        else
            *it = x;
    }
    return (int)tails.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{10, 9, 2, 5, 3, 7, 101, 18}, {0}, {3, 1, 2}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto a = tests[i];
        cout << "Test " << (i + 1) << ": " << lengthOfLIS(a) << '\n';
    }

    return 0;
}

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
