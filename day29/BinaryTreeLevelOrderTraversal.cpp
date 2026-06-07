#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

vector<vector<int>> levelOrder(Node* root) {
    queue<Node*> q;
    vector<vector<int>> ans;

    if(root==nullptr) return ans;

    q.push(root);

    while(!q.empty()) {
        int s=q.size();
        vector<int> level;

        for(int i=0; i<s; i++) {
            Node* curr = q.front();
            q.pop();

            level.push_back(curr->val);

            if(curr->left!=nullptr) {
                q.push(curr->left);
            }
            if(curr->right!=nullptr) {
                q.push(curr->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}

int main() {
    Node* root = new Node{3, nullptr, nullptr};
    root->left = new Node{9, nullptr, nullptr};
    root->right = new Node{20, nullptr, nullptr};
    root->right->left = new Node{15, nullptr, nullptr};
    root->right->right = new Node{7, nullptr, nullptr};

    vector<vector<int>> result = levelOrder(root);

    cout << "Level order traversal: \n";
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}