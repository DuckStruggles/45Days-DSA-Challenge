#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> arr, int idx, int target) {
    if(idx == arr.size()) {
        if(target==0) return 1;
        return 0;
    }

    int plus = solve(arr, idx+1, target-arr[idx]);
    int minus = solve(arr, idx+1, target+arr[idx]);

    return plus+minus;
}

int targetSum(vector<int> arr, int target) {
    return solve(arr, 0, target);
}

int main() {
    vector<int> arr={1, 1, 1, 1, 1};
    int target=3;

    cout << "Number of ways to reach target sum is:\t" << targetSum(arr, target);
    return 0;
}