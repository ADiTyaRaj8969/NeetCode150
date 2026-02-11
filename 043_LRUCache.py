# Topic: LRU Cache
# Description: Design a cache supporting get and put in O(1) time with LRU eviction.
# Approach: Use dict for key->node and doubly-linked list (OrderedDict) to maintain recency.

from collections import OrderedDict


class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.cap:
            self.cache.popitem(last=False)


if __name__ == "__main__":
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    print(f"get(1) -> {cache.get(1)}")   # 1
    cache.put(3, 3)
    print(f"get(2) -> {cache.get(2)}")   # -1
    cache.put(4, 4)
    print(f"get(1) -> {cache.get(1)}")   # -1
    print(f"get(3) -> {cache.get(3)}")   # 3
    print(f"get(4) -> {cache.get(4)}")   # 4

"""
Time Complexity: O(1) per operation
Space Complexity: O(capacity)
"""
