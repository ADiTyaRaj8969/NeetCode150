// Topic: Merge Intervals
// Description: Given a collection of intervals, merge all overlapping intervals.
// Approach: Sort intervals by start, then iterate and merge when overlapping.

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>>& intervals)
{
    if (intervals.empty())
        return {};
    sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> res;
    res.push_back(intervals[0]);
    for (size_t i = 1; i < intervals.size(); ++i)
    {
        auto& last = res.back();
        if (intervals[i].first <= last.second)
        {
            last.second = max(last.second, intervals[i].second);
        }
        else
        {
            res.push_back(intervals[i]);
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int, int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto ans = mergeIntervals(intervals);
    cout << ans.size() << "\n";
    for (auto& p : ans) cout << p.first << " " << p.second << "\n";
}

/*
Time Complexity: O(n log n) due to sorting
Space Complexity: O(n) for output (ignoring in-place sort)
*/
