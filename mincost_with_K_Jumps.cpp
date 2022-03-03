#include <bits/stdc++.h>
using namespace std;
int n = 6, k = 1, dp[10] = {0};
int mincost(vector<int> v, int cur)
{
    if (cur >= n)
        return INT_MAX;
    if (cur == n - 1)
        return v[n - 1];

    // if(dp[cur])
    //  return dp[cur];
    int mini = INT_MAX;
    int cost = 0;
    for (int i = 1; i < 3; i++)
    {
        int temp = mincost(v, cur + i);
        mini = min(temp, mini);
    }

    return v[cur] + max(mini, 0);
    // dp[cur]
}
int main()
{
    vector<int> v = {9, 4, 9, 7, 8, 5};
    // dp[0] = v[0];
    cout << mincost(v, 0);
}