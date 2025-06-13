// C++ program to check if Binary tree
// is sum tree or not
#include <bits/stdc++.h>
using namespace std;

void topKFrequent(int nums[], int n, int k)
{
    unordered_map<int, int> um;

    for (int i = 0; i < n; i++)
    {
        um[nums[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    for (auto it : um)
    {
        pq.push({it.second, it.first});
    }
    
    for (int i = 0; i < k; i++)
    {
        cout << pq.top().second << " ";
        pq.pop();
    }
}
int main()
{
    int arr[] = {1, 1, 1, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    topKFrequent(arr, n, k);
    return 0;
}