#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "\nEnter elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int K;
    cout << "Enter number of children: ";
    cin >> K;

    if(K > n) return -1;

    int minDiff = INT_MAX;

    for (int i = 0; i + K - 1 < n; i++) {
        int diff = arr[i + K - 1] - arr[i];
        minDiff = min(minDiff, diff);
    }

    cout << "Min chocolate distribution is -> " << minDiff << endl;
    return 0;
}