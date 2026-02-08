// Topic: Candy
// Description: Given ratings of children, distribute candies such that each child has at least one
// candy and children with higher ratings get more candies than neighbors. Minimize total candies.
// Approach: Two-pass greedy: left-to-right then right-to-left ensuring constraints.

#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings)
{
    int n = ratings.size();
    if (n == 0)
        return 0;
    vector<int> a(n, 1);
    for (int i = 1; i < n; ++i)
        if (ratings[i] > ratings[i - 1])
            a[i] = a[i - 1] + 1;
    for (int i = n - 2; i >= 0; --i)
        if (ratings[i] > ratings[i + 1])
            a[i] = max(a[i], a[i + 1] + 1);
    long long sum = 0;
    for (int v : a) sum += v;
    return (int)sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<int> r(n);
    for (int i = 0; i < n; ++i) cin >> r[i];
    cout << candy(r) << "\n";
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
