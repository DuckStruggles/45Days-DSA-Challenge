#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> t;

int knapsack(vector<int> wt, vector<int> val, int W, int n) {
    if(n==0 || W==0) return 0;
    if(t[n][W]!=-1) return t[n][W];

    if(W >= wt[n-1]) {
        t[n][W]= max(val[n-1]+knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
    }
    else {
        t[n][W]= knapsack(wt, val, W, n-1);
    }

    return t[n][W];
}

int main() {
    vector<int> wt={1, 3, 4, 5};
    vector<int> val={1, 4, 5, 7};
    int n=wt.size();
    int W=7;

    t.resize(n+1, vector<int>(W+1, -1));

    int ans = knapsack(wt, val, W, n);
    cout << "Ans is: " << ans;

    return 0;
}