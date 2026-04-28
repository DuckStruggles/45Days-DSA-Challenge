#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, K;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "\nEnter elements\n";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Enter Kth position: ";
    cin >> K;

    vector<int> temp;

    for(int i=K+1; i<n; i++) {
        temp.push_back(arr[i]);
    }
    for(int i=0; i<=K; i++) {
        temp.push_back(arr[i]);
    }

    for(int i: temp) {
        cout << i << " ";
    }
    return 0;
}