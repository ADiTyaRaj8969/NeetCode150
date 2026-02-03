// Topic: Top K Frequent Elements
// Description: Return the k most frequently occurring elements in the array.
// Approach: Count frequencies and use a min-heap of size k (or bucket sort). We'll use heap.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<int> topKFrequent(const vector<int>& nums, int k)
    {
        unordered_map<int, int> freq;
        freq.reserve(nums.size() * 2);
        for (int x : nums) ++freq[x];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // (freq, val)
        for (auto& p : freq)
        {
            pq.emplace(p.second, p.first);
            if ((int)pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        res.reserve(k);
        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<vector<int>, int>> tests = {{{1, 1, 1, 2, 2, 3}, 2}, {{1}, 1}};
    for (size_t t = 0; t < tests.size(); ++t)
    {
        cout << "Test " << (t + 1) << ": ";
        auto& p = tests[t];
        for (size_t i = 0; i < p.first.size(); ++i)
        {
            if (i)
                cout << ",";
            cout << p.first[i];
        }
        cout << " k=" << p.second << " -> ";
        auto ans = Solution().topKFrequent(p.first, p.second);
        for (size_t i = 0; i < ans.size(); ++i)
        {
            if (i)
                cout << ",";
            cout << ans[i];
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(n log k)
Space Complexity: O(n)
*/
