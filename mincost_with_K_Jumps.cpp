// max k index jumsps are allowed and find min cost also.
// we have done ki first consider 1 gap recursion with i=1 and inside its recursively might take next

// v = {9, 4, 9, 7, 8, 5}; and k =2;in this ike if we assume 7 is the last in, then
// start from 9,and it can take one step to 4 and also 2 steps to 9 and similary depenidng on jump k
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
    for (int i = 1; i <= k; i++)
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