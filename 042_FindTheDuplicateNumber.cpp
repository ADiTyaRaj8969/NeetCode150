// Topic: Find the Duplicate Number
// Description: Identify duplicate element in array where numbers are in range [1,n] with one
// duplicate Approach: Floyd's Tortoise and Hare cycle detection on value-index mapping, O(n) time,
// O(1) space.

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(const vector<int>& nums)
{
    int tortoise = nums[0], hare = nums[0];
    do
    {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);
    tortoise = nums[0];
    while (tortoise != hare)
    {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    return hare;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a1 = {1, 3, 4, 2, 2};
    vector<int> a2 = {3, 1, 3, 4, 2};
    cout << "Test 1 -> " << findDuplicate(a1) << "\n";
    cout << "Test 2 -> " << findDuplicate(a2) << "\n";
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
