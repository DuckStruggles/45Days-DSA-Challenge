#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter parantheses string\n";
    cin >> s;

    int flag = 1;

    int n = s.size();
    stack<char> st;

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
            {
                flag = 0;
                break;
            }
            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
            {
                flag = 0;
                break;
            }
        }
    }

    if (flag == 1)
        cout << "String is valid";
    else
        cout << "String is not valid";

    return 0;
}