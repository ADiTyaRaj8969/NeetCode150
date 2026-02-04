// Topic: Koko Eating Bananas
// Description: Find minimum eating speed to finish all bananas in time H.
// Approach: Binary search on speed k and check total hours required.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    long long hoursNeeded(const vector<int>& piles, int k)
    {
        long long hours = 0;
        for (int p : piles) hours += (p + k - 1) / k;
        return hours;
    }
    int minEatingSpeed(const vector<int>& piles, int H)
    {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (hoursNeeded(piles, mid) <= H)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<vector<int>, int>> tests = {{{3, 6, 7, 11}, 8}, {{30, 11, 23, 4, 20}, 5}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": -> "
             << Solution().minEatingSpeed(tests[i].first, tests[i].second) << "\n";
    }
}

/*
Time Complexity: O(n log M) where M = max pile
Space Complexity: O(1)
*/
