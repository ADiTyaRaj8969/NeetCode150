// Topic: LRU Cache
// Description: Design and implement a data structure for Least Recently Used (LRU) cache.
// Approach: Use a doubly-linked list (std::list) to store keys in recency order and an
// unordered_map from key to (value, iterator).

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    int cap;
    list<int> order;                                        // most recent at front
    unordered_map<int, pair<int, list<int>::iterator>> mp;  // key -> (value, iterator)
   public:
    LRUCache(int capacity) : cap(capacity) {}
    int get(int key)
    {
        auto it = mp.find(key);
        if (it == mp.end())
            return -1;
        order.erase(it->second.second);
        order.push_front(key);
        it->second.second = order.begin();
        return it->second.first;
    }
    void put(int key, int value)
    {
        auto it = mp.find(key);
        if (it != mp.end())
        {
            order.erase(it->second.second);
            order.push_front(key);
            it->second = {value, order.begin()};
            return;
        }
        if ((int)mp.size() == cap)
        {
            int old = order.back();
            order.pop_back();
            mp.erase(old);
        }
        order.push_front(key);
        mp[key] = {value, order.begin()};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Embedded tests
    cout << "Test 1: ops on capacity 2" << "\n";
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << "get(1) -> " << cache.get(1) << "\n";  // returns 1
    cache.put(3, 3);                               // evicts key 2
    cout << "get(2) -> " << cache.get(2) << "\n";  // returns -1
    cache.put(4, 4);                               // evicts key 1
    cout << "get(1) -> " << cache.get(1) << "\n";  // returns -1
    cout << "get(3) -> " << cache.get(3) << "\n";  // returns 3
    cout << "get(4) -> " << cache.get(4) << "\n";  // returns 4
}

/*
Time Complexity: O(1) average per operation
Space Complexity: O(capacity)
*/
