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

int main()
{
    node *root = new node(6);
    root->left = new node(3);
    root->right = new node(8);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->right->left = new node(7);
    root->right->right = new node(10);
    diagonolPrint(root);

    return 0;
}