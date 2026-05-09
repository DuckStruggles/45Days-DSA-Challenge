// Sliding window problem
/* Given an array of positive integers nums and a positive integer target, 
return the minimal length of a subarray whose sum is greater than or equal to target. 
If there is no such subarray, return 0 instead.*/

#include<iostream>
#include<vector>
using namespace std;

int minSubArrSum(vector<int> arr, int target) {
    int count=0;
    int left=0, right=0;
    int n=arr.size();

    int sum=0;
    int ans=INT_MAX;

    while(right<n) {
        sum += arr[right];

        while(sum>=target) {
            ans = min(ans, right-left+1);
            sum = sum - arr[left];
            left++;
        }
        right++;
    }

    if(ans==INT_MAX) return 0;
    return ans;
}

int main() {
    vector<int> nums={2,3,1,2,4,3};
    int target=7;

    cout << "Minimum subarray length = " << minSubArrSum(nums, target);
    return 0;
}