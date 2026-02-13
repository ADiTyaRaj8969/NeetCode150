# Topic: Merge Intervals
# Description: Given a collection of intervals, merge all overlapping intervals.
# Approach: Sort intervals by start, then iterate and merge when overlapping.

from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        intervals.sort(key=lambda x: x[0])
        result = [intervals[0]]
        for start, end in intervals[1:]:
            if start <= result[-1][1]:
                result[-1][1] = max(result[-1][1], end)
            else:
                result.append([start, end])
        return result


if __name__ == "__main__":
    intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
    result = Solution().merge(intervals)
    print(result)

"""
Time Complexity: O(n log n) due to sorting
Space Complexity: O(n) for output
"""
