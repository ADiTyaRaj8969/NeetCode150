# Topic: Group Anagrams
# Description: Group words that contain the same letters in different orders.
# Approach: Use sorted string as key or character count key. Use dictionary to group.

from typing import List
from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)
        for s in strs:
            key = ''.join(sorted(s))
            mp[key].append(s)
        return list(mp.values())


if __name__ == "__main__":
    tests = [["eat", "tea", "tan", "ate", "nat", "bat"], [""]]
    sol = Solution()
    for i, test in enumerate(tests):
        print(f"Test {i + 1}: {test}")
        print("Groups:")
        result = sol.groupAnagrams(test)
        for group in result:
            print(' '.join(group))
        print()

"""
Time Complexity: O(N * L log L) where N is number of strings and L is avg length (due to sorting)
Space Complexity: O(N * L)
"""
