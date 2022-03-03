#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
    node(int data)
    {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void preorder(node *root)
{
    // root left right
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int height(node *root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
void levelorder(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *cur = q.front();
        q.pop();
        cout << cur->val << " ";
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
}

bool isBST(node *root)
{
    static node *prev = NULL;

    // traverse the tree in inorder fashion
    // and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
            return false;

        // Allows only distinct valued nodes
        if (prev != NULL &&
            root->val <= prev->val)
            return false;

        prev = root;

        return isBST(root->right);
    }

    return true;
}

node *insert_bst(node *root, int element)
{
    if (root == nullptr)
    {
        node *cur = new node(element);
        return cur;
    }
    if (root->val > element)
    {
        root->left = insert_bst(root->left, element);
    }
    else
    {
        root->right = insert_bst(root->right, element);
    }
    return root;
}
bool isIdentical(node *first, node *second)
{
    if (first == nullptr and second == nullptr)
        return 1;
    if (first == nullptr || second == nullptr)
        return 0;
    if (first->val == second->val)
    {
        bool a = isIdentical(first->left, second->left);
        bool b = isIdentical(first->right, second->right);
        return a & b;
    }
    return false;
}
bool ancestors(node *root, int val)
{
    if (!root)
        return 0;
    if (root->val == val)
        return 1;
    if (ancestors(root->left, val) || ancestors(root->right, val))
    {
        cout << root->val << " ";
        return 1;
    }
    return 0;
}
int main()
{
    node *root = new node(6);
    root->left = new node(3);
    root->right = new node(8);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->right->left = new node(7);
    root->right->right = new node(10);
    // insert_bst(root,17);
    // cout << "preorder ";
    /*   preorder(root);
       cout << endl;
       cout << " Postorder ";
       postorder(root);
       cout << endl;
       cout << " Inorder ";
       inorder(root);
       cout << endl;
       cout << " height " << height(root) << endl;
       cout << " Level Order ";
       levelorder(root);
       cout << endl;
       cout << " isIdentical " << isIdentical(root, root) << endl;
       cout << " isIdentical " << isIdentical(root, root->left) << endl;
       cout << " ancestor "
            << "NO\0YES" + 3 * ancestors(root, 10) << endl;
       cout << " ancestor "
            << "NO\0YES" + 3 * ancestors(root, 15) << endl;
   */
    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";

    return 0;
}