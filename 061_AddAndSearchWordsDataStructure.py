# Topic: Design Add and Search Words Data Structure
# Description: Trie that supports inserting words and searching with '.' wildcard which can match any letter.
# Approach: Standard Trie with recursive search supporting wildcard; insert in O(L), search worst-case O(26^L) for wildcards.


class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False


class WordDictionary:
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_end = True

    def search(self, word: str) -> bool:
        def dfs(node, idx):
            if not node:
                return False
            if idx == len(word):
                return node.is_end
            c = word[idx]
            if c == '.':
                for child in node.children.values():
                    if dfs(child, idx + 1):
                        return True
                return False
            else:
                return dfs(node.children.get(c), idx + 1)

        return dfs(self.root, 0)


if __name__ == "__main__":
    wd = WordDictionary()
    wd.addWord("bad")
    wd.addWord("dad")
    wd.addWord("mad")
    print(f"search(bad) -> {wd.search('bad')}")
    print(f"search(.ad) -> {wd.search('.ad')}")
    print(f"search(b..) -> {wd.search('b..')}")

"""
Time Complexity: add O(L), search O(L * branching) worst-case with wildcards
Space Complexity: O(total characters stored)
"""
