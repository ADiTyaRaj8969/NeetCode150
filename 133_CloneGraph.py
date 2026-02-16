# Topic: Clone Graph
# Description: Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.
# Approach: BFS clone using hashmap from original->copy.

from typing import Optional, Dict, List
from collections import deque


class Node:
    def __init__(self, val: int = 0, neighbors: List['Node'] = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: Optional[Node]) -> Optional[Node]:
        if not node:
            return None
        cloned: Dict[Node, Node] = {}
        queue = deque([node])
        cloned[node] = Node(node.val)
        while queue:
            cur = queue.popleft()
            for nei in cur.neighbors:
                if nei not in cloned:
                    cloned[nei] = Node(nei.val)
                    queue.append(nei)
                cloned[cur].neighbors.append(cloned[nei])
        return cloned[node]


def build_graph(adj_list: List[List[int]]) -> Optional[Node]:
    if not adj_list:
        return None
    n = len(adj_list)
    nodes = [Node(i + 1) for i in range(n)]
    for i, neighbors in enumerate(adj_list):
        for j in neighbors:
            nodes[i].neighbors.append(nodes[j - 1])
    return nodes[0]


if __name__ == "__main__":
    tests = [[[2, 4], [1, 3], [2, 4], [1, 3]], [[]], []]
    for i, adj in enumerate(tests):
        original = build_graph(adj) if adj else None
        cloned = Solution().cloneGraph(original)
        print(f"Test {i + 1}: {'Cloned' if cloned else 'None'}")

"""
Time Complexity: O(N + E)
Space Complexity: O(N)
"""
