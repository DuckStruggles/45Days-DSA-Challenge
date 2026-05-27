#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longestSubstr(string s) {
    unordered_set<char> mp;
    int l=0, maxWin=0;

    for(int r=0; r<s.size(); r++) {
        while(mp.find(s[r]) != mp.end()) {
            mp.erase(s[l]);
            l++;
        }
        mp.insert(s[r]);
        maxWin = max(maxWin, r-l+1);
    }
    return maxWin;
}

int main() {
    string s = "xyzlmlmlmxy";
    int result=longestSubstr(s);

    cout << "Longest subtring without repeating length is: " << result;

    return 0;
}