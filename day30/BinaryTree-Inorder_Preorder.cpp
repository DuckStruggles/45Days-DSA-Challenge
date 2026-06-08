#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
};

unordered_map<int, int> inMap;
int pre=0;

Node* build(vector<int> inorder, vector<int> preorder, int left, int right) {
    if(left>right) return nullptr;

    int rootVal=preorder[pre];
    pre++;

    Node* root=new Node{rootVal, nullptr, nullptr};

    int mid = inMap[root->val];

    root->left = build(inorder, preorder, left, mid-1);
    root->right = build(inorder, preorder, mid+1, right);

    return root;
}

Node* buildTree(vector<int> inorder, vector<int> preorder)
{
    for(int i=0; i<inorder.size(); i++) {
        inMap[inorder[i]]=i;
    }

    return build(inorder, preorder, 0, inorder.size()-1);
}

void printTree(Node* root) {
    if (!root) return;

    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main()
{
    vector<int> inorder={9, 3, 15, 20, 7};
    vector<int> preorder={3, 9, 20, 15, 7};
    Node *root = buildTree(inorder, preorder);

    printTree(root);

    return 0;
}