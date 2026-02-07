// Topic: Scramble String
// Description: Determine if one string is a scramble of another (binary partition + possible swap
// at each split). Approach: Recursion with memoization and early pruning using character counts.
// Worst-case exponential without memo.

#include <bits/stdc++.h>
using namespace std;

struct Key
{
    int i1, i2, len;
};

string s1, s2;
unordered_map<long long, bool> memo;

bool equalCount(int i1, int i2, int len)
{
    int cnt[26] = {};
    for (int k = 0; k < len; ++k)
    {
        cnt[s1[i1 + k] - 'a']++;
        cnt[s2[i2 + k] - 'a']--;
    }
    for (int i = 0; i < 26; ++i)
        if (cnt[i] != 0)
            return false;
    return true;
}

long long keyFor(int a, int b, int c)
{
    return ((long long)a << 40) ^ ((long long)b << 20) ^ c;
}

bool dfs(int i1, int i2, int len)
{
    long long key = keyFor(i1, i2, len);
    if (memo.count(key))
        return memo[key];
    if (s1.compare(i1, len, s2, i2, len) == 0)
        return memo[key] = true;
    if (!equalCount(i1, i2, len))
        return memo[key] = false;
    for (int cut = 1; cut < len; ++cut)
    {
        // no swap
        if (dfs(i1, i2, cut) && dfs(i1 + cut, i2 + cut, len - cut))
            return memo[key] = true;
        // swap
        if (dfs(i1, i2 + len - cut, cut) && dfs(i1 + cut, i2, len - cut))
            return memo[key] = true;
    }
    return memo[key] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<string, string>> tests = {{"great", "rgeat"}, {"abcde", "caebd"}, {"a", "a"}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        s1 = tests[i].first;
        s2 = tests[i].second;
        memo.clear();
        cout << "Test " << (i + 1) << ": " << (dfs(0, 0, (int)s1.size()) ? 1 : 0) << '\n';
    }
    return 0;
}

/*
Time Complexity: High (depends on memoization) — exponential worst-case without pruning; memo
reduces repeated states. Space Complexity: O(n^3) in worst-case for memoization storage (n = string
length)
*/
