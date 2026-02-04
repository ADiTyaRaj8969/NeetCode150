// Topic: Time Based Key-Value Store
// Description: Design structure supporting timestamped key-value retrievals.
// Approach: For each key keep sorted vector of (time, value) and binary search for floor timestamp.

#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> mp;

   public:
    TimeMap() { mp.reserve(1024); }
    void set(const string& key, const string& value, int timestamp)
    {
        mp[key].emplace_back(timestamp, value);
    }
    string get(const string& key, int timestamp)
    {
        auto it = mp.find(key);
        if (it == mp.end())
            return "";
        auto& v = it->second;
        int l = 0, r = (int)v.size() - 1, ans = -1;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (v[mid].first <= timestamp)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans == -1 ? string() : v[ans].second;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    TimeMap tm;
    tm.set("foo", "bar", 1);
    cout << "Test 1: get(foo,1) -> " << tm.get("foo", 1) << "\n";  // bar
    cout << "Test 1: get(foo,3) -> " << tm.get("foo", 3) << "\n";  // bar
    tm.set("foo", "bar2", 4);
    cout << "Test 1: get(foo,4) -> " << tm.get("foo", 4) << "\n";  // bar2
    cout << "Test 1: get(foo,5) -> " << tm.get("foo", 5) << "\n";  // bar2
}

/*
Time Complexity: set O(1) amortized, get O(log n_k) for key's list size
Space Complexity: O(total entries)
*/
