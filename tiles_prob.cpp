int dp[100] = {0};
int find_ways(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (dp[n])
        return dp[n];

    return dp[n] = find_ways(n - 1) + find_ways(n - 2);
}
