#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "\nEnter elements\n";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int largest = INT_MIN;
    int second = INT_MIN;

    for(int i=0; i<n; i++) {
        if(arr[i] > largest) {
            second = largest;
            largest = arr[i];
        }
        else if(arr[i] > second && arr[i]!=largest) {
            second = arr[i];
        }
    }

    cout << "Second Largest element is: " << second << endl;

    return 0;
}