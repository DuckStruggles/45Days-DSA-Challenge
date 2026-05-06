#include<iostream>
#include<vector>
using namespace std;

int minMaxGame(vector<int> &nums)
{
    vector<int> newNums;
    while (nums.size() != 1)
    {
        int n = nums.size();

        newNums.resize(n / 2);

        for (int i = 0; i < n / 2; i++)
        {
            if (i % 2 == 0)
                newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
            else
                newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
        }
        nums = newNums;
    }
    return nums[0];
}

int main () {
    vector<int> arr = {1,3,5,2,4,8,2,2};

    cout << "ARRAY: " << endl;
    for(int x: arr) {
        cout << x << " ";
    }

    int ans = minMaxGame(arr);
    cout << "\nThe answer is: " << ans << endl;

    return 0;
}