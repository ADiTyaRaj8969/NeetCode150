// Topic: Gas Station
// Description: Given gas and cost arrays, return the starting gas station's index if you can travel
// around the circuit once, otherwise -1. Approach: Greedy: if total gas >= total cost there is a
// solution; track current tank and reset start when tank < 0.

#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int n = gas.size();
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < n; ++i)
    {
        total += gas[i] - cost[i];
        tank += gas[i] - cost[i];
        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }
    return total >= 0 ? start : -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Embedded test cases (no stdin)
    vector<vector<int>> gas_tests = {{1, 2, 3, 4, 5}, {2, 3, 4}, {2, 2, 2}};
    vector<vector<int>> cost_tests = {{3, 4, 5, 1, 2}, {3, 4, 3}, {1, 1, 1}};

    for (size_t i = 0; i < gas_tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": gas = [";
        for (size_t j = 0; j < gas_tests[i].size(); ++j)
        {
            if (j)
                cout << ",";
            cout << gas_tests[i][j];
        }
        cout << "], cost = [";
        for (size_t j = 0; j < cost_tests[i].size(); ++j)
        {
            if (j)
                cout << ",";
            cout << cost_tests[i][j];
        }
        cout << "] -> start index = " << canCompleteCircuit(gas_tests[i], cost_tests[i]) << "\n";
    }

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
