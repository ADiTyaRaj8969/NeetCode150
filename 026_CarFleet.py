# Topic: Car Fleet
# Description: Count fleets reaching destination given speed and position.
# Approach: Sort cars by position descending and compute arrival times; a car forms new fleet only if its time > previous fleet time.

from typing import List


class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = sorted(zip(position, speed), reverse=True)
        last = -1.0
        fleets = 0
        for pos, spd in cars:
            time = (target - pos) / spd
            if time > last:
                fleets += 1
                last = time
        return fleets


if __name__ == "__main__":
    # Test 1
    target = 12
    pos = [10, 8, 0, 5, 3]
    sp = [2, 4, 1, 1, 3]
    print(f"Test 1: target=12 -> {Solution().carFleet(target, pos, sp)}")  # expect 3

    # Test 2
    target = 10
    pos = [3, 5, 7]
    sp = [3, 2, 1]
    print(f"Test 2: target=10 -> {Solution().carFleet(target, pos, sp)}")

"""
Time Complexity: O(n log n) for sorting
Space Complexity: O(n)
"""
