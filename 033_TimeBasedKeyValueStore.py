# Topic: Time Based Key-Value Store
# Description: Design structure supporting timestamped key-value retrievals.
# Approach: For each key keep sorted list of (time, value) and binary search for floor timestamp.

from collections import defaultdict
import bisect


class TimeMap:
    def __init__(self):
        self.store = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.store[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.store:
            return ""
        arr = self.store[key]
        # Binary search for largest timestamp <= given timestamp
        idx = bisect.bisect_right(arr, (timestamp, chr(127))) - 1
        if idx < 0:
            return ""
        return arr[idx][1]


if __name__ == "__main__":
    tm = TimeMap()
    tm.set("foo", "bar", 1)
    print(f"Test 1: get(foo,1) -> {tm.get('foo', 1)}")  # bar
    print(f"Test 1: get(foo,3) -> {tm.get('foo', 3)}")  # bar
    tm.set("foo", "bar2", 4)
    print(f"Test 1: get(foo,4) -> {tm.get('foo', 4)}")  # bar2
    print(f"Test 1: get(foo,5) -> {tm.get('foo', 5)}")  # bar2

"""
Time Complexity: set O(1) amortized, get O(log n_k) for key's list size
Space Complexity: O(total entries)
"""
