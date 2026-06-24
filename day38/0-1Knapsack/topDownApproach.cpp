#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> t;

int knapsack(vector<int> wt, vector<int> val, int W, int n)
{
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            if (j >= wt[i-1]) {
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][W];
}

int main()
{
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int n = wt.size();
    int W = 7;

    t.resize(n + 1, vector<int>(W + 1, -1));

    int ans = knapsack(wt, val, W, n);
    cout << "Ans is: " << ans;

    return 0;
}