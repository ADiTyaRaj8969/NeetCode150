# Topic: Clone Graph
# Description: Given a reference to a node in an undirected graph, return a deep copy of the graph.
# Approach: BFS/DFS with hashmap to clone nodes.

from typing import Optional, List, Dict
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


def build_graph(adj: List[List[int]]) -> Optional[Node]:
    if not adj:
        return None
    n = len(adj)
    nodes = [Node(i) for i in range(n)]
    for i, neighbors in enumerate(adj):
        for v in neighbors:
            nodes[i].neighbors.append(nodes[v])
    return nodes[0]


def graph_to_adj(node: Optional[Node]) -> Dict[int, List[int]]:
    if not node:
        return {}
    result = {}
    seen = set()
    queue = deque([node])
    seen.add(node)
    while queue:
        cur = queue.popleft()
        result[cur.val] = [nei.val for nei in cur.neighbors]
        for nei in cur.neighbors:
            if nei not in seen:
                seen.add(nei)
                queue.append(nei)
    return result


if __name__ == "__main__":
    tests = [[[1, 2], [2], [0]], [[1], [], []], [[]]]
    for i, adj in enumerate(tests):
        original = build_graph(adj)
        cloned = Solution().cloneGraph(original)
        print(f"Test {i + 1}: {graph_to_adj(cloned)}")

"""
Time Complexity: O(N + E)
Space Complexity: O(N)
"""
