// check if an array can be made non decreasing by changing only one element, if not -> false

#include <iostream>
#include <vector>
using namespace std;

bool nonDecreasing(vector<int> &arr)
{
    bool flag = true;
    int x = 0; // number of violations
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            x++;
            if (x > 1)
                return false;
        }

        if (i == 0 || arr[i - 1] <= arr[i + 1])
            arr[i] = arr[i + 1];
        else
            arr[i + 1] = arr[i];
    }
    return true;
}

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

    int ans = nonDecreasing(arr);
    cout << "Array is non decreasing: " << ((ans == 1) ? "True" : "False") << endl;

    return 0;
}