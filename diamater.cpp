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
int height(Node *node, int &ans)
{
    if (node == NULL)
        return 0;

    int left_tree = height(node->left, ans);
    int right_tree = height(node->right, ans);

    ans = max(left_tree + right_tree + 1, ans);

    return 1 + max(left_tree, right_tree);
}
int diameter(Node *root)
{
    if (root == NULL)
        return 0;

    int ans = INT_MIN;
    height(root, ans);

    return ans;
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

    printf("Diameter is %d\n", diameter(root));

    return 0;
}