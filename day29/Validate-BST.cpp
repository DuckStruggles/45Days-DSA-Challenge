#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
};

bool checker(Node *root, long long low, long long high)
{
    if (root == nullptr)
        return true;

    if (root->val <= low || root->val >= high)
        return false;

    return checker(root->left, low, root->val) && checker(root->right, root->val, high);
}

bool isValidBST(Node *root)
{
    return checker(root, LLONG_MIN, LLONG_MAX);
}

int main()
{
    Node *root = new Node{5, nullptr, nullptr};
    root->left = new Node{1, nullptr, nullptr};
    root->right = new Node{7, nullptr, nullptr};
    root->right->left = new Node{6, nullptr, nullptr};
    root->right->right = new Node{10, nullptr, nullptr};

    bool result = isValidBST(root);

    if(result) cout << "It is a valid Binary Search Tree.";
    else cout << "It is not a valid Binary Search Tree.";

    return 0;
}