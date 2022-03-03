#include <bits/stdc++.h>
using namespace std;

int fun(string arr[], int costs[], int n)
{
    int res = -1;
    vector<pair<float, pair<int, int>>> v(n);

    for (int i = 0; i < n; i++)
    {
        float x = float(costs[i]) / float(arr[i].length());
        v.push_back(make_pair(x, make_pair(costs[i], arr[i].length())));
    }

    sort(v.rbegin(), v.rend());
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (len - v[i].second.second > 30)
            continue;
        else
        {
            res += v[i].second.first;
            len += v[i].second.second;
        }
    }
    return res;
}

int main()
{
    int costs[] = {10, 3, 2, 8, 4};
    string words[] = {"program", "queue", "stack", "linked_list", "update"};

    fun(words, costs, 5);
}