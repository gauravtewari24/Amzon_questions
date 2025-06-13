// K maximum sum combinations from two arrays
// Input: N = 4, K = 3, A [ ] = {1, 2, 3, 4}, B [ ] = {1, 2, 5, 6}
// Output: {10, 9, 9}
// Explanation: 11 -> (A : 4) + (B : 6)
//              10 -> (A : 4) + (B : 5)
//               9 -> (A : 3) + (B : 6)

#include <bits/stdc++.h>

using namespace std;

void ksum(vector<int> a, vector<int> b, int k)
{

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    priority_queue<pair<int, pair<int, int>>> p;
    int n = a.size();
    p.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});

    set<pair<int, int>> s;
    s.insert({n - 1, n - 1});
    for (int i = 0; i < k; i++)
    {

        pair<int, pair<int, int>> temp = p.top();
        p.pop();
        cout << temp.first << "\n";
        int x = temp.second.first;
        int y = temp.second.second;
        if (s.find({x - 1, y}) == s.end())
        {
            p.push({a[x - 1] + b[y], {x - 1, y}});
            s.insert({x - 1, y});
        }

        if (s.find({x, y - 1}) == s.end())
        {
            p.push({a[x] + b[y - 1], {x, y - 1}});
            s.insert({x, y - 1});
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ksum(a, b, k);
}