// Topic: Interleaving String
// Description: Given s1, s2, s3 determine if s3 is formed by interleaving s1 and s2.
// Approach: 2D DP where dp[i][j] means s3[0..i+j-1] can be formed using s1[0..i-1] and s2[0..j-1].

#include <bits/stdc++.h>
using namespace std;

bool isInterleave(const string& s1, const string& s2, const string& s3)
{
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    if (n1 + n2 != n3)
        return false;
    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= n1; ++i)
    {
        for (int j = 0; j <= n2; ++j)
        {
            if (i > 0)
                dp[i][j] = dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
            if (j > 0)
                dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }
    return dp[n1][n2];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<tuple<string, string, string>> tests = {
        {"aabcc", "dbbca", "aadbbcbcac"}, {"aabcc", "dbbca", "aadbbbaccc"}, {"", "", ""}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto s1 = get<0>(tests[i]);
        auto s2 = get<1>(tests[i]);
        auto s3 = get<2>(tests[i]);
        cout << "Test " << (i + 1) << ": " << (isInterleave(s1, s2, s3) ? 1 : 0) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n1 * n2)
Space Complexity: O(n1 * n2) (can be reduced to O(min(n1,n2)))
*/
