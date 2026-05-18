#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> anagrams(string s, string p)
{
    unordered_map<char, int> ms, mp;
    vector<int> ans;

    if (s.length() < p.length())
        return ans;

    for (char c : p)
        mp[c]++;
    int win = p.length();

    for (int i = 0; i <= s.length() - win; i++)
    {
        string sub = s.substr(i, win);
        ms.clear();

        for (char c : sub)
            ms[c]++;
        if (ms == mp)
            ans.push_back(i);
    }

    return ans;
}

int main()
{
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    vector<int> ans = anagrams(s1, s2);

    if (ans.size() >= 1)
    {
        cout << "Substring containing anagrams starting indexes are\n ";
        for (int i : ans)
            cout << i << " ";
    }
    else
    {
        cout << "No substring containing anagrams found";
    }

    return 0;
}