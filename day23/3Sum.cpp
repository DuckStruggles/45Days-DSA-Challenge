#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size(); i++) {
        if(i>0 && nums[i]==nums[i-1]) continue; //skips duplicates
        int l=i+1;
        int r=nums.size()-1;

        while(l<r) {
            int sum=nums[i]+nums[l]+nums[r];

            if(sum<0) l++;
            else if(sum>0) r--;

            else {
                ans.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;

                while(l<r && nums[l]==nums[l-1]) l++;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> result=threeSum(nums);

    for(int i=0; i<result.size(); i++) {
        cout << "Pair " << i+1 << ": ";
        for(int j=0; j<result[0].size(); j++) {
            cout << result[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}