#include <iostream>
#include <vector>
using namespace std;

int minInArr(vector<int> nums)
{
    int low = 0, high = nums.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[high])
            high = mid;
        else //nums[mid] > nums[high] i.e. minimum element must be in 2nd half
            low = mid+1;
    }
    return nums[low];
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 1, 2};
    int ans = minInArr(arr);
    cout << "Minimum element is: " << ans;

    return 0;
}