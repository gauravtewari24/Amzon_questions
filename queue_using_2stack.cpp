// C++ program to check if Binary tree
// is sum tree or not
#include <bits/stdc++.h>
using namespace std;

struct queue_self
{
    stack<int> s1, s2;

    void enqueue(int data)
    {

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int dequeue()
    {
        int x = s1.top();
        s1.pop();

        return x;
    }
};
int main()
{
    queue_self q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';

    return 0;
}