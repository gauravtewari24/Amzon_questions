// C++ program to check if Binary tree
// is sum tree or not
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
left child and right child */
struct node
{
    int data;
    node *left;
    node *right;
    /* node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    } */
};

/* Utility function to check if
the given node is leaf or not */
int isLeaf(node *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}

/* returns data if SumTree property holds for the given
    tree else return -1*/
int isSumTree(node *node)
{
    if (node == NULL)
        return 0;

    int ls; // for sum of nodes in left subtree
    int rs; // for sum of nodes in right subtree

    ls = isSumTree(node->left);
    if (ls == -1) // To stop for further traversal of tree if found not sumTree
        return -1;

    rs = isSumTree(node->right);
    if (rs == -1) // To stop for further traversal of tree if found not sumTree
        return -1;

    if (isLeaf(node) || ls + rs == node->data)
        return ls + rs + node->data;
    else
        return -1;
}

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers.
*/
node *newNode(int data)
{
    node *Node = new node;
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return Node;
}
/* Driver code */
int main()
{
    node *root = newNode(26);
    root->left = newNode(12);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    int total = isSumTree(root);
    if (total != -1 && total == 2 * (root->data))
        cout << "Tree is a Sum Tree";
    else
        cout << "Given Tree is not sum Tree";

    return 0;
}