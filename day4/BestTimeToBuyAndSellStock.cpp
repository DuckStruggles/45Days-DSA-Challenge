#include <iostream>
#include <vector>
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

    int profit = 0;
    int minPrice = arr[0];

    for(int i=0; i<n; i++) {
        minPrice = min(minPrice, arr[i]);
        profit = max( (arr[i] - minPrice), profit);
    }

    cout << "Max profit is -> " << profit << endl;
    return 0;
}