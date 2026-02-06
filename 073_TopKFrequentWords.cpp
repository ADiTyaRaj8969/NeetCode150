// Topic: Top K Frequent Words
// Description: Given a list of words, return the k most frequent words. If frequencies tie, return
// lexicographically smaller first. Approach: Count frequencies with unordered_map, then use vector
// + sort with custom comparator (or min-heap). Here we sort the unique words by freq desc, then
// lexicographically.

#include <bits/stdc++.h>
using namespace std;

vector<string> topKFrequent(vector<string>& words, int k)
{
    unordered_map<string, int> cnt;
    for (auto& w : words) cnt[w]++;
    vector<string> uniq;
    uniq.reserve(cnt.size());
    for (auto& p : cnt) uniq.push_back(p.first);
    sort(uniq.begin(), uniq.end(),
         [&](const string& a, const string& b)
         {
             if (cnt[a] != cnt[b])
                 return cnt[a] > cnt[b];
             return a < b;
         });
    if ((int)uniq.size() > k)
        uniq.resize(k);
    return uniq;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    auto ans = topKFrequent(words, 2);
    for (auto& s : ans) cout << s << "\n";
}

/*
Time Complexity: O(m log m) where m = number of unique words (plus O(n) to count)
Space Complexity: O(m)
*/
