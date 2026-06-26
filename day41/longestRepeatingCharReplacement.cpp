#include<iostream>
#include<vector>
using namespace std;

    int characterReplacement(string s, int k) {
        int left=0;
        int maxFreq=0;
        int maxL=0;
        vector<int> freq(26, 0);

        for(int right=0; right<s.size(); right++) {
            freq[s[right]-'A']++;
            maxFreq = max(maxFreq, freq[s[right]-'A']);

            while((right-left+1) - maxFreq > k) { //shrink window
                freq[s[left]-'A']--;
                left++;
            }
            maxL = max(maxL, right-left+1);
        }
        return maxL;
    }

    int main() {
        string s="ABAB";
        int k=2;
        cout << "Length of the longest substring containing the same letter ->\t" << characterReplacement(s, k);
        return 0;
    }