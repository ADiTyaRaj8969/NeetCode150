// Topic: Best Time to Buy and Sell Stock II
// Description: Maximize profit with as many transactions as you like (can't hold multiple shares
// simultaneously). Approach: Greedy - sum all positive differences between consecutive days.

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int profit = 0;
    for (int i = 1; i < (int)prices.size(); ++i)
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    return profit;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {
        {7, 1, 5, 3, 6, 4},  // expect 7
        {1, 2, 3, 4, 5},     // expect 4
        {7, 6, 4, 3, 1}      // expect 0
    };

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": " << maxProfit(tests[i]) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
