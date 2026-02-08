// Topic: Palindrome Partitioning II
// Description: Given a string s, return the minimum cuts needed for a palindrome partitioning of s.
// Approach: Expand-around-center to find palindromes and maintain min-cuts DP array in O(n^2) time.

#include <bits/stdc++.h>
using namespace std;

int minCut(string s)
{
    int n = s.size();
    if (n <= 1)
        return 0;
    vector<int> cuts(n);
    for (int i = 0; i < n; ++i) cuts[i] = i;  // max cuts
    for (int center = 0; center < n; ++center)
    {
        // odd
        for (int l = center, r = center; l >= 0 && r < n && s[l] == s[r]; --l, ++r)
        {
            int newCut = (l > 0) ? cuts[l - 1] + 1 : 0;
            cuts[r] = min(cuts[r], newCut);
        }
        // even
        for (int l = center, r = center + 1; l >= 0 && r < n && s[l] == s[r]; --l, ++r)
        {
            int newCut = (l > 0) ? cuts[l - 1] + 1 : 0;
            cuts[r] = min(cuts[r], newCut);
        }
    }
    return cuts[n - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!(cin >> s))
        return 0;
    cout << minCut(s) << "\n";
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
