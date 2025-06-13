// It determines if there exists an edge in the binary tree such that removing it
// divides the tree into two subtrees of equal size
// (i.e., each containing n/2 nodes if the total number of nodes is n).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

// utility function to create a new node
struct Node *newNode(int x)
{
    struct Node *temp = new Node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
};

int count(Node *root)
{
    if (root == NULL)
        return 0;
    return count(root->left) + count(root->right) + 1;
}

// This function returns size of tree rooted with given
// root. It also set "res" as true if there is an edge
// whose removal divides tree in two halves.
// n is size of tree
int checkRec(Node *root, int n, bool &res)
{
    // Base case
    if (root == NULL)
        return 0;

    // Compute sizes of left and right children
    int c = checkRec(root->left, n, res) + 1 +
            checkRec(root->right, n, res);

    // If required property is true for current node
    // set "res" as true
    if (c == n - c)
        res = true;

    // Return size
    return c;
}

// This function mainly uses checkRec()
bool check(Node *root)
{
    // Count total nodes in given tree
    int n = count(root);

    // Initialize result and recursively check all nodes
    bool res = false;
    checkRec(root, n, res);

    return res;
}
