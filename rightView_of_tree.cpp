#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void level_rightview(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            Node *temp = q.front();
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
void dfs_rightview(Node *root, int level, int &maxi) // level=1..maxi=0
{
    if (!root)
        return;
    if (maxi < level)
    {
        maxi = level;
        cout << root->val;
    }
    dfs_rightview(root->right, level + 1, maxi);
    dfs_rightview(root->left, level + 1, maxi);
}