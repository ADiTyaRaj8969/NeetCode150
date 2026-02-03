// Topic: Sliding Window Maximum
// Description: Return maximum value from every window of size k.
// Approach: Use deque to maintain indices of candidates (monotonic queue).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k)
    {
        deque<int> dq;  // store indices, decreasing values
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<vector<int>, int>> tests = {
        {{1, 3, -1, -3, 5, 3, 6, 7}, 3}, {{1}, 1}, {{1, -1}, 1}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        auto out = Solution().maxSlidingWindow(tests[i].first, tests[i].second);
        cout << "Test " << (i + 1) << ": ";
        for (size_t j = 0; j < out.size(); ++j)
        {
            if (j)
                cout << " ";
            cout << out[j];
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(k)
*/
