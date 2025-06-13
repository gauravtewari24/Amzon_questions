#include <bits/stdc++.h>

using namespace std;
// this is point based graph, where we decide whether to take y axis or x axis to reach to next point.

int coverPoints(vector<array<int, 2>> v, int n)
{
    int count = 0;

    for (int i = 1; i < n; i++)
    {
        int dist = max(abs(v[i][0] - v[i - 1][0]), abs(v[i][1] - v[i - 1][1]));

        count += dist;
    }
    return count;
}

int main()
{
    // arr stores sequence of points
    // that are to be visited
    vector<array<int, 2>> v = {{4, 6}, {1, 2}, {4, 5}, {10, 12}};
    cout << coverPoints(v, 4);
}