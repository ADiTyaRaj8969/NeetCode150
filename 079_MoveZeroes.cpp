// Topic: Move Zeroes
// Description: Move all zeros in an array to the end while maintaining relative order of non-zero
// elements. Approach: Two-pointer in-place: write index for non-zero.

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums)
{
    int j = 0;  // position to write non-zero
    for (int i = 0; i < (int)nums.size(); ++i)
        if (nums[i] != 0)
            nums[j++] = nums[i];
    while (j < (int)nums.size()) nums[j++] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{0, 1, 0, 3, 12}, {0}, {1, 2, 3}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto a = tests[i];
        moveZeroes(a);
        cout << "Test " << (i + 1) << ": ";
        for (int j = 0; j < (int)a.size(); ++j)
            cout << a[j] << (j + 1 == (int)a.size() ? '\n' : ' ');
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
