// Topic: Product of Array Except Self
// Description: Compute array of products excluding the current element without division.
// Approach: Prefix and suffix products in two passes, O(n) time and O(1) extra space (output array
// not counted).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<int> productExceptSelf(const vector<int>& nums)
    {
        int n = nums.size();
        vector<int> out(n, 1);
        int prefix = 1;
        for (int i = 0; i < n; ++i)
        {
            out[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            out[i] *= suffix;
            suffix *= nums[i];
        }
        return out;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> tests = {{1, 2, 3, 4}, {0, 0}, {-1, 1, 0}};
    for (size_t t = 0; t < tests.size(); ++t)
    {
        cout << "Test " << (t + 1) << ": ";
        auto& nums = tests[t];
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (i)
                cout << ",";
            cout << nums[i];
        }
        cout << " -> ";
        auto res = Solution().productExceptSelf(nums);
        for (size_t i = 0; i < res.size(); ++i)
        {
            if (i)
                cout << ",";
            cout << res[i];
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1) extra (excluding output)
*/
