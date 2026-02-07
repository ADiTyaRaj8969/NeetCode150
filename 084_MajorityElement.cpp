// Topic: Majority Element
// Description: Given an array of size n, find the majority element (appears more than n/2 times).
// Approach: Boyer-Moore Voting Algorithm (O(n) time, O(1) space).

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums)
{
    int count = 0, candidate = 0;
    for (int num : nums)
    {
        if (count == 0)
            candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{3, 2, 3}, {2, 2, 1, 1, 1, 2, 2}, {1}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": " << majorityElement(tests[i]) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
