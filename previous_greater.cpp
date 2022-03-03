#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {10, 4, 2, 20, 40, 12, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    stack<int> st;
    st.push(arr[0]);
    cout << "-1 ";
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && st.top() < arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            cout << st.top() << " ";
        }
        else
            cout << "-1 ";

        st.push(arr[i]);
    }
}