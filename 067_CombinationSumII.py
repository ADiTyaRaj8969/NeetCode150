# Topic: Combination Sum II
# Description: Return unique combinations summing to target where each number may be used once.
# Approach: Sort candidates and backtrack, skipping duplicates at the same recursion level.

from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        result = []
        cur = []

        def dfs(idx, remaining):
            if remaining == 0:
                result.append(cur[:])
                return
            for i in range(idx, len(candidates)):
                if i > idx and candidates[i] == candidates[i - 1]:
                    continue
                if candidates[i] > remaining:
                    break
                cur.append(candidates[i])
                dfs(i + 1, remaining - candidates[i])
                cur.pop()

        dfs(0, target)
        return result


if __name__ == "__main__":
    cand = [10, 1, 2, 7, 6, 1, 5]
    target = 8
    result = Solution().combinationSum2(cand, target)
    for v in result:
        print(v)

"""
Time Complexity: Exponential in worst case (depends on branching)
Space Complexity: O(n) recursion depth + output
"""
