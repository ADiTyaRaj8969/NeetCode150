// Topic: Evaluate Reverse Polish Notation
// Description: Compute arithmetic expression written in postfix notation.
// Approach: Use stack to evaluate tokens; support + - * / (integer division trunc toward zero)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int evalRPN(vector<string>& tokens)
    {
        stack<long long> st;
        for (auto& tok : tokens)
        {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/")
            {
                long long b = st.top();
                st.pop();
                long long a = st.top();
                st.pop();
                if (tok == "+")
                    st.push(a + b);
                else if (tok == "-")
                    st.push(a - b);
                else if (tok == "*")
                    st.push(a * b);
                else
                    st.push(a / b);
            }
            else
                st.push(stoll(tok));
        }
        return (int)st.top();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<string>> tests = {{"2", "1", "+", "3", "*"}, {"4", "13", "5", "/", "+"}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        auto tokens = tests[i];
        cout << "Test " << (i + 1) << ": ";
        for (size_t j = 0; j < tokens.size(); ++j)
        {
            if (j)
                cout << " ";
            cout << tokens[j];
        }
        cout << " -> " << Solution().evalRPN(tokens) << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
