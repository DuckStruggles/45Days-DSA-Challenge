#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % n;

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k;
    cout << "Enter value for k: ";
    cin >> k;

    rotate(arr, k);

    for(int i: arr) {
        cout << i << " ";
    }
    return 0;
}