#include <bits/stdc++.h>
using namespace std;

// bruteforce -- divide factorial by 10 till the remainder is 0.
int main()
{
    int n = 28;

    int cnt5 = 0;

    for (int i = 5; n / i >= 1; i *= 5)
    {
        cnt5 += (n / i);
    }
    cout << cnt5;
}