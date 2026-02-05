// Topic: LRU Cache
// Description: Design a cache supporting get and put in O(1) time with LRU eviction.
// Approach: Use unordered_map for key->iterator and doubly-linked list (std::list) to maintain
// recency.

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    int cap;
    list<pair<int, int>> dq;  // {key, value}, front = most recent
    unordered_map<int, list<pair<int, int>>::iterator> mp;

   public:
    LRUCache(int capacity) : cap(capacity) { mp.reserve(capacity * 2); }
    int get(int key)
    {
        auto it = mp.find(key);
        if (it == mp.end())
            return -1;
        auto nodeIt = it->second;
        int val = nodeIt->second;
        dq.erase(nodeIt);
        dq.push_front({key, val});
        mp[key] = dq.begin();
        return val;
    }
    void put(int key, int value)
    {
        auto it = mp.find(key);
        if (it != mp.end())
        {
            dq.erase(it->second);
            mp.erase(it);
        }
        dq.push_front({key, value});
        mp[key] = dq.begin();
        if ((int)mp.size() > cap)
        {
            auto last = dq.back();
            mp.erase(last.first);
            dq.pop_back();
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << "get(1) -> " << cache.get(1) << "\n";  // returns 1
    cache.put(3, 3);
    cout << "get(2) -> " << cache.get(2) << "\n";  // returns -1
    cache.put(4, 4);
    cout << "get(1) -> " << cache.get(1) << "\n";  // returns -1
    cout << "get(3) -> " << cache.get(3) << "\n";  // returns 3
    cout << "get(4) -> " << cache.get(4) << "\n";  // returns 4
}

/*
Time Complexity: O(1) per operation
Space Complexity: O(capacity)
*/
