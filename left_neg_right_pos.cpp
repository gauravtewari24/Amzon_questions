#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {3, 4, -5, -2, 10};
    int n = v.size();
    int prev;
    stack<int> pos;
    stack<int> neg;

    for (int i = 0; i < n; i++)
    {

        if (v[i] < 0)
        {
            neg.push(v[i]);
            if (pos.empty())
                continue;
        }
        else
        {
            pos.push(v[i]);
            continue;
        }

        while (!neg.empty() && !pos.empty())
        {
            if (abs(neg.top()) >= pos.top())
            {
                pos.pop();
            }
            else
            {
                neg.pop();
            }
        }
    }
    // cout << "HO";
    vector<int> res;
    while (!pos.empty())
    {
        res.push_back(pos.top());
        pos.pop();
    }
    // cout << "HO";
    reverse(res.begin(), res.end());
    while (!neg.empty())
    {
        res.insert(res.begin(), neg.top());
        neg.pop();
    }
    // cout << "HO";
    for (int i : res)
    {
        cout << i << " ";
    }
}