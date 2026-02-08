// Topic: Maximum Product Subarray
// Description: Find the contiguous subarray within an array (containing at least one number) which
// has the largest product. Approach: Track both maximum and minimum products at each position
// because negative numbers flip sign.

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums)
{
    if (nums.empty())
        return 0;
    int n = nums.size();
    long long maxProd = nums[0], minProd = nums[0], ans = nums[0];
    for (int i = 1; i < n; ++i)
    {
        long long x = nums[i];
        if (x < 0)
            swap(maxProd, minProd);
        maxProd = max(x, maxProd * x);
        minProd = min(x, minProd * x);
        ans = max(ans, maxProd);
    }
    return (int)ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{2, 3, -2, 4}, {-2, 0, -1}, {0, 2}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": " << maxProduct(tests[i]) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
