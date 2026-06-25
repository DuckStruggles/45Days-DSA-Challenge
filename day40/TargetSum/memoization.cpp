#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dp;

int solve(vector<int> arr, int idx, int target) {
    if(idx == arr.size()) {
        if(target==0) return 1;
        return 0;
    }

    if(dp[idx][target+1000]!=-1) return dp[idx][target+1000];

    int plus = solve(arr, idx+1, target-arr[idx]);
    int minus = solve(arr, idx+1, target+arr[idx]);

    return dp[idx][target+1000]=plus+minus;
}

int targetSum(vector<int> arr, int target) {
    dp.resize(arr.size(), vector<int>(2000, -1)); //target range is -1000 to 1000, total 2000 combos
    return solve(arr, 0, target);
}

int main() {
    vector<int> arr={1, 1, 1, 1, 1};
    int target=3;

    cout << "Number of ways to reach target sum is:\t" << targetSum(arr, target);
    return 0;
}