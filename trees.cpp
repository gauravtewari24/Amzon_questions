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

bool isSymmetric(node *root1, node *root2)
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
    if (root1 && root2 && root1->val == root2->val)
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);

    return false;
}

void level_rightview(node *root)
{
    if (!root)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            node *temp = q.front();
            if (n == 0)
                cout << temp->val;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            q.pop();
        }
    }
}

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

    if (isLeaf(node) || ls + rs == node->val)
        return ls + rs + node->val;
    else
        return -1;
}

void utility_fun(node *root, int level, map<int, vector<int>> &m)
{
    if (!root)
        return;

    m[level].push_back(root->val);
    utility_fun(root->left, level + 1, m);
    utility_fun(root->right, level, m);
}

void diagonolPrint(node *root)
{
    if (root == NULL)
        return;

    map<int, vector<int>> m;
    utility_fun(root, 0, m);

    for (auto temp : m)
    {
        // cout<<"HOp";
        for (int x : temp.second)
        {
            cout << x << " .";
        }
        cout << "\n";
    }
    // cout<<"HO"<<m.size();
}

// function to print the zigzag traversal
void zizagtraversal(struct node *root)
{
    // if null then return
    if (!root)
        return;

    // declare two stacks
    stack<node *> currentlevel;
    stack<node *> nextlevel;

    // push the root
    currentlevel.push(root);

    // check if stack is empty
    bool lefttoright = true;
    while (!currentlevel.empty())
    {

        // pop out of stack
        struct node *temp = currentlevel.top();
        currentlevel.pop();

        // if not null
        if (temp)
        {

            // print the data in it
            cout << temp->val << " ";

            // store data according to current
            // order.
            if (lefttoright)
            {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else
            {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }

        if (currentlevel.empty())
        {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
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