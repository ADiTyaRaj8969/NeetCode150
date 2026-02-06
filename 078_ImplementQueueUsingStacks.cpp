// Topic: Implement Queue using Stacks
// Description: Implement a queue with push, pop, peek, and empty using two stacks.
// Approach: Use two stacks, 'in' for pushing and 'out' for popping. Amortized O(1) per operation.

#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
    stack<int> in, out;
    void moveInToOut()
    {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
    }

   public:
    MyQueue() {}
    void push(int x) { in.push(x); }
    int pop()
    {
        moveInToOut();
        int v = out.top();
        out.pop();
        return v;
    }
    int peek()
    {
        moveInToOut();
        return out.top();
    }
    bool empty() { return in.empty() && out.empty(); }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<pair<string, int>>> tests = {
        {{"push", 1}, {"push", 2}, {"push", 3}, {"pop", 0}, {"pop", 0}, {"pop", 0}},
        {{"push", 10}, {"peek", 0}, {"pop", 0}, {"empty", 0}},
        {{"push", 5}, {"pop", 0}}};

    for (int t = 0; t < (int)tests.size(); ++t)
    {
        MyQueue q;
        cout << "Test " << (t + 1) << ": ";
        for (auto& op : tests[t])
        {
            if (op.first == "push")
                q.push(op.second);
            else if (op.first == "pop")
                cout << q.pop() << ' ';
            else if (op.first == "peek")
                cout << q.peek() << ' ';
            else if (op.first == "empty")
                cout << (q.empty() ? 1 : 0) << ' ';
        }
        cout << '\n';
    }

    return 0;
}

/*
Time Complexity: Amortized O(1) per operation
Space Complexity: O(n)
*/
