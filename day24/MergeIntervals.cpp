#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> nums) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    int start=nums[0][0], end=nums[0][1];

    for(int i=1; i<nums.size(); i++) {
        if(nums[i][0] <= end) {
            end = max(end, nums[i][1]);
        }
        else {
            ans.push_back({start, end});
            start = nums[i][0];
            end = nums[i][1];
        }
    }
    ans.push_back({start, end});
    return ans;
}

int main() {
    vector<vector<int>> intervals={{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> merged = mergeIntervals(intervals);

    cout << "Merged intervals:\n";
    for(int i=0; i<intervals.size(); i++) {
        for(int j=0; j<intervals[0].size(); j++) {
            cout << merged[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}