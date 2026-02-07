// Topic: Restore IP Addresses
// Description: Given a string containing only digits, restore all possible valid IP address
// combinations. Approach: Backtracking with pruning; each segment must be 0..255 and no leading
// zeros (unless segment is '0').

#include <bits/stdc++.h>
using namespace std;

bool valid(const string& s, int i, int len)
{
    if (len <= 0 || len > 3)
        return false;
    if (s[i] == '0' && len > 1)
        return false;
    int val = 0;
    for (int k = 0; k < len; ++k) val = val * 10 + (s[i + k] - '0');
    return val <= 255;
}

vector<string> restoreIpAddresses(const string& s)
{
    int n = s.size();
    vector<string> ans;
    if (n < 4 || n > 12)
        return ans;
    string cur;
    function<void(int, int)> dfs = [&](int idx, int seg)
    {
        if (seg == 4)
        {
            if (idx == n)
                ans.push_back(cur);
            return;
        }
        for (int len = 1; len <= 3; ++len)
        {
            if (idx + len > n)
                break;
            if (!valid(s, idx, len))
                continue;
            string part = s.substr(idx, len);
            int oldSize = cur.size();
            if (!cur.empty())
                cur.push_back('.');
            cur += part;
            dfs(idx + len, seg + 1);
            cur.resize(oldSize);
        }
    };
    dfs(0, 0);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> tests = {"25525511135", "2550501153", "0000"};
    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto res = restoreIpAddresses(tests[i]);
        cout << "Test " << (i + 1) << ":\n";
        for (auto& r : res) cout << r << "\n";
        if (res.empty())
            cout << "(no valid addresses)\n";
    }
    return 0;
}

/*
Time Complexity: O(1) bounded by branching factor (at most 3^4 candidates)
Space Complexity: O(1) extra excluding output (recursive depth <= 4)
*/
