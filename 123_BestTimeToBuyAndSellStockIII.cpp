// Topic: Best Time to Buy and Sell Stock III
// Description: Max profit with at most two transactions.
// Approach: Dynamic programming: keep track of max profit after first buy/sell and second buy/sell.

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices)
{
    if (prices.empty())
        return 0;
    int n = prices.size();
    long long hold1 = LLONG_MIN, sold1 = 0, hold2 = LLONG_MIN, sold2 = 0;
    for (int price : prices)
    {
        hold1 = max(hold1, -(long long)price);
        sold1 = max(sold1, hold1 + price);
        hold2 = max(hold2, sold1 - price);
        sold2 = max(sold2, hold2 + price);
    }
    return (int)sold2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{3, 3, 5, 0, 0, 3, 1, 4}, {1, 2, 3, 4, 5}, {7, 6, 4, 3, 1}};

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
