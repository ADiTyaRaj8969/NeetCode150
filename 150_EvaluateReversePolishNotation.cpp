// Topic: Evaluate Reverse Polish Notation
// Description: Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Approach: Use a stack to process tokens (numbers or operators).

#include <bits/stdc++.h>
using namespace std;

int evalRPN(const vector<string>& tokens)
{
    stack<long long> st;
    for (const string& t : tokens)
    {
        if (t == "+" || t == "-" || t == "*" || t == "/")
        {
            long long b = st.top();
            st.pop();
            long long a = st.top();
            st.pop();
            if (t == "+")
                st.push(a + b);
            else if (t == "-")
                st.push(a - b);
            else if (t == "*")
                st.push(a * b);
            else if (t == "/")
                st.push(a / b);
        }
        else
        {
            st.push(stoll(t));
        }
    }
    return (int)st.top();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<string>> tests = {
        {"2", "1", "+", "3", "*"},   // (2+1)*3 = 9
        {"4", "13", "5", "/", "+"},  // 4 + (13/5) = 6
        {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": ";
        for (size_t j = 0; j < tests[i].size(); ++j)
        {
            if (j)
                cout << ",";
            cout << tests[i][j];
        }
        cout << " -> " << evalRPN(tests[i]) << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
