#include <bits/stdc++.h>
using namespace std;
int vis[100001] = {0};
vector<int> v[100001];

void dfs_topological(int x, stack<int> &st)
{
    vis[x] = 1;

    for (int ch : v[x])
    {
        if (!vis[ch])
            dfs_topological(ch, st);
    }

    st.push(x);
}
void topologicalSort(int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs_topological(i, st);
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}

int main()
{

    long long t,
        n, a = 0, m, b = 0, i, j, k, c, sum;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        // a--;
        // b--;
        v[a].push_back(b);
        // v[b].push_back(a);
    }

    topologicalSort(n);
    // cout<<v[0][1];
}