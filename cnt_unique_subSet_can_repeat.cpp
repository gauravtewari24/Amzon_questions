#include <bits/stdc++.h>
using namespace std;

// Function to find number of unique subsets

// If an element x appears freq[x] times, then in a subset, it can appear:
// 0 times, 1 time, 2 times, ..., freq[x] times( obciously like [1,2,2]-> 2 cannot appear in subset, appearince and appear twice.)
// So it gives us freq[x] + 1 choices for how many times to include x in a subset.

void countNumberofUniqueSubsets(int A[], int N)
{
    map<int, int> m;

    // Count frequency of each element
    for (int i = 0; i < N; i++)
    {
        m[A[i]]++;
    }

    // Multiply (frequency + 1) for each element
    int subsets = 1;

    for (auto &value : m)
        subsets *= (value.second + 1);

    cout << subsets;
}
