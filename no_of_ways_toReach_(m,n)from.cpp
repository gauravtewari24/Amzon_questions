
#include <bits/stdc++.h>
using namespace std;

/* Driver code */
int numberOfPaths(int n, int m, int dp[4][4])
{
    if (n == 1 || m == 1)
    {
        return 1;
    }
    /*
        if (dp[n][m] != 0)
        {
            cout << "HI";
            return dp[n][m];
        }
        return dp[n][m] = numberOfPaths(n - 1, m, dp) + numberOfPaths(n, m - 1, dp); */
    if (dp[n][m] == 0)
        dp[n][m] = numberOfPaths(n - 1, m, dp) + numberOfPaths(n, m - 1, dp);

    return dp[n][m];
}
int main()
{
    int DP[4][4] = {0};
    memset(DP, 0, sizeof(DP));

    cout << numberOfPaths(3, 3, DP);

    return 0;
}