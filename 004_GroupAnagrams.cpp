// Topic: Group Anagrams
// Description: Group words that contain the same letters in different orders.
// Approach: Use sorted string as key or character count key. Use unordered_map to group.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mp;
        mp.reserve(strs.size() * 2);
        for (auto& s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        res.reserve(mp.size());
        for (auto& p : mp) res.push_back(move(p.second));
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<string>> tests = {{"eat", "tea", "tan", "ate", "nat", "bat"}, {""}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": ";
        for (size_t j = 0; j < tests[i].size(); ++j)
        {
            if (j)
                cout << ",";
            cout << tests[i][j];
        }
        cout << "\nGroups:\n";
        auto res = Solution().groupAnagrams(tests[i]);
        for (auto& g : res)
        {
            for (size_t k = 0; k < g.size(); ++k)
            {
                if (k)
                    cout << " ";
                cout << g[k];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(N * L log L) where N is number of strings and L is avg length (due to sorting)
Space Complexity: O(N * L)
*/
