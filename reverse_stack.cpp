#include <bits/stdc++.h>
using namespace std;

// Function to transfer elements of
// the stack s1 to the stack s2
void transfer(stack<int> &s1,
              stack<int> &s2, int n)
{
    for (int i = 0; i < n; i++)
    {

        // Store the top element
        // in a temporary variable
        int temp = s1.top();

        // Pop out of the stack
        s1.pop();

        // Push it into s2
        s2.push(temp);
    }
}

// Function to reverse a stack using another stack
void reverse_stack_by_using_extra_stack(stack<int> &s,
                                        int n)
{
    stack<int> s2;

    for (int i = 0; i < n; i++)
    {

        // Store the top element
        // of the given stack
        int x = s.top();

        // Pop that element
        // out of the stack
        s.pop();

        transfer(s, s2, n - i - 1);
        s.push(x);
        transfer(s2, s, n - i - 1);
    }
}