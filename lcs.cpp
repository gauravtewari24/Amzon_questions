#include <bits/stdc++.h>

using namespace std;

int lcs_naive(string X, string Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs_naive(X, Y, m - 1, n - 1);
    else
        return max(lcs_naive(X, Y, m, n - 1), lcs_naive(X, Y, m - 1, n));
}

int lcs(string &X, string &Y)
{
    int m = X.length(), n = Y.length();
    int L[m + 1][n + 1];

    /* Following steps build L[m+1][n+1] in bottom up
       fashion. Note that L[i][j] contains length of
       LCS of X[0..i-1] and Y[0..j-1] */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    /* L[m][n] contains length of LCS for X[0..n-1] and
       Y[0..m-1] */
    return L[m][n];
}

int main()
{
    string x = "GXTXAYB";
    string y = "GTAB";
    cout << lcs_naive(x, y, x.length(), y.length());
}