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

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}
bool isSymmetric(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    // For two trees to be mirror
    //  images, the following
    //  three conditions must be true
    //  1 - Their root node's
    //  key must be same 2 - left
    //  subtree of left tree and right subtree
    //  of right tree have to be mirror images
    //  3 - right subtree of left tree and left subtree
    //  of right tree have to be mirror images
    if (root1 && root2 && root1->data == root2->data)
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);

    return false;
}
main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root, root))
        cout << "Symmetric";
    else
        cout << "Not symmetric";
    return 0;
}