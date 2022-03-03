// This function clones a given linked list
// in O(1) space
// Create the copy of node 1 and insert it between node 1 & node 2 in the original Linked List,
// create a copy of 2 and insert it between 2 & 3.
// Continue in this fashion, add the copy of N after the Nth node
#include <bits/stdc++.h>
using namespace std;

// Structure of linked list Node
struct Node
{
    int data;
    Node *next, *random;
    Node(int x)
    {
        data = x;
        next = random = NULL;
    }
};

// Utility function to print the list.
void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}
Node *clone(Node *start)
{
    Node *curr = start, *temp;

    // insert additional node after
    // every node of original list
    while (curr)
    {
        temp = curr->next;

        // Inserting node
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    curr = start;

    // adjust the random pointers of the
    // newly added nodes
    while (curr)
    {
        if (curr->next)
            curr->next->random = curr->random ? curr->random->next : curr->random;

        // move to the next newly added node by
        // skipping an original node
        curr = curr->next ? curr->next->next : curr->next;
    }

    Node *original = start, *copy = start->next;

    // save the start of copied linked list
    temp = copy;

    // now separate the original list and copied list
    while (original && copy)
    {
        original->next =
            original->next ? original->next->next : original->next;

        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return temp;
}