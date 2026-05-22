#include<iostream>
#include<vector>
using namespace std;

int searchInArr(vector<int> nums, int target) {
    int low=0, high=nums.size()-1;

    while(low<=high) {
        int mid = low + (high-low)/2;

        if(nums[mid] == target) return mid;

        if(nums[low] <= nums[mid]) {
            if(nums[low] <= target && nums[mid] >= target) {
                high=mid-1;
            } else {
                low = mid+1;
            }
        }
        else {
            if(nums[high] >= target && nums[mid] < target) {
                low=mid+1;
            }
            else {
                high = mid-1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {4,5,6,7,0,1,2};
    int target;

    cout << "Enter your target: ";
    cin >> target;

    int ans=searchInArr(arr, target);

    if(ans!=-1) cout << "Element found at index: " << ans;
    else cout << "Element not found";

    return 0;
}