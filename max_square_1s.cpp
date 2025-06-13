#include <bits/stdc++.h>
using namespace std;

// basically build a dp with n and m that is one extra row and column.
// if matrix val is 0 then dp is 0;
// else check min(right, down, rightDown) and plus 1 assign to dp;
// keep checking ans with max.
int maxSquare(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    int ans = 0;

    // Create 2d array for tabulation
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the dp
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            // If square cannot be formed
            if (mat[i][j] == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = 1 + min({dp[i][j + 1],
                                dp[i + 1][j], dp[i + 1][j + 1]});

            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> mat =
        {{0, 1, 1, 0, 1},
         {1, 1, 0, 1, 0},
         {0, 1, 1, 1, 0},
         {1, 1, 1, 1, 0},
         {1, 1, 1, 1, 1},
         {0, 0, 0, 0, 0}};
    cout << maxSquare(mat) << endl;

    return 0;
}