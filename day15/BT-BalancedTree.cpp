#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    //constructor for giving default values when 'new TreeNode(1)' is run
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

int maxDiff=0;

int helper(TreeNode *root) {
    if(root==NULL) return 0;

    int left= helper(root->left);
    int right=helper(root->right);

    maxDiff = max(maxDiff, abs(left-right));

    return 1+max(left, right);
}

bool balanced(TreeNode* root) {
    helper(root);
    return maxDiff <= 1;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

    bool ans = balanced(root);

    if(ans) cout << "Tree is balanced.";
    else cout << "Tree is not balanced.";
    return 0;
}