// Topic: Car Fleet
// Description: Count fleets reaching destination given speed and position.
// Approach: Sort cars by position descending and compute arrival times; a car forms new fleet only
// if its time > previous fleet time.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        int n = position.size();
        vector<pair<int, int>> cars;
        cars.reserve(n);
        for (int i = 0; i < n; ++i) cars.emplace_back(position[i], speed[i]);
        sort(cars.begin(), cars.end(), greater<>());
        double last = -1.0;
        int fleets = 0;
        for (auto& c : cars)
        {
            double time = double(target - c.first) / c.second;
            if (time > last)
            {
                ++fleets;
                last = time;
            }
        }
        return fleets;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        int target = 12;
        vector<int> pos = {10, 8, 0, 5, 3};
        vector<int> sp = {2, 4, 1, 1, 3};
        cout << "Test 1: target=12 -> " << Solution().carFleet(target, pos, sp)
             << "\n";  // expect 3
    }
    {
        int target = 10;
        vector<int> pos = {3, 5, 7};
        vector<int> sp = {3, 2, 1};
        cout << "Test 2: target=10 -> " << Solution().carFleet(target, pos, sp) << "\n";
    }
}

/*
Time Complexity: O(n log n) for sorting
Space Complexity: O(n)
*/
