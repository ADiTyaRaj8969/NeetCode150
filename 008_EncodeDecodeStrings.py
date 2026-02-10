# Topic: Encode and Decode Strings
# Description: Serialize and deserialize a list of strings efficiently.
# Approach: Use length-prefix encoding with delimiter-free representation.

from typing import List


class Codec:
    def encode(self, strs: List[str]) -> str:
        out = ""
        for s in strs:
            out += str(len(s)) + '#' + s
        return out

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        n = len(s)
        while i < n:
            j = i
            while j < n and s[j] != '#':
                j += 1
            length = int(s[i:j])
            j += 1  # skip '#'
            res.append(s[j:j + length])
            i = j + length
        return res


if __name__ == "__main__":
    tests = [["hello", "world"], ["", "#", "abc"]]
    codec = Codec()
    for i, test in enumerate(tests):
        print(f"Test {i + 1}: {test}")
        enc = codec.encode(test)
        dec = codec.decode(enc)
        print("Decoded:")
        for x in dec:
            print(x)
        print()

"""
Time Complexity: O(total length of strings)
Space Complexity: O(total length) for encoded string
"""
