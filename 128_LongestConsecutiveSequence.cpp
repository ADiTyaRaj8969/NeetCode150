// Topic: Longest Consecutive Sequence
// Description: Given an unsorted array of integers, find the length of the longest consecutive
// elements sequence. Approach: Use an unordered_set for O(1) lookup. For each number that is the
// start of a sequence (num-1 not in set), count consecutive numbers.

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums)
{
    unordered_set<int> s(nums.begin(), nums.end());
    int best = 0;
    for (int num : s)
    {
        if (s.find(num - 1) != s.end())
            continue;  // not start
        int cur = num, len = 1;
        while (s.find(cur + 1) != s.end())
        {
            cur++;
            len++;
        }
        best = max(best, len);
    }
    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{100, 4, 200, 1, 3, 2}, {0, 3, 7, 2, 5, 8, 4, 6, 0, 1}};
    for (int i = 0; i < (int)tests.size(); ++i)
        cout << "Test " << (i + 1) << ": " << longestConsecutive(tests[i]) << '\n';
    return 0;
}

/*
Time Complexity: O(n) average
Space Complexity: O(n)
*/
