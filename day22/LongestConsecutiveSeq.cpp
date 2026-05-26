#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longestConsecutive(vector<int> nums) {
    unordered_set<int> mp;
    int currNum;
    int currSeq=0;
    int maxSeq=0;

    if(nums.empty()) return 0;

    for(int num: nums) mp.insert(num);

    for(int num: mp) {
        if(mp.find(num-1) == mp.end()) {
            currNum = num;
            currSeq=1;
        }
        while(mp.find(currNum+1) != mp.end()) {
            currSeq++;
            currNum++;
        }
        maxSeq=max(maxSeq, currSeq);
    }
    return maxSeq;
}

int main() {
    vector<int> nums={100, 4, 200, 1, 3, 2};
    int ans = longestConsecutive(nums);

    cout << "Longest consecutive subsequence is: " << ans;
    return 0;
}