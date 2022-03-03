#include <bits/stdc++.h>
using namespace std;

string modify(string str, int k)
{
    stack<pair<char, int>> st;
    st.push({str[0], 1});
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == st.top().first)
        {
            st.push({str[i], st.top().second + 1});
            if (st.top().second == k)
            {
                for (int i = 0; i < k; i++)
                    st.pop();
            }
        }
        else
            st.push({str[i], 1});
    }
    str = "";
    while (!st.empty())
    {
        str += st.top().first;
        st.pop();
    }
    reverse(str.begin(), str.end());

    return str;
}

int main()
{
    string s = "geeksforgeeks";
    cout << modify(s, 2);
}