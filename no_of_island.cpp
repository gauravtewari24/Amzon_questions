// no of island in a matrix

#include <bits/stdc++.h>

using namespace std;

// nput: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]

bool vis[10001][10001];
int v[10001][10001];
int n, m;

bool isSafe(int i, int j)
{
    return (i < n) and (j < m) and (i >= 0) and (j >= 0) and (v[i][j] and !vis[i][j]);
}
void dfs(int i, int j)
{
    vis[i][j] = true;

    static int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int k = 0; k < 8; k++)
    {
        if (isSafe(i + dx[k], j + dy[k]))
        {
            dfs(i + dx[k], j + dy[k]);
        }
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));

    int k;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && v[i][j])
            {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count;
}
