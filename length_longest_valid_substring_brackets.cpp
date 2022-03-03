#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "()(()))))";

    stack<int> s;
    int maxi = 0;
    s.push(-1);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            s.push(i);
        else
        {
            if (!s.empty())
                s.pop();

            if (!s.empty())
                maxi = max(maxi, i - s.top());
            else
                s.push(i);
        }
    }
    cout << maxi;
}