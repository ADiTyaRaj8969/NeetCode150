# Topic: Course Schedule
# Description: Given numCourses and prerequisites pairs, determine if you can finish all courses
#              (i.e., no cycle in graph).
# Approach: Detect cycle using DFS (colors) or Kahn's BFS topological sort. Using DFS coloring.

from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        for course, prereq in prerequisites:
            adj[prereq].append(course)
        color = [0] * numCourses  # 0=unvisited, 1=visiting, 2=visited

        def has_cycle(u: int) -> bool:
            color[u] = 1
            for v in adj[u]:
                if color[v] == 1:
                    return True
                if color[v] == 0 and has_cycle(v):
                    return True
            color[u] = 2
            return False

        for i in range(numCourses):
            if color[i] == 0:
                if has_cycle(i):
                    return False
        return True


if __name__ == "__main__":
    tests = [(2, [[1, 0]]), (2, [[1, 0], [0, 1]]), (3, [[1, 0], [2, 1]])]
    for i, (num, prereq) in enumerate(tests):
        print(f"Test {i + 1}: {Solution().canFinish(num, prereq)}")

"""
Time Complexity: O(V+E)
Space Complexity: O(V+E)
"""
