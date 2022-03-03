#include <bits/stdc++.h>
using namespace std;

// can do with MIN_HEAP----extract_min--HEAPIFY---max_BUILD

int main()
{
    vector<int> l = {4, 3, 2, 6};
    int size = sizeof(l) / sizeof(l[0]);

    priority_queue<int, vector<int>, greater<int>> pq(l.begin(), l.end());

    int count = 0;

    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();

        pq.push(x + y);
        count += (x + y);
    }
    cout << count;
}