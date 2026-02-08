// Topic: Word Ladder
// Description: Given beginWord, endWord, and a dictionary, return length of shortest transformation
// sequence. Approach: BFS over words using generic transformations, O(N * L^2) naive.

#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord))
        return 0;
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    unordered_set<string> seen;
    seen.insert(beginWord);
    while (!q.empty())
    {
        auto [w, d] = q.front();
        q.pop();
        if (w == endWord)
            return d;
        string cur = w;
        for (size_t i = 0; i < cur.size(); ++i)
        {
            char old = cur[i];
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (c == old)
                    continue;
                cur[i] = c;
                if (dict.count(cur) && !seen.count(cur))
                {
                    seen.insert(cur);
                    q.push({cur, d + 1});
                }
            }
            cur[i] = old;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<tuple<string, string, vector<string>>> tests = {
        {"hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}},
        {"hit", "cog", {"hot", "dot", "dog", "lot", "log"}}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": "
             << ladderLength(get<0>(tests[i]), get<1>(tests[i]), get<2>(tests[i])) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(N * L * 26) where L is word length
Space Complexity: O(N)
*/
