#include <bits/stdc++.h>
using namespace std;

int UniquePathHelper(int i, int j, int r, int c,
                     vector<vector<int>> &A,
                     vector<vector<int>> &paths)
{
    // boundary condition or constraints
    if (i == r || j == c)
    {
        return 0;
    }

    if (A[i][j] == 1)
    {
        return 0;
    }

    // base case
    if (i == r - 1 && j == c - 1)
    {
        return 1;
    }

    if (paths[i][j] != -1)
    {
        return paths[i][j];
    }

    return paths[i][j] = UniquePathHelper(i + 1, j, r, c, A, paths) + UniquePathHelper(i, j + 1, r, c, A, paths);
}

int uniquePathsWithObstacles(vector<vector<int>> &A)
{

    int r = A.size(), c = A[0].size();

    // create a 2D-matrix and initializing
    // with value 0

    vector<vector<int>> paths(r, vector<int>(c, -1));

    return UniquePathHelper(0, 0, r, c, A, paths);
}

// Driver code
int main()
{
    vector<vector<int>> A = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};

    cout << uniquePathsWithObstacles(A) << " \n";
}