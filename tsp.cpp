#include <bits/stdc++.h>

using namespace std;

int vis[100001];
int v[10001][10001] = {0};
/*
int v[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}}; */
int n = 4;
int VISITED_ALL = (1 << n) - 1;

int dp[10001][10001];

int tsp(int mask, int pos)
{
    if (mask == VISITED_ALL)
    {
        return v[pos][0];
    }

    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }
    int ans = INT_MAX;
    for (int city = 0; city < n; city++)
    {

        if ((mask & (1 << city)) == 0)
        {
            int temp = v[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, temp);
        }
    }

    return dp[mask][pos] = ans;
}

int main()
{

    int m, k;
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a][b] = c;
        v[b][a] = c;
    }

    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    }

    cout << tsp(1, 0);
}