# Topic: LRU Cache
# Description: Design and implement a data structure for Least Recently Used (LRU) cache.
# Approach: Use OrderedDict to maintain insertion order; move to end on access.

from collections import OrderedDict


class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
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
            return
        if len(self.cache) >= self.capacity:
            self.cache.popitem(last=False)
        self.cache[key] = value


if __name__ == "__main__":
    print("Test 1: ops on capacity 2")
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    print(f"get(1) -> {cache.get(1)}")  # returns 1
    cache.put(3, 3)  # evicts key 2
    print(f"get(2) -> {cache.get(2)}")  # returns -1
    cache.put(4, 4)  # evicts key 1
    print(f"get(1) -> {cache.get(1)}")  # returns -1
    print(f"get(3) -> {cache.get(3)}")  # returns 3
    print(f"get(4) -> {cache.get(4)}")  # returns 4

"""
Time Complexity: O(1) average per operation
Space Complexity: O(capacity)
"""
