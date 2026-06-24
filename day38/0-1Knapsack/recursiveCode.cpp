#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int W, int n) {
    if(n==0 || W==0) return 0;

    if(W >= wt[n-1]) {
        return max(val[n-1]+knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
    }
    else {
        return knapsack(wt, val, W, n-1);
    }

    return 0;
}

int main() {
    vector<int> wt={1, 3, 4, 5};
    vector<int> val={1, 4, 5, 7};
    int n=wt.size();
    int W=7;

    int ans = knapsack(wt, val, W, n);
    cout << "Ans is: " << ans;

    return 0;
}