#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<vector<int>> ans;

void backtrack(vector<int> nums, int idx) {
    if(idx == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for(int i=idx; i<nums.size(); i++) {
        swap(nums[i], nums[idx]);
        backtrack(nums, idx+1);
        swap(nums[i], nums[idx]);
    }
}

vector<vector<int>> permutations(vector<int> nums) {
    backtrack(nums, 0);
    return ans;
}

int main() {
    vector<int> arr={1, 2, 3, 4};
    vector<vector<int>> ans = permutations(arr);

    cout << "Permutations of the numbers are: ";
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}