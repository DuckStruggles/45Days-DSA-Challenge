/* Given a string S(input consisting) of ‘*’ and ‘#’. The length of the string is variable. 
The task is to find the minimum number of ‘*’ or ‘#’ to make it a valid string. 
The string is considered valid if the number of ‘*’ and ‘#’ are equal. The ‘*’ and ‘#’ can be at any position in the string.
Note : The output will be a positive or negative integer based on number of ‘*’ and ‘#’ in the input string.

(*>#): positive integer
(#>*): negative integer
(#=*): 0 */

#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int hash=0, star=0;

    for(char c: s) {
        if(c=='#') hash++;
        else if(c=='*') star++;
    }

    cout << star-hash;
    return 0;
}