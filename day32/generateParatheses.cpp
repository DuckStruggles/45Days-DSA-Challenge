#include <iostream>
#include <vector>
using namespace std;

vector<string> ans;

void backtrack(int n, string curr, int open, int close)
{
    if (curr.size() == n * 2)
    {
        ans.push_back(curr);
        return;
    }

    if (open < n)
        backtrack(n, curr + "(", open + 1, close);
    if (close < open)
        backtrack(n, curr + ")", open, close + 1);
}

vector<string> generateParatheses(int n)
{
    backtrack(n, "", 0, 0);
    return ans;
}

int main()
{
    int n;
    cout << "Enter number of brackets you want: ";
    cin >> n;

    vector<string> ans = generateParatheses(n);

    cout << "Letter combinations of phone number are: ";
    for (string s : ans)
    {
        cout << s << " ";
    }
    return 0;
}