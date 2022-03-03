#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// Function to merge K sorted linked list.
Node *mergeKLists(Node *arr[], int K)
{
    Node *head = NULL;
    while (1)
    {
        int a = 0;
        int z;
        Node *curr;
        int min = INT_MAX;
        for (int i = 0; i < K; i++)
        {
            if (arr[i] != NULL)
            {
                a++;
                if (arr[i]->data < min)
                {
                    min = arr[i]->data;
                    z = i;
                }
            }
        }
        if (a != 0)
        {
            arr[z] = arr[z]->next;
            Node *temp = new Node(min);
            if (head == NULL)
            {
                head = temp;
                curr = temp;
            }
            else
            {
                curr->next = temp;
                curr = temp;
            }
        }
        else
        {
            return head;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    struct Node *arr[N];
    for (int j = 0; j < N; j++)
    {
        int n;
        cin >> n;
        int x;
        cin >> x;
        arr[j] = new Node(x);
        Node *curr = arr[j];
        --n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            Node *temp = new Node(x);
            curr->next = temp;
            curr = temp;
        }
    }

    Node *res = mergeKLists(arr, N);
    printList(res);

    return 0;
}
