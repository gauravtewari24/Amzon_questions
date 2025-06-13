#include <bits/stdc++.h>
using namespace std;

// can do with MIN_HEAP----extract_min--HEAPIFY---max_BUILD
// we have a rope lengths like [4,3,2,4] and we take 2 lowest ropes and connect them and then add
// the answer in count and now [4,5,4]. priority queue in ascending.

int main()
{
    vector<int> l = {4, 3, 2, 6};
    int size = sizeof(l) / sizeof(l[0]);

    priority_queue<int, vector<int>, greater<int>> pq(l.begin(), l.end()); // creates a min heap

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