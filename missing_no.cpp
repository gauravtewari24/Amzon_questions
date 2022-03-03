#include <bits/stdc++.h>
using namespace std;

int getMissingNo1(int a[], int n)
{

    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++)
        total -= a[i];
    return total;
}

int getMissingNo(int a[], int n)
{
    // Assume a1 ^ a2 ^ a3 ^ …^ an = a and a1 ^ a2 ^ a3 ^ …^ an-1 = b
    // Then a ^ b = an

    // For xor of all the elements in array
    int x1 = a[0];

    // For xor of all the elements from 1 to n+1
    int x2 = a[0];
    int mini = *min_element(a, a + n);

    int maxi = *max_element(a, a + n);

    for (int i = 1; i < n; i++)
        x1 = x1 ^ a[i];

    for (int i = mini + 1; i <= maxi; i++)
        x2 = x2 ^ i;

    return (x1 ^ x2);
}

int main()
{
    int a[] = {2, 3, 4, 5, 9, 6, 8, 7, 11};
    int n = 9;
    cout << getMissingNo(a, n);
    // cout << miss;
}