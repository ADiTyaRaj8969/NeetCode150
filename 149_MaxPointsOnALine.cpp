// Topic: Max Points on a Line
// Description: Given n points on a 2D plane, find the maximum number of points that lie on the same
// straight line. Approach: For each point, build a hashmap of slopes to counts. Handle duplicates
// and vertical lines. O(n^2) time.

#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<pair<int, int>>& pts)
{
    int n = pts.size();
    if (n < 3)
        return n;
    int best = 0;
    for (int i = 0; i < n; ++i)
    {
        unordered_map<long long, int> cnt;  // encode slope as pair reduced
        int dup = 0, localMax = 0;
        for (int j = i + 1; j < n; ++j)
        {
            int dx = pts[j].first - pts[i].first;
            int dy = pts[j].second - pts[i].second;
            if (dx == 0 && dy == 0)
            {
                dup++;
                continue;
            }
            int g = __gcd(dx, dy);
            if (g != 0)
            {
                dx /= g;
                dy /= g;
            }
            // normalize sign
            if (dx < 0)
            {
                dx = -dx;
                dy = -dy;
            }
            else if (dx == 0 && dy < 0)
                dy = -dy;
            long long key = ((long long)dx << 32) ^ (unsigned int)dy;
            localMax = max(localMax, ++cnt[key]);
        }
        best = max(best, localMax + dup + 1);
    }
    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<pair<int, int>>> tests = {{{1, 1}, {2, 2}, {3, 3}},
                                            {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": ";
        for (size_t j = 0; j < tests[i].size(); ++j)
        {
            if (j)
                cout << ",";
            cout << "(" << tests[i][j].first << "," << tests[i][j].second << ")";
        }
        cout << " -> " << maxPoints(const_cast<vector<pair<int, int>>&>(tests[i])) << "\n";
    }
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
