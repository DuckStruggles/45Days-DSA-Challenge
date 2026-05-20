#include <iostream>
#include <unordered_map>
using namespace std;

bool validAnagram(string s, string t)
{
    bool flag = true;
    unordered_map<char, int> mp;

    if (s.length() != t.length())
        return false;

    for (char c : s)
    {
        mp[c]++;
    }

    for (char c : t)
    {
        mp[c]--;
        if (mp[c] < 0)
            return false;

        /* why didnt we check for mp[c]>0?
        example: s = "aab", t="abx"
           a → count = 1 (extra in s)
           b → count = 0
           x → already caught earlier as negative, since it does not exist in s
        */
    }
    return flag;
}

int main()
{
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;

    bool ans = validAnagram(s1, s2);

    cout << "The strings are anagram: " << ((ans==1)?"true":"false") << endl;

    return 0;
}