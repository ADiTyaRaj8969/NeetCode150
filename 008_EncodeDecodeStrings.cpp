// Topic: Encode and Decode Strings
// Description: Serialize and deserialize a list of strings efficiently.
// Approach: Use length-prefix encoding with delimiter-free representation.

#include <bits/stdc++.h>
using namespace std;

class Codec
{
   public:
    string encode(const vector<string>& strs)
    {
        string out;
        for (const auto& s : strs)
        {
            out += to_string(s.size());
            out.push_back('#');
            out += s;
        }
        return out;
    }

    vector<string> decode(const string& s)
    {
        vector<string> res;
        size_t i = 0, n = s.size();
        while (i < n)
        {
            size_t j = i;
            while (j < n && s[j] != '#') ++j;
            int len = stoi(s.substr(i, j - i));
            j++;  // skip '#'
            res.emplace_back(s.substr(j, len));
            i = j + len;
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<string>> tests = {{"hello", "world"}, {"", "#", "abc"}};
    Codec codec;
    for (size_t t = 0; t < tests.size(); ++t)
    {
        cout << "Test " << (t + 1) << ": ";
        for (size_t i = 0; i < tests[t].size(); ++i)
        {
            if (i)
                cout << ",";
            cout << "\"" << tests[t][i] << "\"";
        }
        cout << "\n";
        string enc = codec.encode(tests[t]);
        auto dec = codec.decode(enc);
        cout << "Decoded:\n";
        for (auto& x : dec) cout << x << "\n";
        cout << "\n";
    }
}

/*
Time Complexity: O(total length of strings)
Space Complexity: O(total length) for encoded string
*/
