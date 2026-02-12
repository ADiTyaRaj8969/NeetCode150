# Topic: Implement Trie (Prefix Tree)
# Description: Design prefix tree supporting insert, search, and startsWith operations.
# Approach: Standard trie using dict of children.


class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_end = True

    def search(self, word: str) -> bool:
        node = self.root
        for ch in word:
            if ch not in node.children:
                return False
            node = node.children[ch]
        return node.is_end

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for ch in prefix:
            if ch not in node.children:
                return False
            node = node.children[ch]
        return True


if __name__ == "__main__":
    trie = Trie()
    trie.insert("apple")
    print(f"search(apple) -> {trie.search('apple')}")
    print(f"search(app) -> {trie.search('app')}")
    print(f"startsWith(app) -> {trie.startsWith('app')}")
    trie.insert("app")
    print(f"search(app) -> {trie.search('app')}")

"""
Time Complexity: insert/search/startsWith O(L) where L is word length
Space Complexity: O(total characters stored)
"""
