#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    if (grid.empty())
        return -1;

    queue<pair<int, int>> rotten;
    int CountOneTwo = 0, n = grid.size(), m = grid[0].size();
    int minutes = 0, cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0)
                CountOneTwo++;

            if (grid[i][j] == 2)
            {
                rotten.push({i, j});
            }
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!rotten.empty())
    {
        int sz = rotten.size();
        cnt += sz;

        for (int i = 0; i < sz; i++)
        {
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                    continue;

                grid[nx][ny] = 2;
                rotten.push({nx, ny});
            }
        }
        if (!rotten.empty())
            minutes++;
    }

    if (cnt == CountOneTwo)
        return minutes;

    return -1;
    // Code here
}

// Driver code
int main()
{
    vector<vector<int>> grid = {{2, 1, 0, 2, 1},

                                {1, 0, 1, 2, 1},

                                {1, 0, 0, 2, 1}};

    cout << orangesRotting(grid);
}