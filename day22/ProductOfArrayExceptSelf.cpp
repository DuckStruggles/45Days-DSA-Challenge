#include<iostream>
#include<vector>
using namespace std;

vector<int> productArr(vector<int> nums) {
    int n=nums.size();
    vector<int> ans(n, 1);

    int prefix=1;
    for(int i=0; i<n; i++) {
        ans[i] = prefix;
        prefix = prefix*nums[i];
    }

    int suffix=1;
    for(int i=n-1; i>=0; i--) {
        ans[i]=ans[i]*suffix;
        suffix = suffix*nums[i];
    }
    return ans;
}

int main() {
    vector<int> arr={1, 2, 3, 4};
    vector<int> ans=productArr(arr);

    cout << "Product array\n";
    for(int num: ans) {
        cout << num << " ";
    }
}