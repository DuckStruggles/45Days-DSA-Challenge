#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;

void backtrack(vector<int> &candidates, int target, vector<int> &curr, int idx, int sum)
{
    if (sum == target)
    {
        ans.push_back(curr);
        return;
    }
    if (sum > target)
        return;

    for (int i = idx; i < candidates.size(); i++)
    {
        curr.push_back(candidates[i]);
        backtrack(candidates, target, curr, i, sum + candidates[i]);
        curr.pop_back();
    }
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;
    vector<int> curr;
    backtrack(arr, target, curr, 0, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
