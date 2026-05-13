#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    //constructor for giving default values when 'new TreeNode(1)' is run
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if(root==NULL) return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

    int ans = maxDepth(root);

    cout << "Maximum depth of Binary Tree is: " << ans << endl;
    return 0;
}