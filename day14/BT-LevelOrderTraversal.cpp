#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
    public:
      int data;
      Node* left;
      Node* right;

      Node(int value) {
        data = value;
        left=NULL;
        right=NULL;
      }
};

vector<vector<int>> levelOrder(Node* root) {
    queue<Node*> q;
    vector<vector<int>> ans;

    if(root==NULL) return ans;

    q.push(root);

    while(!q.empty()) {
        int s=q.size(); //no of nodes on this level
        vector<int> lvl;

        for(int i=0; i<s; i++) {
            Node* temp = q.front();
            q.pop();

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

            lvl.push_back(temp->data);
        }
        ans.push_back(lvl);
    }
    return ans;
}

int main() {
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    vector<vector<int>> ans = levelOrder(root);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}