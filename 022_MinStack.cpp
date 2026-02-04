// Topic: Min Stack
// Description: Design stack supporting push, pop, top, and retrieving current minimum in O(1).
// Approach: Maintain main stack and stack of current minimums (or store paired values).

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    vector<pair<int, int>> st;  // {value, current_min}
   public:
    MinStack() {}
    void push(int x)
    {
        if (st.empty())
            st.emplace_back(x, x);
        else
            st.emplace_back(x, min(x, st.back().second));
    }
    void pop()
    {
        if (!st.empty())
            st.pop_back();
    }
    int top() const { return st.back().first; }
    int getMin() const { return st.back().second; }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Test scenario 1
    {
        MinStack ms;
        ms.push(-2);
        ms.push(0);
        ms.push(-3);
        cout << "Test 1: getMin -> " << ms.getMin() << "\n";  // expect -3
        ms.pop();
        cout << "Test 1: top -> " << ms.top() << "\n";        // expect 0
        cout << "Test 1: getMin -> " << ms.getMin() << "\n";  // expect -2
    }
    // Test scenario 2
    {
        MinStack ms;
        ms.push(2);
        ms.push(2);
        ms.pop();
        cout << "Test 2: top -> " << ms.top() << "\n";        // expect 2
        cout << "Test 2: getMin -> " << ms.getMin() << "\n";  // expect 2
    }
}

/*
Time Complexity: O(1) per operation
Space Complexity: O(n)
*/
