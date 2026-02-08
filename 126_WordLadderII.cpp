// Topic: Word Ladder II
// Description: Find all shortest transformation sequences from beginWord to endWord.
// Approach: BFS to build distance map and adjacency (neighbors), then DFS backtracking to collect
// all shortest paths.

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
    unordered_set<string> dict(wordList.begin(), wordList.end());
    vector<vector<string>> res;
    if (!dict.count(endWord))
        return res;
    dict.insert(beginWord);

    // BFS to build distance map
    unordered_map<string, int> dist;
    queue<string> q;
    q.push(beginWord);
    dist[beginWord] = 0;
    while (!q.empty())
    {
        string w = q.front();
        q.pop();
        int d = dist[w];
        string cur = w;
        for (size_t i = 0; i < cur.size(); ++i)
        {
            char old = cur[i];
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (c == old)
                    continue;
                cur[i] = c;
                if (dict.count(cur) && !dist.count(cur))
                {
                    dist[cur] = d + 1;
                    q.push(cur);
                }
            }
            cur[i] = old;
        }
    }
    if (!dist.count(endWord))
        return res;

    // build adjacency only moving to words with dist+1
    function<void(const string&, vector<string>&)> dfs =
        [&](const string& word, vector<string>& path)
    {
        if (word == endWord)
        {
            res.push_back(path);
            return;
        }
        string cur = word;
        int d = dist[word];
        for (size_t i = 0; i < cur.size(); ++i)
        {
            char old = cur[i];
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (c == old)
                    continue;
                cur[i] = c;
                if (dist.count(cur) && dist[cur] == d + 1)
                {
                    path.push_back(cur);
                    dfs(cur, path);
                    path.pop_back();
                }
            }
            cur[i] = old;
        }
    };

    vector<string> path{beginWord};
    dfs(beginWord, path);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<tuple<string, string, vector<string>>> tests = {
        {"hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}}, {"a", "c", {"a", "b", "c"}}};

    for (int t = 0; t < (int)tests.size(); ++t)
    {
        string begin = get<0>(tests[t]);
        string end = get<1>(tests[t]);
        vector<string> list = get<2>(tests[t]);
        auto ans = findLadders(begin, end, list);
        cout << "Test " << (t + 1) << ":\n";
        for (auto& p : ans)
        {
            for (size_t i = 0; i < p.size(); ++i) cout << p[i] << (i + 1 == p.size() ? '\n' : ' ');
        }
        if (ans.empty())
            cout << "(no paths)\n";
    }
    return 0;
}

/*
Time Complexity: BFS + DFS; worst-case high, typically bounded by number of shortest paths
Space Complexity: O(N * L) for dictionary and recursion
*/
