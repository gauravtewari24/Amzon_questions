#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    int platform[2361] = {0};

    for (int i = 0; i < n; i++)
    {
        platform[arr[i]]++;

        platform[dep[i] + 1]--;
    }
    int ans = 0, temp = 0;
    for (int i = 0; i < 2361; i++)
    {
        temp += platform[i];
        ans = max(ans, temp);
    }
    cout << ans;
}