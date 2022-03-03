#include <bits/stdc++.h>
using namespace std;

int fun(int sum)
{
    if (sum < 0)
        return 0;
    if (sum == 0)
        return 1;

    int maxi = max(max(fun(sum - 1), fun(sum - 2)), fun(sum - 5));
    return maxi;
}
int count(vector<int> const &S, int target)
{
    // if the total is 0, return 1
    if (target == 0)
    {
        return 1;
    }

    // return 0 if total becomes negative
    if (target < 0)
    {
        return 0;
    }

    // initialize the total number of ways to 0
    int result = 0;

    // do for each coin
    for (int c : S)
    {
        // recur to see if total can be reached by including current coin `c`
        result += count(S, target - c);
    }

    // return the total number of ways
    return result;
}

int main()
{
    vector<int> const S = {1, 2, 5};
    cout << count(S, 7);
}