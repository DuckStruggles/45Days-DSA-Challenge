// Detect cycle in undirected graph using BFS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detect(int src, vector<vector<int>> &adj, vector<int>& vis) {
    vis[src]=1;

    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto neighbor: adj[node]) {
            if(!vis[neighbor]) {
                vis[neighbor]=1;
                q.push({neighbor, node}); 
            }
            else if(neighbor!=parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> &adj) {
    vector<int> vis(V, 0);

    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            if(detect(i, adj, vis)) return true;
        }
    }
    return false;
}

int main() {
    int V=7;
    vector<vector<int>> adj(V);

    adj[0]={1, 2};
    adj[1]={0, 3};
    adj[2]={0, 4, 6};
    adj[3]={1, 5};
    adj[4]={2, 5};
    adj[5]={3, 4};
    adj[6]={2};

    if(isCycle(V, adj)) cout << "Cycle detected\n";
    else cout << "No cycle\n";

    return 0;
}