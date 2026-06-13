#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<string> ans;

void backtrack(string &digits, int idx, string curr, unordered_map<char, string> &mp) {
    if(idx == digits.size()) {
        ans.push_back(curr);
    }

    string letters = mp[digits[idx]];
    for(char c: letters) {
        backtrack(digits, idx+1, curr+c, mp);
    }
}

vector<string> combinations(string digits) {
    if(digits.empty()) return {};

     unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

    backtrack(digits, 0, "", mp);
    return ans;
}

int main() {
    string digits;

    cout << "Enter digits: ";
    cin >> digits;

    vector<string> ans = combinations(digits);

    cout << "Letter combinations of phone number are: ";
    for(string s: ans) {
        cout << s << " ";
    }
    return 0;
}