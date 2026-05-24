#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;

    for (int num : nums)
    {
        freq[num]++;
    }
    vector<vector<int>> bucket(nums.size() + 1);

    for (auto it : freq)
    {
        int i = it.first;
        int frequency = it.second;

        bucket[frequency].push_back(i);
    }
    vector<int> ans;

    for (int i = bucket.size() - 1; i >= 0; i--)
    {
        for (int num : bucket[i])
        {
            ans.push_back(num);

            if (ans.size() == k)
                return ans;
        }
    }
    return ans;
}

int main() {
    vector<int> arr={1,1,1,2,2,3};
    int k=2;
    vector<int> ans = topKFrequent(arr, k);

    cout << "Top K frequent elements are:\n";
    for(int i: ans){
        cout << i << " ";
    }

    return 0;
}