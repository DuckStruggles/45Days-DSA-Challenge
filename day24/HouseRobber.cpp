#include <iostream>
#include <vector>
using namespace std;

int houseRob(vector<int> nums)
{
    int prev2 = 0, prev1 = 0;

    for (int i : nums)
    {
        int curr = max(prev1, prev2 + i);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    vector<int> houses = {1, 2, 3, 1};
    int ans = houseRob(houses);

    cout << "Maximum money that can be robbed: " << ans;

    return 0;
}