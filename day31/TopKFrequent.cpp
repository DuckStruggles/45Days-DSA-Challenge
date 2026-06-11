#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;

    for (int num : nums)
    {
        freq[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (auto &[val, fr] : freq)
    {
        minHeap.push({fr, val});
        if (minHeap.size() > k)
            minHeap.pop();
    }
    vector<int> ans;

    while (minHeap.size() > 0)
    {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3, 3};
    int k = 3;

    vector<int> ans = topKFrequent(arr, k);

    cout << "Top K frequent elements are: ";
    for (int i : ans)
        cout << i << " ";

    return 0;
}