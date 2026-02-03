// Topic: 3Sum
// Description: Return all unique triplets that sum to zero without duplicates.
// Approach: Sort and use two-pointer for each fixed i, skip duplicates.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            if (i && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];
            int l = i + 1, r = (int)nums.size() - 1;
            while (l < r)
            {
                int s = nums[l] + nums[r];
                if (s == target)
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    while (l < r && nums[r] == nums[r - 1]) --r;
                    ++l;
                    --r;
                }
                else if (s < target)
                    ++l;
                else
                    --r;
            }
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> tests = {{-1, 0, 1, 2, -1, -4}, {0, 0, 0, 0}};
    for (size_t t = 0; t < tests.size(); ++t)
    {
        cout << "Test " << (t + 1) << ": ";
        auto a = tests[t];
        for (size_t i = 0; i < a.size(); ++i)
        {
            if (i)
                cout << ",";
            cout << a[i];
        }
        cout << " -> \n";
        auto res = Solution().threeSum(a);
        for (auto& trip : res)
        {
            for (int i = 0; i < 3; ++i)
            {
                if (i)
                    cout << ",";
                cout << trip[i];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(n^2)
Space Complexity: O(log n) for sort or O(n) depending on sort implementation
*/
