#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
};

void helper(Node* root, int k, int &cnt, int &ans) {
    if(root==nullptr) return;

    helper(root->left, k, cnt, ans);
    cnt++;
    if(cnt==k) {
        ans = root->val;
        return;
    }
    helper(root->right, k, cnt, ans);
}

int KthSmallest(Node *root, int k)
{
    int cnt=0;
    int ans;

    helper(root, k, cnt, ans);
    return ans;
}

int main()
{
    Node *root = new Node{5, nullptr, nullptr};
    root->left = new Node{1, nullptr, nullptr};
    root->right = new Node{7, nullptr, nullptr};
    root->right->left = new Node{6, nullptr, nullptr};
    root->right->right = new Node{10, nullptr, nullptr};

    int k=3;

    int result = KthSmallest(root, k);

    cout << "Kth smallest element in BST is: " << result;

    return 0;
}