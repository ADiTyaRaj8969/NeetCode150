// Topic: Pow(x, n)
// Description: Implement pow(x, n) to compute x raised to the power n (n can be negative).
// Approach: Fast exponentiation (binary exponentiation). Handle negative exponent by reciprocal.

#include <bits/stdc++.h>
using namespace std;

double myPow(double x, long long n)
{
    if (n == 0)
        return 1.0;
    double res = 1.0;
    long long exp = llabs(n);
    while (exp > 0)
    {
        if (exp & 1)
            res *= x;
        x *= x;
        exp >>= 1;
    }
    return n < 0 ? 1.0 / res : res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<double, long long>> tests = {{2.00000, 10}, {2.10000, 3}, {2.00000, -2}};

    cout.setf(std::ios::fixed);
    for (int i = 0; i < (int)tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": ";
        cout << setprecision(10) << myPow(tests[i].first, tests[i].second) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(log |n|)
Space Complexity: O(1)
*/
