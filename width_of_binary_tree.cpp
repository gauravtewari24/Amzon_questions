// C++ program to check if Binary tree
// is sum tree or not
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int maxWidth(Node *root)
{
    if (root == NULL)
        return 0;

    int maxi = INT_MIN;
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        maxi = max(size, maxi);

        while (size--)
        {
            Node *cur = q.front();
            if (cur->left != NULL)
                q.push(cur->left);

            if (cur->right != NULL)
                q.push(cur->right);

            q.pop();
        }
    }
    return maxi;
}

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}
main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);

    /*   Constructed Binary tree is:
                 1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7    */
    // Function call
    cout << "Maximum width is " << maxWidth(root) << endl;
    return 0;
}