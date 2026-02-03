// Topic: Best Time to Buy and Sell Stock
// Description: Find max profit from one buy-sell transaction.
// Approach: Track minimum price so far and compute max profit.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int maxProfit(const vector<int>& prices)
    {
        int minp = INT_MAX, best = 0;
        for (int p : prices)
        {
            minp = min(minp, p);
            best = max(best, p - minp);
        }
        return best;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> tests = {{7, 1, 5, 3, 6, 4}, {7, 6, 4, 3, 1}};
    for (size_t t = 0; t < tests.size(); ++t)
    {
        cout << "Test " << (t + 1) << ": ";
        for (size_t i = 0; i < tests[t].size(); ++i)
        {
            if (i)
                cout << ",";
            cout << tests[t][i];
        }
        cout << " -> " << Solution().maxProfit(tests[t]) << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
