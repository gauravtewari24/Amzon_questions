#include <bits/stdc++.h>
using namespace std;
const int N = 6;
const int M = 6;

void flood_fill(char mat[][N], int x, int y, int lastCh, int newCh)
{
    if (x >= N || x < 0 || y >= M || y < 0)
        return;

    if (lastCh != mat[x][y])
        return;

    mat[x][y] = newCh;

    flood_fill(mat, x + 1, y, lastCh, newCh);
    flood_fill(mat, x - 1, y, lastCh, newCh);
    flood_fill(mat, x, y + 1, lastCh, newCh);
    flood_fill(mat, x, y - 1, lastCh, newCh);
}

void replaceSurrounded(char mat[][M])
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mat[i][j] == 'O')
                mat[i][j] = '#';
        }
    }

    for (int i = 0; i < M; i++)
        if (mat[0][i] == '#')
            flood_fill(mat, 0, i, '#', 'O');

    for (int i = 0; i < N; i++)
        if (mat[i][0] == '#')
            flood_fill(mat, i, 0, '#', 'O');

    for (int i = 0; i < M; i++)
        if (mat[N - 1][i] == '#')
            flood_fill(mat, N - 1, i, '#', 'O');

    for (int i = 0; i < M; i++)
        if (mat[i][M - 1] == '#')
            flood_fill(mat, i, M - 1, '#', 'O');

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mat[i][j] == '#')
                mat[i][j] = 'X';
        }
    }
}

int main()
{
    char mat[][M] = {
        {'X', 'O', 'X', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'X'},
        {'O', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'O', 'X', 'O', 'O', 'O'},
    };
    replaceSurrounded(mat);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}