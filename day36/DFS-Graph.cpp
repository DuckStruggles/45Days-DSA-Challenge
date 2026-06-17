#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node]=true;
    cout << node << " ";

    for(int neigh: adj[node]) {
        if(!vis[neigh]) {
            dfs(neigh, adj, vis);
        }
    }
}

int main() {
    int n=5;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    vector<bool> vis(n, false);
    dfs(0, adj, vis);

    return 0;
}