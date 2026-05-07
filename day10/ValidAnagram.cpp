#include<iostream>
#include<unordered_map>
using namespace std;

bool validAnagram(string x, string y) {
    bool ans = true; // empty strings are valid anagrams
    unordered_map<char, int> mp;

    if(x.length() != y.length()) return false;

    for(char c: x) {
        mp[c]++;
    }
    for(char c: y) {
        mp[c]--;
        if(mp[c] < 0) return false;
    }
    return ans;
}

int main() {
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;

    cout << "Enter string 2: ";
    cin >> s2;

    if(validAnagram(s1, s2)) cout << "Yes, they are valid anagram";
    else cout << "No, they are not valid anagrams";

    return 0;
}