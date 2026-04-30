#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void moveZeroes(vector<int> &arr) {
    int idx=0;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]!=0) {
            arr[idx] = arr[i];
            idx++;
        }
    }
    for(int i=idx; i<arr.size(); i++) arr[i]=0;
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

    moveZeroes(arr);
    cout << "New array ->\n";

    for(int x: arr) cout << x << " ";

    return 0;
}