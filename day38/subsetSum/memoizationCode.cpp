#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> t;

bool subsetSum(vector<int> arr, int sum, int curr, int n) {
    if(curr == sum) return true;
    if(n==0 || curr > sum) return false;

    if(t[n][curr]!=-1)
    return t[n][curr];

    return t[n][curr]= subsetSum(arr, sum, curr+arr[n-1], n-1) || subsetSum(arr, sum, curr, n-1);
}

int main() {
    vector<int> arr={2, 3, 7, 8, 10};
    int n=arr.size();
    int sum=11;

    t.resize(n+1, vector<int>(sum+1, -1));

    bool ans = subsetSum(arr, sum, 0, n);
    if(ans) cout << "Yes there is a subset sum";
    else cout << "No subset sum";

    return 0;
}