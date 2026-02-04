// Topic: Median of Two Sorted Arrays
// Description: Find median from two individually sorted arrays.
// Approach: Binary search on partition in smaller array; O(log(min(m,n))).

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(const vector<int>& A, const vector<int>& B)
{
    const vector<int>*a = &A, *b = &B;
    if (A.size() > B.size())
        swap(a, b);
    int m = a->size(), n = b->size();
    int imin = 0, imax = m;
    int half = (m + n + 1) / 2;
    while (imin <= imax)
    {
        int i = (imin + imax) / 2;
        int j = half - i;
        int aleft = (i == 0) ? INT_MIN : (*a)[i - 1];
        int aright = (i == m) ? INT_MAX : (*a)[i];
        int bleft = (j == 0) ? INT_MIN : (*b)[j - 1];
        int bright = (j == n) ? INT_MAX : (*b)[j];
        if (aleft <= bright && bleft <= aright)
        {
            if ((m + n) % 2 == 1)
                return max(aleft, bleft);
            return (max(aleft, bleft) + min(aright, bright)) / 2.0;
        }
        else if (aleft > bright)
        {
            imax = i - 1;
        }
        else
            imin = i + 1;
    }
    return 0.0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> A1 = {1, 3}, B1 = {2};
    vector<int> A2 = {1, 2}, B2 = {3, 4};
    cout << "Test 1 -> " << fixed << setprecision(5) << findMedianSortedArrays(A1, B1) << "\n";
    cout << "Test 2 -> " << fixed << setprecision(5) << findMedianSortedArrays(A2, B2) << "\n";
}

/*
Time Complexity: O(log(min(m,n)))
Space Complexity: O(1)
*/
