# Topic: Combination Sum
# Description: Return combinations summing to target, reuse numbers allowed.
# Approach: Backtracking with candidates sorted to prune branches.

from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        result = []
        cur = []

        def dfs(idx, remaining):
            if remaining == 0:
                result.append(cur[:])
                return
            for i in range(idx, len(candidates)):
                if candidates[i] > remaining:
                    break
                cur.append(candidates[i])
                dfs(i, remaining - candidates[i])
                cur.pop()

        dfs(0, target)
        return result


if __name__ == "__main__":
    cand = [2, 3, 6, 7]
    target = 7
    result = Solution().combinationSum(cand, target)
    for v in result:
        print(v)

"""
Time Complexity: Depends on branching; in worst-case exponential
Space Complexity: O(target / min(candidates)) recursion depth
"""
