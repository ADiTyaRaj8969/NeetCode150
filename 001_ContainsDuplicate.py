# Topic: Contains Duplicate
# Description: Check if any number appears more than once in the array.
# Approach: Use a hash set to detect duplicates in O(n) average time.

from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = set()
        for x in nums:
            if x in seen:
                return True  # already present
            seen.add(x)
        return False


if __name__ == "__main__":
    # Embedded tests
    tests = [[1, 2, 3, 1], [1, 2, 3], []]
    sol = Solution()
    for i, test in enumerate(tests):
        result = sol.containsDuplicate(test)
        print(f"Test {i + 1}: {test} -> {result}")

"""
Time Complexity: O(n) on average, where n is the number of elements (set add/lookup average O(1)).
Space Complexity: O(n) extra space for the set storing seen elements.
"""
