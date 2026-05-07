#include<iostream>
#include<unordered_map>
using namespace std;

int longestSub(string s) {
    unordered_map<char, int> mp;
    int left=0, right=0, maxL=0;

    for(right=0; right<s.length(); right++) {
        mp[s[right]]++;

        while(mp[s[right]] > 1) {
            mp[s[left]]--;
            left++;
        }
        maxL = max(maxL, right-left+1);
    }
    return maxL;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int ans = longestSub(s);
    cout << "Longest substring is of length: " << ans << endl;

    return 0;
}