# Topic: Number of Connected Components in an Undirected Graph
# Description: Given n nodes and edge list, count connected components. Use Union-Find or DFS.
# Approach: Union-Find (disjoint set) for near-linear performance.

from typing import List


class DSU:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def unite(self, a: int, b: int) -> None:
        a, b = self.find(a), self.find(b)
        if a == b:
            return
        if self.rank[a] < self.rank[b]:
            a, b = b, a
        self.parent[b] = a
        if self.rank[a] == self.rank[b]:
            self.rank[a] += 1


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        dsu = DSU(n)
        for a, b in edges:
            dsu.unite(a, b)
        return len(set(dsu.find(i) for i in range(n)))


if __name__ == "__main__":
    tests = [(4, [[0, 1], [2, 3]]), (5, [[0, 1], [1, 2], [3, 4]]), (3, [])]
    for i, (n, edges) in enumerate(tests):
        print(f"Test {i + 1}: {Solution().countComponents(n, edges)}")

"""
Time Complexity: near O(n + m * alpha(n))
Space Complexity: O(n)
"""
